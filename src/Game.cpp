#include "raylib.h"
#include "Game.h"
#include "TextureManager.h"

constexpr int enemyPoolSize{5};

Game::Game(): enemies{enemyPoolSize}, enemySpawner{&enemies} {}

void Game::update(float deltaSeconds) {
    player.update(deltaSeconds);
    enemies.update(deltaSeconds);
    enemySpawner.update(deltaSeconds);
}

void Game::draw() {
    player.draw();
    enemies.draw();
}
