#include "ScrollingBackground.h"
#include "TextureManager.h"

constexpr int farBuildingsScrollSpeed = -25; // pixels per second
constexpr int backBuildingsScrollSpeed = -50; // pixels per second
constexpr int foregroundScrollSpeed = -100; // pixels per second
constexpr float textureScale = 2.0;

ScrollingBackground::ScrollingBackground():
    farBuildings{textureManager.loadAndGetTexture("textures/far-buildings.png")},
    backBuildings{textureManager.loadAndGetTexture("textures/back-buildings.png")},
    foreground{textureManager.loadAndGetTexture("textures/foreground.png")},
    farBuildingsX{},
    backBuildingsX{},
    foregroundX{} {}

void ScrollingBackground::update(float deltaSeconds) {
    updateLayerX(deltaSeconds, farBuildingsX, farBuildingsScrollSpeed, farBuildings->texture);
    updateLayerX(deltaSeconds, backBuildingsX, backBuildingsScrollSpeed, backBuildings->texture);
    updateLayerX(deltaSeconds, foregroundX, foregroundScrollSpeed, foreground->texture);
}

void ScrollingBackground::updateLayerX(float deltaSeconds, float& x, const float& scrollSpeed, const Texture2D& texture) {
    x += scrollSpeed * deltaSeconds;
    if (x <= -texture.width * textureScale) {
        x = 0;
    }
}

void ScrollingBackground::draw() const {
    drawLayer(farBuildingsX, farBuildings->texture);
    drawLayer(backBuildingsX, backBuildings->texture);
    drawLayer(foregroundX, foreground->texture);
}

void ScrollingBackground::drawLayer(const float& x, const Texture2D& texture) const {
    Vector2 position{x, 0.0};
    DrawTextureEx(texture, position, 0.0, textureScale, WHITE);
    position.x += texture.width * textureScale;
    DrawTextureEx(texture, position, 0.0, textureScale, WHITE);
    position.x += texture.width * textureScale;
    DrawTextureEx(texture, position, 0.0, textureScale, WHITE);
}
