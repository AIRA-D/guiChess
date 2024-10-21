#include "game.h"
#include "board.h"

Game* Game::instance = nullptr;

Game::Game(): board(new Board()) {}

Game::~Game() {}

Game* Game::getInstance()
{
    if (instance == nullptr) {
        instance = new Game();
    }
    return instance;
}



