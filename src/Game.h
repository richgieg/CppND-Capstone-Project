#ifndef _GAME
#define _GAME

#include "Entity.h"

class Game {
public:
    Game();
    void update(float deltaSeconds);
    void draw();
private:
    Entity entity;
};

#endif
