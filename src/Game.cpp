#include "raylib.h"
#include "Game.h"

Game::Game(): entity{"asdf", 1, 6, 6} {
    entity.setPosition(GetScreenWidth() / 2 - entity.getWidth() / 2, GetScreenHeight() - entity.getHeight());
}

void Game::update(float deltaSeconds) {
    entity.update(deltaSeconds);
}

void Game::draw() {
    entity.draw();
}
