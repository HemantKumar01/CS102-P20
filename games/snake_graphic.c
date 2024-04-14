#include "raylib.h"
#include <stdlib.h>

#define TILE_SIZE 20
#define MAX_SNAKE_LENGTH 100
#define INITIAL_TIMER 10000

// Direction enumeration
typedef enum
{
    UP,
    DOWN,
    LEFT,
    RIGHT
} Direction;
// Snake structure
typedef struct
{
    Vector2 position;
    Vector2 speed;
    int length;
    Vector2 tail[MAX_SNAKE_LENGTH];
    Direction direction;
} Snake;
// Food structure
typedef struct
{
    Vector2 position;
    Color color;
} Food;

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Snake Game");

    // Forming Snake
    Snake snake = {
        {(float)(screenWidth / 2), (float)(screenHeight / 2)},
        {TILE_SIZE, 0},
        1,
        {0},
        RIGHT};
    // Food for snake
    Food food = {0};
    food.position = (Vector2){(float)(GetRandomValue(0, (screenWidth / TILE_SIZE) - 1) * TILE_SIZE),
                              (float)(GetRandomValue(0, (screenHeight / TILE_SIZE) - 1) * TILE_SIZE)};
    food.color = BLACK;
    int timer = INITIAL_TIMER;
    SetTargetFPS(10);

    while (!WindowShouldClose())
    {
        // Update
        if (IsKeyPressed(KEY_UP) && snake.direction != DOWN)
            snake.direction = UP;
        else if (IsKeyPressed(KEY_DOWN) && snake.direction != UP)
            snake.direction = DOWN;
        else if (IsKeyPressed(KEY_LEFT) && snake.direction != RIGHT)
            snake.direction = LEFT;
        else if (IsKeyPressed(KEY_RIGHT) && snake.direction != LEFT)
            snake.direction = RIGHT;
        // Update snake position
        snake.position.x += snake.speed.x;
        snake.position.y += snake.speed.y;

        if (snake.position.x >= screenWidth)
            snake.position.x = 0;
        else if (snake.position.x < 0)
            snake.position.x = screenWidth - TILE_SIZE;
        if (snake.position.y >= screenHeight)
            snake.position.y = 0;
        else if (snake.position.y < 0)
            snake.position.y = screenHeight - TILE_SIZE;

        // if it eats food
        if (CheckCollisionRecs((Rectangle){snake.position.x, snake.position.y, TILE_SIZE, TILE_SIZE},
                               (Rectangle){food.position.x, food.position.y, TILE_SIZE, TILE_SIZE}))
        {
            snake.length++;
            food.position = (Vector2){(float)(GetRandomValue(0, (screenWidth / TILE_SIZE) - 1) * TILE_SIZE),
                                      (float)(GetRandomValue(0, (screenHeight / TILE_SIZE) - 1) * TILE_SIZE)};
            timer += 10; // Increase timer when food is eaten
        }
        // Move snake's tail
        for (int i = snake.length - 1; i > 0; i--)
        {
            snake.tail[i] = snake.tail[i - 1];
        }
        snake.tail[0] = snake.position;
        // Move snake's head
        switch (snake.direction)
        {
        case UP:
            snake.speed = (Vector2){0, -TILE_SIZE};
            break;
        case DOWN:
            snake.speed = (Vector2){0, TILE_SIZE};
            break;
        case LEFT:
            snake.speed = (Vector2){-TILE_SIZE, 0};
            break;
        case RIGHT:
            snake.speed = (Vector2){TILE_SIZE, 0};
            break;
        default:
            break;
        }
        // if it eats it's own body
        for (int i = 1; i < snake.length; i++)
        {
            if (CheckCollisionRecs((Rectangle){snake.position.x, snake.position.y, TILE_SIZE, TILE_SIZE},
                                   (Rectangle){snake.tail[i].x, snake.tail[i].y, TILE_SIZE, TILE_SIZE}))
            {
                snake.length = 1;
                snake.position = (Vector2){(float)(screenWidth / 2), (float)(screenHeight / 2)};
                snake.direction = RIGHT;
            }
        }
        timer--;
        // Draw
        BeginDrawing();
        ClearBackground(RAYWHITE);
        // Draw snake
        for (int i = 0; i < snake.length; i++)
        {
            DrawRectangle(snake.tail[i].x, snake.tail[i].y, TILE_SIZE, TILE_SIZE, RED);
        }
        // Draw food
        DrawRectangle(food.position.x, food.position.y, TILE_SIZE, TILE_SIZE, food.color);
        // Draw timer
        DrawText(TextFormat("Timer: %d", timer), 10, 10, 20, BLACK);
        // Check if timer runs out
        if (timer <= 0)
        {
            DrawText("Game Over", screenWidth / 2 - MeasureText("Game Over", 40) / 2, screenHeight / 2 - 20, 40, BLACK);
            EndDrawing();
            break;
        }
        EndDrawing();
    }
    // De-Initialization
    CloseWindow();
    return 0;
}