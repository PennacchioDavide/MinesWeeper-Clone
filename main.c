#include <raylib.h>
#include <stdlib.h>

const int screenWidth = 1080;
const int screenHeight = 720;

int main() {

    InitWindow(screenWidth, screenHeight, "basic window"); // Window Initialisation

    while (!WindowShouldClose()) { // Game Loop

        BeginDrawing();

            ClearBackground(RAYWHITE); // Background Color

        EndDrawing();
    }

    CloseWindow(); // WIndow Closing

    return 0;
}