#include "raylib.h"
#include "Game.h"
#include "TextureManager.h"

constexpr int enemyPoolSize{50}; // max number of simultaneous enemies

Game::Game(): enemies{enemyPoolSize}, enemySpawner{&enemies} {}

void Game::update(float deltaSeconds) {
    scrollingBackground.update(deltaSeconds);
    player.update(deltaSeconds);
    enemies.update(deltaSeconds);
    enemySpawner.update(deltaSeconds);
}

void Game::draw() {
    scrollingBackground.draw();
    player.draw();
    enemies.draw();
}
