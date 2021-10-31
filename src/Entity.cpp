#include "Entity.h"

constexpr int gravityAcceleration{1'000}; // pixels per second per second
constexpr int jumpVelocity{-600}; // pixels per second
constexpr float updateTime{1.0 / 12.0}; // 12 frames per second

Entity::Entity(std::string spritesheetFile, int rowsInSpritesheet, int columnsInSpritesheet, int framesInSpritesheet):
    texture{LoadTexture(spritesheetFile.c_str())},
    source{0, 0, static_cast<float>(texture.width / columnsInSpritesheet), static_cast<float>(texture.height / rowsInSpritesheet)},
    position{0, GetScreenHeight() - source.height},
    velocity{},
    framesInSpritesheet{framesInSpritesheet},
    currentFrame{},
    isInAir{},
    runningTime{} {}

Entity::~Entity() {
    UnloadTexture(texture);
}

void Entity::update(float deltaSeconds) {
    position.x += velocity.x * deltaSeconds;
    position.y += velocity.y * deltaSeconds;
    if (position.y >= GetScreenHeight() - source.height) {
        position.y = GetScreenHeight() - source.height;
        velocity.y = 0;
        isInAir = false;
    } else {
        velocity.y += gravityAcceleration * deltaSeconds;
        isInAir = true;
    }
    if (IsKeyPressed(KEY_SPACE) && !isInAir) {
        velocity.y += jumpVelocity;
    }
    if (!isInAir) {
        runningTime += deltaSeconds;
        if (runningTime >= updateTime) {
            runningTime = runningTime - updateTime;
            source.x = currentFrame * source.width;
            currentFrame++;
            if (currentFrame >= framesInSpritesheet) {
                currentFrame = 0;
            }
        }
    }
}

void Entity::draw() {
    DrawTextureRec(texture, source, position, WHITE);
}
