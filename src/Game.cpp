#include "Game.h"

Game::Game(int windowWidth, int windowHeight):
    windowWidth{windowWidth},
    windowHeight{windowHeight}
{
    scarfy.setPosition(windowWidth / 2 - scarfy.getWidth() / 2, windowHeight - scarfy.getHeight());
}

void Game::update(float deltaSeconds) {

}

void Game::draw() {
    scarfy.draw();
}
