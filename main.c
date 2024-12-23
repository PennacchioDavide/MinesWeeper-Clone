#include <raylib.h>
#include <stdlib.h>
#include <raymath.h>
#include <time.h>

#define COLS 10

#define ROWS 10

const int screenWidth = 400;
const int screenHeight = 400;

const int cellWidth = screenWidth / COLS;
const int cellHeight= screenHeight / ROWS;

typedef struct Cell {
    int i;
    int j;
}Cell;

Cell grid[ROWS][COLS];

int main() {

    srand(time(0));

    InitWindow(screenWidth, screenHeight, "basic window"); // Window Initialisation

    for (int i = 0; i < COLS; i++) {
        for (int j = 0; j < ROWS; j++) {
            grid[i][j].i = i;
            grid[i][j].j = j;
        }   
    }

    while (!WindowShouldClose()) { // Game Loop

        BeginDrawing();

            ClearBackground(RAYWHITE); // Background Color

            for (int i = 0; i < COLS; i++) {
                for (int j = 0; j < ROWS; j++) {
                    CellDraw(grid[i][j]);
                }   
            }

        EndDrawing();
    }

    CloseWindow(); // WIndow Closing

    return 0;
}

void CellDraw(Cell cell) {
    DrawRectangleLines(cell.i * cellWidth, cell.j * cellHeight, cellWidth, cellHeight, BLACK);
}