
@ECHO on
gcc games/pong.c -o dist/pong -L./raylib-5.0_win64_mingw-w64/lib -lraylib -lopengl32 -lgdi32 -lwinmm
gcc games/breakout.c -o dist/breakout -L./raylib-5.0_win64_mingw-w64/lib -lraylib -lopengl32 -lgdi32 -lwinmm
gcc games/snake_graphic.c -o dist/snake_g -L./raylib-5.0_win64_mingw-w64/lib -lraylib -lopengl32 -lgdi32 -lwinmm
gcc games/tictactoe.c -o dist/tictactoe -L./raylib-5.0_win64_mingw-w64/lib -lraylib -lopengl32 -lgdi32 -lwinmm
gcc games/apple.c -o dist/apple -L./raylib-5.0_win64_mingw-w64/lib -lraylib -lopengl32 -lgdi32 -lwinmm
gcc games/snake_terminal.c -o dist/snake_t
gcc games/rock_paper.c -o dist/rockpaper
gcc games/hangman.c -o dist/hangman
pause