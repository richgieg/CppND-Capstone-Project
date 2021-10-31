#include "raylib.h"
#include "Game.h"

constexpr int windowWidth{1536};
constexpr int windowHeight{380};
constexpr char windowName[]{"Game"};

int main() {
    SetConfigFlags(FLAG_VSYNC_HINT);
    InitWindow(windowWidth, windowHeight, windowName);
    Game game;
    while (!WindowShouldClose()) {
        game.update(GetFrameTime());
        BeginDrawing();
        ClearBackground(WHITE);
        game.draw();
        EndDrawing();
    }
}
