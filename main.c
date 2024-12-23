#include <raylib.h>
#include <stdlib.h>

const int screenWidth = 1080;
const int screenHeight = 720;

int main() {

    InitWindow(screenWidth, screenHeight, "basic window");
    SetWindowTitle("Pong");
    HideCursor();

    while (!WindowShouldClose()) {

        BeginDrawing();

            ClearBackground(BLACK);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}