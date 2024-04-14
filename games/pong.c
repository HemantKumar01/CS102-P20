#include "raylib.h"
#include <stdio.h>

typedef struct
{
    char gameName[30];
    int screenWidth;
    int screenHeight;
    int playerWidth;
    int playerHeight;
    int ballRadius;
    int ballXSpeed;
    int ballYSpeed;
    Color boundaryColor;
    Color playerColor;
    Color opponentColor;
    Color ballColor;
} Settings;

void createPongTable(Settings *setting);
int getOpponentPoition(Settings *setting, Rectangle ball);

int main(void)
{
    Settings setting = {"Pong Game", 1000, 700, 10, 80, 10, -200, -200, BLUE, LIME, MAROON, BLACK};
    createPongTable(&setting);
    return 0;
}

int getOpponentPoition(Settings *setting, Rectangle ball)
{
    return (ball.y - setting->playerHeight / 2);
}

void createPongTable(Settings *setting)
{
    // Initialization
    InitWindow(setting->screenWidth, setting->screenHeight, setting->gameName);

    SetTargetFPS(30); // Set our game to run at 30 frames-per-second

    Rectangle ball = {setting->screenWidth / 2, setting->screenHeight / 2, 2 * setting->ballRadius, 2 * setting->ballRadius};
    Rectangle playerRec = {20,
                           GetMousePosition().y - 40,
                           setting->playerWidth,
                           setting->playerHeight};
    Rectangle opponentRec = {(setting->screenWidth - setting->playerWidth - 20), setting->screenHeight / 2, setting->playerWidth, setting->playerHeight};

    double previousTime = GetTime(); // Previous time measure
    double currentTime = 0.0;        // Current time measure
    double updateDrawTime = 0.0;     // Update + Draw time
    double waitTime = 0.0;           // Wait time (if target fps required)
    float deltaTime = 0.0f;          // Frame time (Update + Draw + Wait time)

    float finished = false;
    float won = false;
    // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        if (ball.x < 0)
        {
            finished = true;
            won = false;
        }
        else if (ball.x > setting->screenWidth)
        {
            finished = true;
            won = true;
        }
        if (!finished)
        {
            // updating player based on mouse position
            playerRec.y = GetMousePosition().y - 40;

            // moving the ball
            ball.x += setting->ballXSpeed * deltaTime;
            ball.y += setting->ballYSpeed * deltaTime;

            // handling collision with top and bottom endpoint
            if (ball.y >= setting->screenHeight - 10 || ball.y <= 10)
            {
                setting->ballYSpeed *= -1;
            }

            // bouncing back the ball if it collides with the player or opponent
            if (CheckCollisionRecs(ball, playerRec) || CheckCollisionRecs(ball, opponentRec))
            {
                setting->ballXSpeed *= -1;
            }

            // Draw
            BeginDrawing();

            ClearBackground(RAYWHITE);

            // Setting Up Screen
            DrawRectangle(0, 0, setting->screenWidth, 10, setting->boundaryColor);
            DrawRectangle(0, setting->screenHeight - 10, setting->screenWidth, 10, setting->boundaryColor);
            DrawRectangle(setting->screenWidth / 2, 0, 10, setting->screenHeight, setting->boundaryColor);

            // Setting Player Position.
            DrawRectangle(playerRec.x, playerRec.y, playerRec.width, playerRec.height, setting->playerColor);

            DrawCircle(ball.x, ball.y, setting->ballRadius, setting->ballColor);

            // Opponent Position
            opponentRec.y = getOpponentPoition(setting, ball);
            DrawRectangle(opponentRec.x, opponentRec.y, opponentRec.width, opponentRec.height, setting->opponentColor);

            EndDrawing();

            // updating deltaTime
            currentTime = GetTime();
            updateDrawTime = currentTime - previousTime;

            waitTime = (1.0f / (float)30) - updateDrawTime;
            if (waitTime > 0.0)
            {
                WaitTime((float)waitTime);
                currentTime = GetTime();
                deltaTime = (float)(currentTime - previousTime);
            }

            previousTime = currentTime;
        }
        else
        {
            BeginDrawing();

            ClearBackground(RAYWHITE);
            if (won)
            {
                DrawText("Congrats! You Won the Game", setting->screenWidth / 2, setting->screenHeight / 2, 50, LIGHTGRAY);
            }
            else
            {
                DrawText("Game Over", setting->screenWidth / 2, setting->screenHeight / 2, 50, LIGHTGRAY);
            }

            EndDrawing();
        }
    }

    // De-Initialization
    CloseWindow(); // Close window and OpenGL context
}