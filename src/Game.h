#ifndef _GAME
#define _GAME

#include "Scarfy.h"
#include "Nebula.h"

class Game {
public:
    Game();
    void update(float deltaSeconds);
    void draw();
private:
    Scarfy scarfy;
    Nebula nebula;
};

#endif
