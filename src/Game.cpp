#include <iostream>
#include "raylib.h"
#include "Game.h"
#include "TextureManager.h"

constexpr int enemyPoolSize{50}; // max number of simultaneous enemies

Game::Game(): enemies{enemyPoolSize}, enemySpawner{&enemies} {}

void Game::update(float deltaSeconds) {
    checkForCollision();
    scrollingBackground.update(deltaSeconds);
    player.update(deltaSeconds);
    enemies.update(deltaSeconds);
    enemySpawner.update(deltaSeconds);
}

void Game::checkForCollision() {
    for (auto& enemy : enemies) {
        if (enemy.getActive() && player.collidesWith(enemy)) {
            std::cout << "collision\n";
        }
    }
}

void Game::draw() {
    scrollingBackground.draw();
    player.draw();
    enemies.draw();
}
