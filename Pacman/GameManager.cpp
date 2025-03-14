#include "GameManager.h"
#include "map.h"
#include <conio.h>
#include <iostream>

GameManager::GameManager() : pacman(1, 1) {
    initializeMap();
    placeGhosts();
}

void GameManager::initializeMap() {
    // Initialize the map with your existing map values
    map = std::vector<std::vector<char>>(MAP_HEIGHT, std::vector<char>(MAP_WIDTH));
    ::initializeMap(map);
    placeCharacterOnMap(map, pacman.getX(), pacman.getY(), 'P'); // Place Pacman at (1, 1)
}

void GameManager::placeGhosts() {
    // Register all ghost types
    registerGhosts();

    // Create ghosts dynamically
    auto redGhost = GhostFactory::getInstance().createGhost("RedGhost");
    auto blueGhost = GhostFactory::getInstance().createGhost("BlueGhost");

    // Place ghosts on the map
    placeCharacterOnMap(map, 3, 3, 'R'); // Place RedGhost at (3, 3)
    placeCharacterOnMap(map, 4, 6, 'B'); // Place BlueGhost at (4, 6)
}

void GameManager::startGame() {
    renderMap(map);
    gameLoop();
}

void GameManager::gameLoop() {
    while (true) {
        if (_kbhit()) {
            char input = _getch();
            int newX = pacman.getX(), newY = pacman.getY();

            if (input == 'w') newY--;
            else if (input == 's') newY++;
            else if (input == 'a') newX--;
            else if (input == 'd') newX++;
            else if (input == 'q') break;

            pacman.move(map, newX, newY);
            renderMap(map);
        }
    }
}