#include "ScrollingBackground.h"
#include "TextureManager.h"

constexpr int farBuildingsScrollSpeed = -100; // pixels per second
constexpr float farBuildingsScale = 2.0;

ScrollingBackground::ScrollingBackground():
    farBuildings{textureManager.getTexture("textures/far-buildings.png")},
    farBuildingsX{} {}

void ScrollingBackground::update(float deltaMs) {
    farBuildingsX += farBuildingsScrollSpeed * deltaMs;
    if (farBuildingsX <= -farBuildings->texture.width * 2) {
        farBuildingsX = 0;
    }
}

void ScrollingBackground::draw() {
    Vector2 farBuildingsPosition{farBuildingsX, 0.0};
    DrawTextureEx(farBuildings->texture, farBuildingsPosition, 0.0, farBuildingsScale, WHITE);
    farBuildingsPosition.x += farBuildings->texture.width * farBuildingsScale;
    DrawTextureEx(farBuildings->texture, farBuildingsPosition, 0.0, farBuildingsScale, WHITE);
    farBuildingsPosition.x += farBuildings->texture.width * farBuildingsScale;
    DrawTextureEx(farBuildings->texture, farBuildingsPosition, 0.0, farBuildingsScale, WHITE);
}
