#ifndef _SCROLLING_BACKGROUND
#define _SCROLLING_BACKGROUND

#include <memory>
#include "Entity.h"

class ScrollingBackground {
public:
    ScrollingBackground();
    void update(float deltaSeconds);
    void draw();
private:
    std::shared_ptr<Texture2DHandle> farBuildings;
    Vector2 farBuildingsPosition;
};

#endif
