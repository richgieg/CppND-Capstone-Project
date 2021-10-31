#include "ScrollingBackground.h"
#include "TextureManager.h"

constexpr int farBuildingsScrollSpeed = -25; // pixels per second
constexpr float farBuildingsScale = 2.0;
constexpr int backBuildingsScrollSpeed = -50; // pixels per second
constexpr float backBuildingsScale = 2.0;

ScrollingBackground::ScrollingBackground():
    farBuildings{textureManager.getTexture("textures/far-buildings.png")},
    backBuildings{textureManager.getTexture("textures/back-buildings.png")},
    farBuildingsX{},
    backBuildingsX{} {}

void ScrollingBackground::update(float deltaMs) {
    farBuildingsX += farBuildingsScrollSpeed * deltaMs;
    if (farBuildingsX <= -farBuildings->texture.width * 2) {
        farBuildingsX = 0;
    }
    backBuildingsX += backBuildingsScrollSpeed * deltaMs;
    if (backBuildingsX <= -backBuildings->texture.width * 2) {
        backBuildingsX = 0;
    }
}

void ScrollingBackground::draw() {
    Vector2 farBuildingsPosition{farBuildingsX, 0.0};
    DrawTextureEx(farBuildings->texture, farBuildingsPosition, 0.0, farBuildingsScale, WHITE);
    farBuildingsPosition.x += farBuildings->texture.width * farBuildingsScale;
    DrawTextureEx(farBuildings->texture, farBuildingsPosition, 0.0, farBuildingsScale, WHITE);
    farBuildingsPosition.x += farBuildings->texture.width * farBuildingsScale;
    DrawTextureEx(farBuildings->texture, farBuildingsPosition, 0.0, farBuildingsScale, WHITE);

    Vector2 backBuildingsPosition{backBuildingsX, 0.0};
    DrawTextureEx(backBuildings->texture, backBuildingsPosition, 0.0, backBuildingsScale, WHITE);
    backBuildingsPosition.x += backBuildings->texture.width * backBuildingsScale;
    DrawTextureEx(backBuildings->texture, backBuildingsPosition, 0.0, backBuildingsScale, WHITE);
    backBuildingsPosition.x += backBuildings->texture.width * backBuildingsScale;
    DrawTextureEx(backBuildings->texture, backBuildingsPosition, 0.0, backBuildingsScale, WHITE);
}
