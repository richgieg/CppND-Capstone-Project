#include <iostream>
#include <algorithm>
#include "EnemySpawner.h"

constexpr float spawnSeconds{2.0};
constexpr int spawnsPerLevel{5};

EnemySpawner::EnemySpawner(EntityPool<Enemy> *enemies):
    enemies{enemies},
    secondsSinceLastSpawn{},
    spawnCounter{} {}

void EnemySpawner::update(float deltaSeconds) {
    secondsSinceLastSpawn += deltaSeconds;
    if (secondsSinceLastSpawn >= spawnSeconds) {
        secondsSinceLastSpawn = 0;
        auto asdf = (spawnCounter / 5) + 1;
        std::cout << asdf << "\n";
        for (int i = 0; i < asdf; i++) {
            auto enemyIterator = std::find_if(enemies->begin(), enemies->end(), [](Enemy& enemy) {
                return enemy.getX() >= GetScreenWidth();
            });
            if (enemyIterator != enemies->end()) {
                enemyIterator->setVelocityX(-1000);
            }
        }
        spawnCounter++;
    }
}
