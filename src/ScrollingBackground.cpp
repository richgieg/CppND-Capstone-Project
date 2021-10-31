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

void drawLayer(const float& x, const Texture2D& texture) {
    Vector2 position{x, 0.0};
    DrawTextureEx(texture, position, 0.0, textureScale, WHITE);
    position.x += texture.width * textureScale;
    DrawTextureEx(texture, position, 0.0, textureScale, WHITE);
    position.x += texture.width * textureScale;
    DrawTextureEx(texture, position, 0.0, textureScale, WHITE);
}

void ScrollingBackground::draw() {
    drawLayer(farBuildingsX, farBuildings->texture);
    drawLayer(backBuildingsX, backBuildings->texture);
    drawLayer(foregroundX, foreground->texture);
}
