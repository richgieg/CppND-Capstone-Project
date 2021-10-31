#include "raylib.h"
#include "Game.h"
#include "TextureManager.h"

constexpr int enemyPoolSize{50}; // max number of simultaneous enemies

Game::Game():
    enemies{enemyPoolSize},
    enemySpawner{&enemies},
    gameOver{} {}

void Game::update(float deltaSeconds) {
    if (!gameOver) {
        if (checkForCollision()) {
            gameOver = true;
        }
        scrollingBackground.update(deltaSeconds);
        player.update(deltaSeconds);
        enemies.update(deltaSeconds);
        enemySpawner.update(deltaSeconds);
    }
}

bool Game::checkForCollision() {
    for (auto& enemy : enemies) {
        if (enemy.getActive() && player.collidesWith(enemy)) {
            return true;
        }
    }
    return false;
}

void Game::draw() {
    scrollingBackground.draw();
    player.draw();
    enemies.draw();
    if (gameOver) {
        gameOverScreen.draw();
    }
}
