#include "ScrollingBackground.h"
#include "TextureManager.h"

constexpr int farBuildingsScrollSpeed = -25; // pixels per second
constexpr int backBuildingsScrollSpeed = -50; // pixels per second
constexpr int foregroundScrollSpeed = -100; // pixels per second
constexpr float textureScale = 2.0;

ScrollingBackground::ScrollingBackground():
    farBuildings{textureManager.getTexture("textures/far-buildings.png")},
    backBuildings{textureManager.getTexture("textures/back-buildings.png")},
    foreground{textureManager.getTexture("textures/foreground.png")},
    farBuildingsX{},
    backBuildingsX{},
    foregroundX{} {}

void ScrollingBackground::update(float deltaMs) {
    farBuildingsX += farBuildingsScrollSpeed * deltaMs;
    if (farBuildingsX <= -farBuildings->texture.width * textureScale) {
        farBuildingsX = 0;
    }
    backBuildingsX += backBuildingsScrollSpeed * deltaMs;
    if (backBuildingsX <= -backBuildings->texture.width * textureScale) {
        backBuildingsX = 0;
    }
    foregroundX += foregroundScrollSpeed * deltaMs;
    if (foregroundX <= -foreground->texture.width * textureScale) {
        foregroundX = 0;
    }
}

void ScrollingBackground::draw() {
    Vector2 farBuildingsPosition{farBuildingsX, 0.0};
    DrawTextureEx(farBuildings->texture, farBuildingsPosition, 0.0, textureScale, WHITE);
    farBuildingsPosition.x += farBuildings->texture.width * textureScale;
    DrawTextureEx(farBuildings->texture, farBuildingsPosition, 0.0, textureScale, WHITE);
    farBuildingsPosition.x += farBuildings->texture.width * textureScale;
    DrawTextureEx(farBuildings->texture, farBuildingsPosition, 0.0, textureScale, WHITE);
    Vector2 backBuildingsPosition{backBuildingsX, 0.0};
    DrawTextureEx(backBuildings->texture, backBuildingsPosition, 0.0, textureScale, WHITE);
    backBuildingsPosition.x += backBuildings->texture.width * textureScale;
    DrawTextureEx(backBuildings->texture, backBuildingsPosition, 0.0, textureScale, WHITE);
    backBuildingsPosition.x += backBuildings->texture.width * textureScale;
    DrawTextureEx(backBuildings->texture, backBuildingsPosition, 0.0, textureScale, WHITE);
    Vector2 foregroundPosition{foregroundX, 0.0};
    DrawTextureEx(foreground->texture, foregroundPosition, 0.0, textureScale, WHITE);
    foregroundPosition.x += foreground->texture.width * textureScale;
    DrawTextureEx(foreground->texture, foregroundPosition, 0.0, textureScale, WHITE);
    foregroundPosition.x += foreground->texture.width * textureScale;
    DrawTextureEx(foreground->texture, foregroundPosition, 0.0, textureScale, WHITE);
}
