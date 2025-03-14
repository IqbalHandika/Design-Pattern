#include "GameManager.h"
#include <iostream>

GameManager::GameManager() : pacman(1, 1) {
    initializeMap();
}

void GameManager::initializeMap() {
    // Initialize the map with some default values
    map = {
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
        {'#', 'P', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
        {'#', ' ', '#', '#', '#', '#', '#', '#', ' ', '#'},
        {'#', ' ', '#', ' ', ' ', ' ', ' ', '#', ' ', '#'},
        {'#', ' ', '#', ' ', '#', '#', ' ', '#', ' ', '#'},
        {'#', ' ', '#', ' ', '#', '#', ' ', '#', ' ', '#'},
        {'#', ' ', '#', ' ', ' ', ' ', ' ', '#', ' ', '#'},
        {'#', ' ', '#', '#', '#', '#', '#', '#', ' ', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
    };
}

void GameManager::startGame() {
    gameLoop();
}

void GameManager::gameLoop() {
    while (true) {
        // Example movement logic (move right)
        pacman.move(map, pacman.getX() + 1, pacman.getY());
        // Add more game logic here
    }
}