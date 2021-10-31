#include <algorithm>
#include "EnemySpawner.h"

constexpr float spawnSeconds{5};
constexpr int initialEnemiesPerSpawn{1};

EnemySpawner::EnemySpawner(EntityPool<Enemy> *enemies):
    enemies{enemies},
    secondsSinceLastSpawn{},
    enemiesPerSpawn{initialEnemiesPerSpawn} {}

void EnemySpawner::update(float deltaSeconds) {
    secondsSinceLastSpawn += deltaSeconds;
    if (secondsSinceLastSpawn >= spawnSeconds) {
        secondsSinceLastSpawn = 0;
        for (int i = 0; i < enemiesPerSpawn; i++) {
            auto enemyIterator = std::find_if(enemies->begin(), enemies->end(), [](Enemy& enemy) {
                return enemy.getX() >= GetScreenWidth();
            });
            if (enemyIterator != enemies->end()) {
                enemyIterator->setVelocityX(-1000);
            }
        }
    }
}
