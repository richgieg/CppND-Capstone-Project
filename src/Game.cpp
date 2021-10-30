#include "raylib.h"
#include "Game.h"

Game::Game() {
    scarfy.setPosition(GetScreenWidth() / 2 - scarfy.getWidth() / 2, GetScreenHeight() - scarfy.getHeight());
}

void Game::update(float deltaSeconds) {
    scarfy.update(deltaSeconds);
}

void Game::draw() {
    scarfy.draw();
}
