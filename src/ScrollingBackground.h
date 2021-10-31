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
    void updateLayerX(float deltaSeconds, float& x, const float& scrollSpeed, const Texture2D& texture);
    void drawLayer(const float& x, const Texture2D& texture);
    std::shared_ptr<Texture2DHandle> farBuildings;
    std::shared_ptr<Texture2DHandle> backBuildings;
    std::shared_ptr<Texture2DHandle> foreground;
    float farBuildingsX;
    float backBuildingsX;
    float foregroundX;
};

#endif
