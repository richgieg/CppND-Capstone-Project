#include "Entity.h"

constexpr int gravityAcceleration{1'000}; // pixels per second per second
constexpr int jumpVelocity{-600}; // pixels per second
constexpr float updateTime{1.0 / 12.0}; // 12 frames per second

Entity::Entity(std::string spritesheetFile, int spritesheetRows, int spritesheetColumns, int spritesheetFrames):
    texture{LoadTexture(spritesheetFile.c_str())},
    source{0, 0, static_cast<float>(texture.width / spritesheetColumns), static_cast<float>(texture.height / spritesheetRows)},
    position{},
    velocity{},
    currentFrame{},
    isInAir{},
    runningTime{} {}

float Entity::getWidth() {
    return source.width;
}

float Entity::getHeight() {
    return source.height;
}

void Entity::setPosition(float x, float y) {
    position.x = x;
    position.y = y;
}

void Entity::update(float deltaSeconds) {
    position.y += velocity.y * deltaSeconds;
    if (position.y >= GetScreenHeight() - source.height) {
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
            runningTime = 0;
            source.x = currentFrame * source.width;
            currentFrame++;
            if (currentFrame > 5) {
                currentFrame = 0;
            }
        }
    }
}

void Entity::draw() {
    DrawTextureRec(texture, source, position, WHITE);
}

Entity::~Entity() {
    UnloadTexture(texture);
}
