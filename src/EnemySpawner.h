#ifndef _ENEMY_SPAWNER
#define _ENEMY_SPAWNER

#include "EntityPool.h"
#include "Enemy.h"

class EnemySpawner {
public:
    EnemySpawner(EntityPool<Enemy> *enemies);
    void update(float deltaSeconds);
private:
    EntityPool<Enemy> *enemies;
    float secondsSinceLastSpawn;
    int enemiesPerSpawn;
};

#endif
