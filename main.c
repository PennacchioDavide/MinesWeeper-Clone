#include <raylib.h>

int main() {

    InitWindow(800, 450, "basic window"); // Window Initialisation

    SetTargetFPS(144); // Setting FPS

    while (!WindowShouldClose()) { // Game Loop

        BeginDrawing();

            ClearBackground(RAYWHITE); // Background Color

           

        EndDrawing();
    }

    CloseWindow(); // WIndow Closing

    return 0;
}
