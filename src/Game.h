#ifndef _GAME
#define _GAME

#include "Player.h"
#include "Enemy.h"
#include "EntityPool.h"
#include "EnemySpawner.h"

class Game {
public:
    Game();
    void update(float deltaSeconds);
    void draw();
private:
    Player player;
    EntityPool<Enemy> enemies;
    EnemySpawner enemySpawner;
};

#endif
