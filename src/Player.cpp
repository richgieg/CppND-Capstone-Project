#include "Player.h"

constexpr float velocityX{500.0}; // pixels per second

Player::Player(): Entity{"textures/player.png", 1, 6, 6} {
    setX(GetScreenWidth() / 3.0 - getWidth() / 2.0);
    setActive(true);
}

void Player::update(float deltaSeconds) {
    Entity::update(deltaSeconds);
    if (IsKeyPressed(KEY_SPACE)) {
        jump();
    }
}
