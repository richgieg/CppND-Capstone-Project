#ifndef _GAME
#define _GAME

#include "Scarfy.h"
#include "Nebula.h"
#include "EntityPool.h"

class Game {
public:
    Game();
    void update(float deltaSeconds);
    void draw();
private:
    Scarfy scarfy;
    EntityPool<Nebula> nebulas;
};

#endif
