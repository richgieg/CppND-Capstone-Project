#include <algorithm>
#include "EnemySpawner.h"

constexpr float spawnSeconds{5};

EnemySpawner::EnemySpawner(EntityPool<Enemy> *enemies):
    enemies{enemies},
    secondsSinceLastSpawn{} {}

void EnemySpawner::update(float deltaSeconds) {
    secondsSinceLastSpawn += deltaSeconds;
    if (secondsSinceLastSpawn >= spawnSeconds) {
        secondsSinceLastSpawn = 0;
        auto enemyIterator = std::find_if(enemies->begin(), enemies->end(), [](Enemy& enemy) {
            return enemy.getX() >= GetScreenWidth();
        });
        if (enemyIterator != enemies->end()) {
            (*enemyIterator).setVelocityX(-1000);
        }
    }
}
