#include "Entity.h"

constexpr int gravityAcceleration{1'000}; // pixels per second per second
constexpr int defaultJumpVelocity{-600}; // pixels per second
constexpr float updateTime{1.0 / 12.0}; // 12 frames per second

Entity::Entity(std::string spritesheetFile, int rowsInSpritesheet, int columnsInSpritesheet, int framesInSpritesheet):
    texture{LoadTexture(spritesheetFile.c_str())},
    source{0, 0, static_cast<float>(texture.width / columnsInSpritesheet), static_cast<float>(texture.height / rowsInSpritesheet)},
    position{0, GetScreenHeight() - source.height},
    velocity{},
    jumpVelocity{defaultJumpVelocity},
    framesInSpritesheet{framesInSpritesheet},
    currentFrame{},
    isInAir{},
    runningTime{} {}

Entity::Entity(Entity&& other) {
    // copy members to "moved to" object
    texture = other.texture;
    source = other.source;
    position = other.position;
    velocity = other.velocity;
    jumpVelocity = other.jumpVelocity;
    framesInSpritesheet = other.framesInSpritesheet;
    currentFrame = other.currentFrame;
    isInAir = other.isInAir;
    runningTime = other.runningTime;
    // set members to default values in "moved from" object
    other.texture = {};
    other.source = {};
    other.position = {};
    other.velocity = {};
    other.jumpVelocity = {};
    other.framesInSpritesheet = {};
    other.currentFrame = {};
    other.isInAir = {};
    other.runningTime = {};
}

Entity& Entity::operator=(Entity&& other) {
    if (this == &other) return *this;
    // copy members to "moved to" object
    texture = other.texture;
    source = other.source;
    position = other.position;
    velocity = other.velocity;
    jumpVelocity = other.jumpVelocity;
    framesInSpritesheet = other.framesInSpritesheet;
    currentFrame = other.currentFrame;
    isInAir = other.isInAir;
    runningTime = other.runningTime;
    // set members to default values in "moved from" object
    other.texture = {};
    other.source = {};
    other.position = {};
    other.velocity = {};
    other.jumpVelocity = {};
    other.framesInSpritesheet = {};
    other.currentFrame = {};
    other.isInAir = {};
    other.runningTime = {};
    return *this;
}

Entity::~Entity() {
    UnloadTexture(texture);
}

void Entity::setX(float pixels) {
    position.x = pixels;
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
    DrawTextureRec(texture, source, position, WHITE);
}
