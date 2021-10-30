#include "Entity.h"

constexpr int spritesheetWidth = 6;
constexpr int gravityAcceleration{1'000}; // pixels per second per second
constexpr int jumpVelocity{-600};
constexpr float updateTime{1.0 / 12.0}; // 12 frames per second

Entity::Entity():
    texture{LoadTexture("textures/scarfy.png")},
    source{0, 0, static_cast<float>(texture.width / spritesheetWidth), static_cast<float>(texture.height)},
    position{},
    velocity{},
    frame{},
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
    // update scarfy position
    position.y += velocity.y * deltaSeconds;
    // perform ground check
    if (position.y >= GetScreenHeight() - source.height) {
        velocity.y = 0;
        isInAir = false;
    } else {
        // rectangle is in the air
        velocity.y += gravityAcceleration * deltaSeconds;
        isInAir = true;
    }
    // jump check
    if (IsKeyPressed(KEY_SPACE) && !isInAir) {
        velocity.y += jumpVelocity;
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

void Entity::draw() {
    DrawTextureRec(texture, source, position, WHITE);
}

Entity::~Entity() {
    UnloadTexture(texture);
}
