#include "Enemy.h"

Enemy::Enemy(): Entity{"textures/enemy.png", 8, 8, 3} {
    setX(GetScreenWidth()); // start off screen, to the right
}

void Enemy::update(float deltaSeconds) {
    Entity::update(deltaSeconds);
    if (getX() < -getWidth()) {
        setVelocityX(0);
        setX(GetScreenWidth()); // move back off screen, to the right
    }
}
