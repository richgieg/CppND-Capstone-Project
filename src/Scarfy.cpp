#include "Scarfy.h"

Scarfy::Scarfy(): texture{}, rectangle{}, position{}, velocity{} {
    texture = LoadTexture("textures/scarfy.png");
}

Scarfy::~Scarfy() {
    UnloadTexture(texture);
}
