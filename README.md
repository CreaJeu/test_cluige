
## test_cluige

This is the project to achieve the test-driven development approach of our [cluige](https://github.com/CreaJeu/cluige) game engine.

When new features or evolutions are developed in cluige, they are tested here in test_cluige. Both these two projects are maintained up to date together. Old tests are all kept so they are always re-run for non-regression testing. Sometimes a cluige evolution forces us to fix old tests accordingly; we always do so each time it is needed.

#### BUILD

Only usual C here (C11 compliant so far, probably even C99 as long as we don't use threads). Just compile it your favourite way.

Test_cluige depends on cluige, which depends on PDCurses.

A **Code::Blocks project file is included** (test_cluige.cbp), for those who like it, providing straightforward compilation with link to cluige. It can be used with the Code::Blocks project files included with cluige. This is _the preferred environment of team cluige_. It assumes the following directory structure:
> - any_root_you_like
>   - **cluige**
>     - cluige.c
>     - cluige.cbp
>     - ...
>     - Nodes/
>     - ...
>   - **PDCurses**
>     - curses.h
>     - ...
>     - wincon/
>     - x11/
>   - **test_cluige**
>     - camera_test.c
>     - ...
>     - main_cluige_test.c
>     - ...
>     - test_cluige.cbp
>     - ...
>     - godot_example/
>     - ...

Build and run tested on:
- Windows 10, 11
- Linux (Debian 12)
