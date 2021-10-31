#include <iostream>
#include <algorithm>
#include "EnemySpawner.h"

constexpr float spawnSeconds{2.0};
constexpr int spawnsPerLevel{5};

EnemySpawner::EnemySpawner(EntityPool<Enemy> *enemies):
    enemies{enemies},
    secondsSinceLastSpawn{},
    totalSpawns{} {}

void EnemySpawner::update(float deltaSeconds) {
    secondsSinceLastSpawn += deltaSeconds;
    if (secondsSinceLastSpawn >= spawnSeconds) {
        secondsSinceLastSpawn = 0;
        int enemiesToSpawn = (totalSpawns / spawnsPerLevel) + 1;
        std::cout << enemiesToSpawn << "\n";
        for (int i = 0; i < enemiesToSpawn; i++) {
            auto enemyIterator = std::find_if(enemies->begin(), enemies->end(), [](Enemy& enemy) {
                return enemy.getX() >= GetScreenWidth();
            });
            if (enemyIterator != enemies->end()) {
                auto x = GetScreenWidth() + (i * enemyIterator->getWidth());
                std::cout << x << "\n";
                enemyIterator->setX(x);
                enemyIterator->setVelocityX(-1000);
            }
        }
        totalSpawns++;
    }
}
