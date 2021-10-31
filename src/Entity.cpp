#include "Entity.h"
#include "TextureManager.h"

constexpr int gravityAcceleration{1'000}; // pixels per second per second
constexpr int defaultJumpVelocity{-600}; // pixels per second
constexpr float updateTime{1.0 / 12.0}; // 12 frames per second

Entity::Entity(std::string spritesheetFile, int rowsInSpritesheet, int columnsInSpritesheet, int framesInSpritesheet):
    texturePtr{TextureManager::getInstance().getTexture(spritesheetFile)},
    source{
        0,
        0,
        static_cast<float>(texturePtr->texture.width / columnsInSpritesheet),
        static_cast<float>(texturePtr->texture.height / rowsInSpritesheet)
    },
    position{0, GetScreenHeight() - source.height},
    velocity{},
    jumpVelocity{defaultJumpVelocity},
    framesInSpritesheet{framesInSpritesheet},
    currentFrame{},
    isInAir{},
    runningTime{} {}

float Entity::getWidth() {
    return source.width;
}

float Entity::getX() const {
    return position.x;
}

void Entity::setX(float pixels) {
    position.x = pixels;
}

void Entity::setVelocityX(float pixelsPerSecond) {
    velocity.x = pixelsPerSecond;
}

void Entity::setJumpVelocity(float pixelsPerSecond) {
    jumpVelocity = pixelsPerSecond;
}

void Entity::jump() {
    if (!isInAir) {
        velocity.y += jumpVelocity;
    }
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
    DrawTextureRec(texturePtr->texture, source, position, WHITE);
}
