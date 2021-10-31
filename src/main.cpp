#include "raylib.h"
#include "Game.h"

constexpr int windowWidth{1024};
constexpr int windowHeight{380};
constexpr char windowName[]{"Hipster Hop"};

int main() {
    SetConfigFlags(FLAG_VSYNC_HINT); // match vertical refresh rate
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
