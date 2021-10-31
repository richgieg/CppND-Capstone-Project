#include "EnemySpawner.h"

constexpr float asdf{123.345};

EnemySpawner::EnemySpawner(EntityPool<Enemy> *enemies):
    enemies{enemies},
    secondsSinceLastSpawn{} {}

void EnemySpawner::update(float deltaSeconds) {
    secondsSinceLastSpawn += deltaSeconds;
}
