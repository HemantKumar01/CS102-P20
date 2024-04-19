
# CS102 Project for 2024 spring semester
A collection of games written in C using raylib library. It includes games of all types such as classic, arcade, puzzle, and strategy games.

# Usage
1. run `compile.bat` to compile all games
2. in terminal run `gcc main.c`
3. then `./a.exe` (for powershell) or `a` (for cmd)


# Usage of Individual Games
for compiling your code (for example test.c) run
for windows
```bash
gcc games/test.c -o test -L./raylib-5.0_win64_mingw-w64/lib -lraylib -lopengl32 -lgdi32 -lwinmm
```

for linux 
```bash
sudo apt install libraylib-dev
gcc test.c -o my_game -lraylib
```

### Changes to run it on linux

1. Download linux version of raylib v5.0 https://github.com/raysan5/raylib/releases
