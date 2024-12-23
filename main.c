#include <raylib.h>
#include <stdlib.h>

const int screenWidth = 1080;
const int screenHeight = 720;

int main() {

    InitWindow(screenWidth, screenHeight, "basic window");
    SetWindowTitle("Pong");
    HideCursor();
    SetTargetFPS(60);

    Rectangle TopWhite = {10, 0, 1060, 10}; // Top White Line
    Rectangle BotWhite = {10, 710, 1060, 10}; // Bot White Line
    Rectangle LeftRed = {0, 0, 10, 720}; // Left Red Line
    Rectangle RightRed = {1070, 0, 10, 720}; // Right Red Line

    Rectangle LeftPaddle = {50, 310, 20, 120}; // Left Paddle
    Rectangle RightPaddle = {1010, 310, 20, 120}; // Right Paddle

    Vector2 circlePos = { 526.25, 351.25 }; // Circle Position
    float circleRadius = 17.5; // Circle Radius

    while (!WindowShouldClose()) {

        if (IsKeyDown(KEY_UP) && !CheckCollisionRecs(RightPaddle, TopWhite)) {
            RightPaddle.y -= 30;
        }
        if (IsKeyDown(KEY_DOWN) && !CheckCollisionRecs(RightPaddle, BotWhite)) {
            RightPaddle.y += 30;
        }
        if (IsKeyDown(KEY_W) && !CheckCollisionRecs(LeftPaddle, TopWhite)) {
            LeftPaddle.y -= 30;
        }
        if (IsKeyDown(KEY_S) && !CheckCollisionRecs(LeftPaddle, BotWhite)) {
            LeftPaddle.y += 30;
        }

        BeginDrawing();

            ClearBackground(BLACK);

            DrawRectangleRec(TopWhite, RAYWHITE);
            DrawRectangleRec(BotWhite, RAYWHITE);
            DrawRectangleRec(LeftRed, RED);
            DrawRectangleRec(RightRed, RED);
            DrawRectangleRec(RightPaddle, RAYWHITE);
            DrawRectangleRec(LeftPaddle, RAYWHITE);

            DrawCircleV(circlePos, circleRadius, RAYWHITE);

           


        EndDrawing();
    }

    CloseWindow();

    return 0;
}