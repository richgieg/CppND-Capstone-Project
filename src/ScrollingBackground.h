#ifndef _SCROLLING_BACKGROUND
#define _SCROLLING_BACKGROUND

#include "Entity.h"

class ScrollingBackground {
public:
    ScrollingBackground();
    void update(float deltaSeconds);
    void draw();
private:
    Entity backBuildings;
};

#endif
