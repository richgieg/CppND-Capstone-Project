#include <iostream>
#include "Player.h"

constexpr float velocityX = 500.0; // pixels per second

Player::Player(): Entity{"textures/scarfy.png", 1, 6, 6} {}

void Player::update(float deltaSeconds) {
    Entity::update(deltaSeconds);
    if (IsKeyPressed(KEY_SPACE)) {
        jump();
    }
}
