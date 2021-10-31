#include "ScrollingBackground.h"
#include "TextureManager.h"

constexpr int farBuildingsScrollSpeed = -25; // pixels per second
constexpr float farBuildingsScale = 2.0;
constexpr int backBuildingsScrollSpeed = -50; // pixels per second
constexpr float backBuildingsScale = 2.0;
constexpr int foregroundScrollSpeed = -100; // pixels per second
constexpr float foregroundScale = 2.0;

ScrollingBackground::ScrollingBackground():
    farBuildings{textureManager.getTexture("textures/far-buildings.png")},
    backBuildings{textureManager.getTexture("textures/back-buildings.png")},
    foreground{textureManager.getTexture("textures/foreground.png")},
    farBuildingsX{},
    backBuildingsX{},
    foregroundX{} {}

void ScrollingBackground::update(float deltaMs) {
    farBuildingsX += farBuildingsScrollSpeed * deltaMs;
    if (farBuildingsX <= -farBuildings->texture.width * 2) {
        farBuildingsX = 0;
    }
    backBuildingsX += backBuildingsScrollSpeed * deltaMs;
    if (backBuildingsX <= -backBuildings->texture.width * 2) {
        backBuildingsX = 0;
    }
    foregroundX += foregroundScrollSpeed * deltaMs;
    if (foregroundX <= -foreground->texture.width * 2) {
        foregroundX = 0;
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
    Vector2 foregroundPosition{foregroundX, 0.0};
    DrawTextureEx(foreground->texture, foregroundPosition, 0.0, foregroundScale, WHITE);
    foregroundPosition.x += foreground->texture.width * foregroundScale;
    DrawTextureEx(foreground->texture, foregroundPosition, 0.0, foregroundScale, WHITE);
    foregroundPosition.x += foreground->texture.width * foregroundScale;
    DrawTextureEx(foreground->texture, foregroundPosition, 0.0, foregroundScale, WHITE);
}
