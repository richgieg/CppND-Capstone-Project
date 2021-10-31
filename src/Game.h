// Game
//
// Implements the game.
//

#ifndef _GAME
#define _GAME

#include "ScrollingBackground.h"
#include "Player.h"
#include "Enemy.h"
#include "EntityPool.h"
#include "EnemySpawner.h"
#include "GameOverScreen.h"

class Game {
public:
    Game();
    void update(float deltaSeconds);
    void draw();
private:
    bool checkForCollision();
    ScrollingBackground scrollingBackground;
    Player player;
    EntityPool<Enemy> enemies;
    EnemySpawner enemySpawner;
    bool gameOver;
    GameOverScreen gameOverScreen;
};

#endif
