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

    Vector2 ballPos = { 526.25, 351.25 }; // Circle Position
    float ballRadius = 17.5; // Circle Radius
    Vector2 ballSpeed = {5.0f, 4.0f}; // Ball Speed

    bool winRight = false;
    bool winLeft = false;

    while (!WindowShouldClose()) {

        // Input
        if (IsKeyDown(KEY_UP) && !CheckCollisionRecs(RightPaddle, TopWhite)) {
            RightPaddle.y -= 20;
        }
        if (IsKeyDown(KEY_DOWN) && !CheckCollisionRecs(RightPaddle, BotWhite)) {
            RightPaddle.y += 20;
        }
        if (IsKeyDown(KEY_W) && !CheckCollisionRecs(LeftPaddle, TopWhite)) {
            LeftPaddle.y -= 20;
        }
        if (IsKeyDown(KEY_S) && !CheckCollisionRecs(LeftPaddle, BotWhite)) {
            LeftPaddle.y += 20;
        }
        if ((winRight || winLeft) && IsKeyPressed(KEY_SPACE)) {
            winRight = false;
            winLeft = false;
        }

        // Ball Movement
        ballPos.x += ballSpeed.x;
        ballPos.y += ballSpeed.y;
        
        // Checking Ball Collision

        // White Walls
        if (CheckCollisionCircleRec(ballPos, ballRadius, BotWhite)) {
            ballSpeed.y *= -1;
        }
        if (CheckCollisionCircleRec(ballPos, ballRadius, TopWhite)) {
            ballSpeed.y *= -1;
        }

        // Paddles
        if (CheckCollisionCircleRec(ballPos, ballRadius, LeftPaddle)) {
            ballSpeed.x *= -1;
        }
        if (CheckCollisionCircleRec(ballPos, ballRadius, RightPaddle)) {
            ballSpeed.x *= -1;
        }

        // Red Walls
        if (CheckCollisionCircleRec(ballPos, ballRadius, LeftRed)) {
            winRight = true;
        }
        if (CheckCollisionCircleRec(ballPos, ballRadius, RightRed)) {
            winLeft = true;
        }

        // Drawing on Screen
        BeginDrawing();

            ClearBackground(BLACK);

            DrawRectangleRec(TopWhite, RAYWHITE);
            DrawRectangleRec(BotWhite, RAYWHITE);
            DrawRectangleRec(LeftRed, RED);
            DrawRectangleRec(RightRed, RED);

            if (!winRight && !winLeft) {
                DrawRectangleRec(RightPaddle, RAYWHITE);
                DrawRectangleRec(LeftPaddle, RAYWHITE);
                DrawCircleV(ballPos, ballRadius, RAYWHITE);
            }

            if (winRight) {
                DrawText("Right Side Wins", 350, 335, 50, RAYWHITE);
                DrawText("Press Space To Play Again", 400, 400, 20, RAYWHITE);
            }
            if (winLeft) {
                DrawText("Left Side Wins", 350, 335, 50, RAYWHITE);
                DrawText("Press Space To Play Again", 400, 400, 20, RAYWHITE);
            }

        EndDrawing();
    }

    CloseWindow();

    return 0;
}