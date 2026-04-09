#!/usr/bin/env bash
set -uo pipefail

usage() {
  cat <<EOF
Usage: $0 <Debug|Release> <existing-directory>
  First arg must be exactly "Debug" or "Release".
  Second arg must be a path to an existing directory.
EOF
  exit 2
}

# Need exactly 2 args
if [ "$#" -ne 2 ]; then
  echo "Error: wrong number of arguments." >&2
  usage
fi

mode="$1"
dir="$2"

# Validate mode (exact match)
if [ "$mode" != "Debug" ] && [ "$mode" != "Release" ]; then
  echo "Error: first argument must be 'Debug' or 'Release'." >&2
  usage
fi

# Validate directory exists and is a directory
if [ ! -d "$dir" ]; then
  echo "Error: '$dir' is not an existing directory." >&2
  usage
fi



#libXCurses.so is regenerated either as Debug or as Release => think to rebuild it in codeblocks if needed
pdc_so_path="../PDCurses/x11/libXCurses.so"
if ! command -v readelf >/dev/null 2>&1; then
  echo "Error: readelf not found in PATH." >&2
  exit 3
fi
if [ ! -f "$pdc_so_path" ]; then
  echo "Error: '$pdc_so_path' not found." >&2
  exit 4
fi
# detect presence of DWARF debug sections
if readelf --sections "$pdc_so_path" 2>/dev/null | grep -qE '\.debug_info|\.debug_frame|\.debug_abbrev|\.stab'; then
  has_debug=1
else
  has_debug=0
fi
if [ "$mode" = "Debug" ]; then
  if [ ! "$has_debug" -eq 1 ]; then
    echo "Error: mode is Debug but '$pdc_so_path' has no debug symbols. => rebuild it as Debug first" >&2
    exit 5
  fi
else  # mode is Release
  if [ "$has_debug" -eq 1 ]; then
    echo "Error: mode is Release but '$pdc_so_path' contains debug symbols. => rebuild it as Release first" >&2
    exit 6
  fi
fi


#copy only what needed for cluige game
cp -v $pdc_so_path $dir
cp -v ../cluige/bin/$mode/libcluige.so $dir
cp -v bin/$mode/test_cluige $dir
cp -vur assets $dir
cp -vu godot_example/project.godot $dir/godot_example/
cp -vu godot_example/assets/*.svg  $dir/godot_example/
cp -vu godot_example/godot_only/*.tscn $dir/godot_example/godot_only
cp -vu godot_example/scenes/*.tscn $dir/godot_example/

echo done

