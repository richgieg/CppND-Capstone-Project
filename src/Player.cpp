#include <iostream>
#include "Player.h"

constexpr float velocityX = 500.0; // pixels per second

Player::Player(): Entity{"textures/scarfy.png", 1, 6, 6} {}

void Player::update(float deltaSeconds) {
    Entity::update(deltaSeconds);
    if (IsKeyDown(KEY_RIGHT)) {
        setVelocityX(velocityX);
    } else if (IsKeyDown(KEY_LEFT)) {
        setVelocityX(-velocityX);
    } else {
        setVelocityX(0);
    }
    if (IsKeyPressed(KEY_SPACE)) {
        jump();
    }
}
