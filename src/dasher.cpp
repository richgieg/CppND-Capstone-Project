// https://www.raylib.com/cheatsheet/cheatsheet.html

#include "raylib.h"

int main() {
    const int windowWidth{512};
    const int windowHeight{380};

    InitWindow(windowWidth, windowHeight, "Dapper Dasher!");

    // acceleration due to gravity (px/frame/frame)
    const int gravity{1};

    // rectangle dimensions
    const int width{50};
    const int height{80};

    // is rectangle in air
    bool isInAir{};
    // jump velocity
    const int jumpVel{-22};

    int posY{windowHeight - height};
    int velocity{0};

    SetTargetFPS(60);
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(WHITE);

        // perform ground check
        if (posY >= windowHeight - height) {
            // rectangle is on the ground
            velocity = 0;
            isInAir = false;
        } else {
            // rectangle is in the air
            velocity += gravity;
            isInAir = true;
        }

        // jump check
        if (IsKeyPressed(KEY_SPACE) && !isInAir) {
            velocity += jumpVel;
        }

        // update position
        posY += velocity;

        DrawRectangle(windowWidth / 2, posY, width, height, BLUE);

        EndDrawing();
    }
    CloseWindow();
}
