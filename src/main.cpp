#include <raylib.h>


int main(int argc, char const *argv[]) {
    InitWindow(800, 800, "Touhou");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
