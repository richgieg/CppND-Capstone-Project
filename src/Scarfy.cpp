#include "Scarfy.h"

constexpr int spritesheetWidth = 6;
// acceleration due to gravity (pixels/s)/s
constexpr int gravity{1'000};
constexpr int jumpVel{-600};
constexpr float updateTime{1.0 / 12.0}; // 12 frames per second

Scarfy::Scarfy():
    texture{LoadTexture("textures/scarfy.png")},
    source{0, 0, static_cast<float>(texture.width / spritesheetWidth), static_cast<float>(texture.height)},
    position{},
    velocity{},
    acceleration{},
    frame{},
    isInAir{},
    runningTime{} {}

float Scarfy::getWidth() {
    return source.width;
}

float Scarfy::getHeight() {
    return source.height;
}

void Scarfy::setPosition(float x, float y) {
    position.x = x;
    position.y = y;
}

void Scarfy::update(float deltaSeconds) {
    // update scarfy position
    position.y += velocity.y * deltaSeconds;
    // perform ground check
    if (position.y >= GetScreenHeight() - source.height) {
        velocity.y = 0;
        isInAir = false;
    } else {
        // rectangle is in the air
        velocity.y += gravity * deltaSeconds;
        isInAir = true;
    }
    // jump check
    if (IsKeyPressed(KEY_SPACE) && !isInAir) {
        velocity.y += jumpVel;
    }
    if (!isInAir) {
        // update running time
        runningTime += deltaSeconds;
        if (runningTime >= updateTime) {
            runningTime = 0;
            // update animation frame
            source.x = frame * source.width;
            frame++;
            if (frame > 5) {
                frame = 0;
            }
        }
    }
}

void Scarfy::draw() {
    DrawTextureRec(texture, source, position, WHITE);
}

Scarfy::~Scarfy() {
    UnloadTexture(texture);
}
