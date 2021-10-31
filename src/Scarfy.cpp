#include "Scarfy.h"

Scarfy::Scarfy(): Entity{"textures/scarfy.png", 1, 6, 6} {}

void Scarfy::update(float deltaSeconds) {
    Entity::update(deltaSeconds);
    if (IsKeyPressed(KEY_SPACE)) {
        jump();
    }
}
