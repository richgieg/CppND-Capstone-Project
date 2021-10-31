#include "raylib.h"
#include "Game.h"

Game::Game() {
    nebula.setX(200);
    nebula.setJumpVelocity(-1200);
}

void Game::update(float deltaSeconds) {
    scarfy.update(deltaSeconds);
    nebula.update(deltaSeconds);
}

void Game::draw() {
    scarfy.draw();
    nebula.draw();
}
