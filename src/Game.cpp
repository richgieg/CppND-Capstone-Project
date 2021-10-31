#include "raylib.h"
#include "Game.h"

Game::Game(): scarfy{} {}

void Game::update(float deltaSeconds) {
    scarfy.update(deltaSeconds);
    nebula.update(deltaSeconds);
}

void Game::draw() {
    scarfy.draw();
    nebula.draw();
}
