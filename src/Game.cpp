#include <algorithm>
#include "raylib.h"
#include "Game.h"
#include "TextureManager.h"

constexpr int enemyPoolSize = 5;

Game::Game(): enemies{enemyPoolSize} {
    auto enemyIterator = std::find_if(enemies.begin(), enemies.end(), [](Enemy& enemy) {
        return enemy.getX() >= GetScreenWidth();
    });
    if (enemyIterator != enemies.end()) {
        (*enemyIterator).setVelocityX(-1000);
    }
}

void Game::update(float deltaSeconds) {
    player.update(deltaSeconds);
    enemies.update(deltaSeconds);
}

void Game::draw() {
    player.draw();
    enemies.draw();
}
