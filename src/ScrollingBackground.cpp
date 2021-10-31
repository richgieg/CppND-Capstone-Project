#include "ScrollingBackground.h"

ScrollingBackground::ScrollingBackground():
    backBuildings{"textures/far-buildings.png", 1, 1, 1}
{
    backBuildings.setActive(true);
}

void ScrollingBackground::update(float deltaMs) {
    backBuildings.update(deltaMs);
}

void ScrollingBackground::draw() {
    backBuildings.draw();
}
