#include "raylib.h"
#include "Game.h"

Game::Game(): nebulas{5} {}

void Game::update(float deltaSeconds) {
    scarfy.update(deltaSeconds);
    nebulas.update(deltaSeconds);
}

void Game::draw() {
    scarfy.draw();
    nebulas.draw();
}
