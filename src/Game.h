#ifndef _GAME
#define _GAME

#include "Player.h"
#include "Nebula.h"
#include "EntityPool.h"

class Game {
public:
    Game();
    void update(float deltaSeconds);
    void draw();
private:
    Player player;
    EntityPool<Nebula> nebulas;
};

#endif
