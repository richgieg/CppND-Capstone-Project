#include "raylib.h"
#include "Game.h"

constexpr int width{512};
constexpr int height{380};
constexpr char name[] = "Game";

int main() {
    SetConfigFlags(FLAG_VSYNC_HINT);
    InitWindow(width, height, name);
    Game game;
    while (!WindowShouldClose()) {
        game.update(GetFrameTime());
        BeginDrawing();
        ClearBackground(WHITE);
        game.draw();
        EndDrawing();
    }
    CloseWindow();
}
