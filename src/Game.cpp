#include <iostream>
#include <algorithm>
#include "raylib.h"
#include "Game.h"
#include "TextureManager.h"

constexpr int enemyPoolSize = 5;

Game::Game(): enemies{enemyPoolSize} {
    // auto enemiesVector = enemies.getEntities();
    // auto asdf = std::find_if(enemiesVector.begin(), enemiesVector.end(), [](Enemy& enemy) {
    //     return enemy.getX() >= GetScreenWidth();
    // });
    // if (asdf != enemiesVector.end()) {
    //     std::cout << "found\n";
    //     (*asdf).setVelocityX(-100);
    // }

    auto asdf = std::find_if(enemies.begin(), enemies.end(), [](Enemy& enemy) {
        return enemy.getX() >= GetScreenWidth();
    });
    if (asdf != enemies.end()) {
        std::cout << "found\n";
        (*asdf).setVelocityX(-100);
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
