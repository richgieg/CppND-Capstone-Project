#include "Enemy.h"

Enemy::Enemy(): Entity{"textures/enemy.png", 8, 8, 3} {
    setX(GetScreenWidth()); // start off screen
}
