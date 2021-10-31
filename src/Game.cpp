#include "raylib.h"
#include "Game.h"
#include "TextureManager.h"

Game::Game(): nebulas{5} {}

void Game::update(float deltaSeconds) {
    player.update(deltaSeconds);
    nebulas.update(deltaSeconds);
}

void Game::draw() {
    player.draw();
    nebulas.draw();
}
