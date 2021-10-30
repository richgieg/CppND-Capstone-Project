#include "Scarfy.h"

Scarfy::Scarfy():
    texture{LoadTexture("textures/scarfy.png")},
    rectangle{0, 0, static_cast<float>(texture.width / 6), static_cast<float>(texture.height)},
    position{},
    velocity{} {}

void Scarfy::update(float deltaSeconds) {

}

void Scarfy::draw() {
    DrawTextureRec(texture, rectangle, position, WHITE);
}

Scarfy::~Scarfy() {
    UnloadTexture(texture);
}
