#include "raylib.h"
#include <stdio.h>
#define BOARD_SIZE 3

// Structure to represent the game board
typedef struct
{
    int cells[BOARD_SIZE][BOARD_SIZE]; // 0 for empty, 1 for X, 2 for O
    int currentPlayer;                 // 1 for X, 2 for O
    int gameOver;
} GameBoard;

// Initialize game board
void InitGameBoard(GameBoard *board)
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            board->cells[i][j] = 0;
        }
    }
    board->currentPlayer = 1; // X starts
    board->gameOver = false;
}

// Check if there is a winner
bool CheckWinner(const GameBoard *board, int player)
{
    // Check rows and columns
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        if (board->cells[i][0] == player && board->cells[i][1] == player && board->cells[i][2] == player)
            return true; // Rows
        if (board->cells[0][i] == player && board->cells[1][i] == player && board->cells[2][i] == player)
            return true; // Columns
    }

    // Check diagonals
    if (board->cells[0][0] == player && board->cells[1][1] == player && board->cells[2][2] == player)
        return true; // Diagonal
    if (board->cells[0][2] == player && board->cells[1][1] == player && board->cells[2][0] == player)
        return true; // Anti-Diagonal

    return false;
}

// Draw game board
void DrawGameBoard(const GameBoard *board)
{
    // Draw grid
    for (int i = 1; i < BOARD_SIZE; i++)
    {
        DrawLine(i * GetScreenWidth() / BOARD_SIZE, 0, i * GetScreenWidth() / BOARD_SIZE, GetScreenHeight(), DARKGRAY);
        DrawLine(0, i * GetScreenHeight() / BOARD_SIZE, GetScreenWidth(), i * GetScreenHeight() / BOARD_SIZE, DARKGRAY);
    }

    // Draw X's and O's
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if (board->cells[i][j] == 1)
            {
                DrawText("X", i * GetScreenWidth() / BOARD_SIZE + 10, j * GetScreenHeight() / BOARD_SIZE + 10, 50, BLACK);
            }
            else if (board->cells[i][j] == 2)
            {
                DrawText("O", i * GetScreenWidth() / BOARD_SIZE + 10, j * GetScreenHeight() / BOARD_SIZE + 10, 50, BLACK);
            }
        }
    }
}

int main()
{
    const int screenWidth = 600;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "Tic Tac Toe");
    SetTargetFPS(60);

    GameBoard game;
    InitGameBoard(&game);

    while (!WindowShouldClose())
    {
        // Update
        if (!game.gameOver)
        {
            // Draw
            BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawGameBoard(&game);
            EndDrawing();
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                int mouseX = GetMouseX();
                int mouseY = GetMouseY();

                // Determine cell clicked
                int cellX = mouseX / (screenWidth / BOARD_SIZE);
                int cellY = mouseY / (screenHeight / BOARD_SIZE);

                // Place the current player's mark if the cell is empty
                if (game.cells[cellX][cellY] == 0)
                {
                    game.cells[cellX][cellY] = game.currentPlayer;

                    // Check for winner
                    if (CheckWinner(&game, game.currentPlayer))
                    {
                        game.gameOver = 1;
                    }
                    else
                    {
                        // Switch player
                        game.currentPlayer = (game.currentPlayer == 1) ? 2 : 1;
                    }
                }
            }
        }
        else
        {
            BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawText(game.currentPlayer == 1 ? "Player 1 wins" : "Player 2 wins", 200, 200, 50, LIGHTGRAY);
            EndDrawing();
        }
    }

    CloseWindow();
    return 0;
}