#include "ScrollingBackground.h"
#include "TextureManager.h"

ScrollingBackground::ScrollingBackground():
    farBuildings{textureManager.getTexture("textures/far-buildings.png")},
    farBuildingsPosition{} {}

void ScrollingBackground::update(float deltaMs) {

}

void ScrollingBackground::draw() {
    DrawTextureEx(farBuildings->texture, farBuildingsPosition, 0.0, 2.0, WHITE);
}
