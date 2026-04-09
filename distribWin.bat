@echo off

set "USAGE1=--from test_cluige directory--"
set "USAGE2=distribWin.bat  Debug  path\to\destination"
set "USAGE3=distribWin.bat  Release  path\to\destination"

if "%~1"=="" (
	echo Error: arg1 missing. Allowed: Debug, Release
	echo Usage :
	echo      %USAGE1%
	echo      %USAGE2%
	echo      %USAGE3%
	exit /b 1
)

if not "%~1"=="Debug" if not "%~1"=="Release" (
	echo Error: arg1 incorrect. Allowed: Debug, Release
	echo Usage :
	echo      %USAGE1%
	echo      %USAGE2%
	echo      %USAGE3%
	exit /b 2
)

if "%~2"=="" (
	echo Error: arg2 missing. Allowed: an existing directory
	echo Usage :
	echo      %USAGE1%
	echo      %USAGE2%
	echo      %USAGE3%
	exit /b 3
)

if not exist "%~2\" (
	echo Error: arg2 incorrect. Allowed: an existing directory
	echo Usage :
	echo      %USAGE1%
	echo      %USAGE2%
	echo      %USAGE3%
	exit /b 4
)

xcopy /E /V /Y /F  ..\PDCurses\wincon\my%~1\pdcurses.dll %~2
xcopy /E /V /Y /F  ..\cluige\bin\%~1\cluige.dll          %~2
xcopy /E /V /Y /F  bin\%~1\test_cluige.exe               %~2
xcopy /E /V /Y /F /D /I  assets                          %~2\assets
xcopy /E /V /Y /F /D  godot_example\project.godot        %~2\godot_example\
xcopy /E /V /Y /F /D  godot_example\assets\*.svg         %~2\godot_example\assets\
xcopy /E /V /Y /F /D  godot_example\godot_only\*.tscn    %~2\godot_example\godot_only\
xcopy /E /V /Y /F /D  godot_example\scenes\*.tscn        %~2\godot_example\scenes\

echo ok
