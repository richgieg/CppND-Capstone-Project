#include <algorithm>
#include "EnemySpawner.h"

// How often to spawn enemies.
constexpr float spawnSeconds{2.0};
// At first each spawn creates one enemy.
// After five spawns, the number of enemies per spawn
// increases by one.
constexpr int spawnsPerLevel{5};
constexpr float enemyVelocityX{-1000}; // pixels per second

EnemySpawner::EnemySpawner(EntityPool<Enemy> *enemies):
    enemies{enemies},
    secondsSinceLastSpawn{},
    totalSpawns{} {}

void EnemySpawner::update(float deltaSeconds) {
    secondsSinceLastSpawn += deltaSeconds;
    if (secondsSinceLastSpawn >= spawnSeconds) {
        secondsSinceLastSpawn = 0;
        int enemiesPerSpawn = (totalSpawns / spawnsPerLevel) + 1;
        for (int i = 0; i < enemiesPerSpawn; i++) {
            auto enemyIterator = enemies->getFirstInactive();
            if (enemyIterator != enemies->end()) {
                auto x = GetScreenWidth() + (i * enemyIterator->getWidth());
                enemyIterator->setX(x);
                enemyIterator->setVelocityX(enemyVelocityX);
                enemyIterator->setActive(true);
            }
        }
        totalSpawns++;
    }
}
