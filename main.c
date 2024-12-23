#include <raylib.h>
#include <stdlib.h>

const int screenWidth = 1080;
const int screenHeight = 720;

int main() {

    InitWindow(screenWidth, screenHeight, "basic window");
    SetWindowTitle("Pong");
    HideCursor();
    SetTargetFPS(60);

    while (!WindowShouldClose()) {

        BeginDrawing();

            ClearBackground(BLACK);

            DrawRectangle(10, 0, 1060, 10, RAYWHITE); // Top WHite Line
            DrawRectangle(10, 710, 1060, 10, RAYWHITE); // Bot White Line
            DrawRectangle(0, 0, 10, 720, RED); // Left Red Line
            DrawRectangle(1070, 0, 10, 720, RED); // Right Red Line

            DrawCircle(526.25, 351.25, 17.5, RAYWHITE); // Ball

            DrawRectangle(50, 310, 20, 120, RAYWHITE);
            DrawRectangle(1010, 310, 20, 120, RAYWHITE);


        EndDrawing();
    }

    CloseWindow();

    return 0;
}