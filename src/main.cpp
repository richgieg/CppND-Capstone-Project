// https://www.raylib.com/cheatsheet/cheatsheet.html

#include <iostream>
#include "raylib.h"
#include "Game.h"

int main() {
    const int windowWidth{512};
    const int windowHeight{380};
    InitWindow(windowWidth, windowHeight, "Dapper Dasher!");
    Game game;
    SetTargetFPS(60);
    while (!WindowShouldClose()) {
        const float dT{GetFrameTime()};
        game.update(dT);
        BeginDrawing();
        ClearBackground(WHITE);
        game.draw();
        EndDrawing();
    }
    CloseWindow();
}


// int main() {
//     const int windowWidth{512};
//     const int windowHeight{380};

//     InitWindow(windowWidth, windowHeight, "Dapper Dasher!");

//     // acceleration due to gravity (pixels/s)/s
//     // const int gravity{1'000};

//     // nebula variables
//     Texture2D nebula = LoadTexture("textures/12_nebula_spritesheet.png");
//     Rectangle nebRec{0, 0, static_cast<float>(nebula.width / 8), static_cast<float>(nebula.height / 8)};
//     Vector2 nebPos{windowWidth, windowHeight - nebRec.height};

//     // nebula X velocity (pixels/s)
//     int nebVel{-600};

//     // scarfy variables
//     // Texture2D scarfy = LoadTexture("textures/scarfy.png");
//     // Rectangle scarfyRec{0, 0, static_cast<float>(scarfy.width / 6), static_cast<float>(scarfy.height)};
//     // Vector2 scarfyPos{windowWidth / 2 - scarfyRec.width / 2, windowHeight - scarfyRec.height};

//     // // animation frame
//     // int frame{};
//     // // amount of time before we update the animation frame
//     // const float updateTime{1.0 / 12.0};
//     // float runningTime{};

//     // // is rectangle in air
//     // bool isInAir{};
//     // // jump velocity (pixels/s)
//     // const int jumpVel{-600};

//     // int velocity{0};

//     Game game;

//     SetTargetFPS(60);
//     while (!WindowShouldClose()) {
//         // delta time
//         const float dT{GetFrameTime()};
//         game.update(dT);

//         BeginDrawing();
//         ClearBackground(WHITE);

//         // // perform ground check
//         // if (scarfyPos.y >= windowHeight - scarfyRec.height) {
//         //     // rectangle is on the ground
//         //     velocity = 0;
//         //     isInAir = false;
//         // } else {
//         //     // rectangle is in the air
//         //     velocity += gravity * dT;
//         //     isInAir = true;
//         // }

//         // // jump check
//         // if (IsKeyPressed(KEY_SPACE) && !isInAir) {
//         //     velocity += jumpVel;
//         // }

//         // update nebula position
//         nebPos.x += nebVel * dT;

//         // // update scarfy position
//         // scarfyPos.y += velocity * dT;

//         // if (!isInAir) {
//         //     // update running time
//         //     runningTime += dT;
//         //     if (runningTime >= updateTime) {
//         //         runningTime = 0;
//         //         // update animation frame
//         //         scarfyRec.x = frame * scarfyRec.width;
//         //         frame++;
//         //         if (frame > 5) {
//         //             frame = 0;
//         //         }
//         //     }
//         // }

//         // draw nebula
//         DrawTextureRec(nebula, nebRec, nebPos, WHITE);

//         game.draw();

//         EndDrawing();
//     }
//     UnloadTexture(nebula);
//     CloseWindow();
// }
