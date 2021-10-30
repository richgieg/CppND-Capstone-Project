#include "Scarfy.h"

class Game {
public:
    Game(int windowWidth, int windowHeight);
    void update(float deltaSeconds);
    void draw();
private:
    int windowWidth;
    int windowHeight;
    Scarfy scarfy;
};
