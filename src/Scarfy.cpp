#include "Scarfy.h"

constexpr int spritesheetWidth = 6;

Scarfy::Scarfy():
    texture{LoadTexture("textures/scarfy.png")},
    source{0, 0, static_cast<float>(texture.width / spritesheetWidth), static_cast<float>(texture.height)},
    position{},
    velocity{} {}

float Scarfy::getWidth() {
    return source.width;
}

float Scarfy::getHeight() {
    return source.height;
}

void Scarfy::setPosition(float x, float y) {
    position.x = x;
    position.y = y;
}

void Scarfy::update(float deltaSeconds) {

}

void Scarfy::draw() {
    DrawTextureRec(texture, source, position, WHITE);
}

Scarfy::~Scarfy() {
    UnloadTexture(texture);
}
