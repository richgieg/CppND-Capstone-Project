#include "Enemy.h"

Enemy::Enemy(): Entity{"textures/enemy.png", 8, 8, 3} {}

void Enemy::update(float deltaSeconds) {
    Entity::update(deltaSeconds);
    if (getX() < -getWidth()) {
        setActive(false);
    }
}
