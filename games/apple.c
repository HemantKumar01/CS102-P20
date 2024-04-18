#include "raylib.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 450
#define GRAVITY 0.5f
#define APPLE_RADIUS 20
#define BASKET_WIDTH 100
#define BASKET_HEIGHT 50
#define BASKET_SPEED 5

typedef struct
{
    Vector2 position;
    Vector2 velocity;
    Color color;
    bool active;
} Apple;

typedef struct
{
    Vector2 position;
    Color color;
} Basket;

int main()
{
    // Initialization
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Apple Fall Game");
    SetTargetFPS(60);

    Apple apple = {0};
    Basket basket = {0};

    apple.position = (Vector2){GetRandomValue(APPLE_RADIUS, SCREEN_WIDTH - APPLE_RADIUS), 0};
    apple.velocity = (Vector2){0, 3};
    apple.color = RED;
    apple.active = true;

    basket.position = (Vector2){SCREEN_WIDTH / 2 - BASKET_WIDTH / 2, SCREEN_HEIGHT - BASKET_HEIGHT};
    basket.color = BLUE;

    // Main game loop
    while (!WindowShouldClose())
    {
        // Update
        if (IsKeyDown(KEY_LEFT))
        {
            basket.position.x -= BASKET_SPEED;
        }
        if (IsKeyDown(KEY_RIGHT))
        {
            basket.position.x += BASKET_SPEED;
        }

        if (apple.active)
        {
            apple.position.y += apple.velocity.y;
            apple.velocity.y += GRAVITY;

            // Check collision with basket
            if ((apple.position.x > basket.position.x) &&
                (apple.position.x < basket.position.x + BASKET_WIDTH) &&
                (apple.position.y + APPLE_RADIUS > basket.position.y))
            {
                apple.active = false;
            }

            // Reset apple if it goes out of screen
            if (apple.position.y > SCREEN_HEIGHT + APPLE_RADIUS)
            {
                apple.position = (Vector2){GetRandomValue(APPLE_RADIUS, SCREEN_WIDTH - APPLE_RADIUS), 0};
                apple.velocity = (Vector2){0, 3};
            }
        }

        // Ensure basket stays within the screen boundaries
        if (basket.position.x < 0)
        {
            basket.position.x = 0;
        }
        if (basket.position.x > SCREEN_WIDTH - BASKET_WIDTH)
        {
            basket.position.x = SCREEN_WIDTH - BASKET_WIDTH;
        }

        // Draw
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Draw basket
        DrawRectangle(basket.position.x, basket.position.y, BASKET_WIDTH, BASKET_HEIGHT, basket.color);

        // Draw apple
        if (apple.active)
            DrawCircleV(apple.position, APPLE_RADIUS, apple.color);
        else
        {
            DrawText("You caught the apple!", SCREEN_WIDTH / 2 - 100, SCREEN_HEIGHT / 2, 20, BLACK);
        }
        EndDrawing();
    }

    // De-Initialization
    CloseWindow();

    return 0;
}