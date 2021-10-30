#ifndef _GAME
#define _GAME

#include "Scarfy.h"

class Game {
public:
    Game();
    void update(float deltaSeconds);
    void draw();
private:
    Scarfy scarfy;
};

#endif
