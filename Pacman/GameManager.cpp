#include "GameManager.h"
#include "map.h"
#include <conio.h>
#include <iostream>

GameManager::GameManager() {
    pacman = &Pacman::getInstance(1, 1); // Initialize Pacman at (1, 1)
    initializeMap();
    placeGhosts();
}

void GameManager::initializeMap() {
    // Initialize the map with your existing map values
    map = std::vector<std::vector<char>>(MAP_HEIGHT, std::vector<char>(MAP_WIDTH));
    ::initializeMap(map);
    placeCharacterOnMap(map, pacman->getX(), pacman->getY(), '<'); // Place Pacman with new icon
}

void GameManager::placeGhosts() {
    // Register all ghost types
    registerGhosts();

    // Create ghosts dynamically
    auto redGhost = GhostFactory::getInstance().createGhost("RedGhost");
    auto blueGhost = GhostFactory::getInstance().createGhost("BlueGhost");
    auto pinkGhost = GhostFactory::getInstance().createGhost("PinkGhost");
    auto orangeGhost = GhostFactory::getInstance().createGhost("OrangeGhost");

    // Place ghosts on the map
    placeCharacterOnMap(map, 4, 4, 'R'); // Place RedGhost at (4, 4)
    placeCharacterOnMap(map, 4, 5, 'B'); // Place BlueGhost at (4, 5)
    placeCharacterOnMap(map, 5, 4, 'P'); // Place PinkGhost at (5, 4)
    placeCharacterOnMap(map, 5, 5, 'O'); // Place OrangeGhost at (5, 5)
}

void GameManager::startGame() {
    renderMap(map);
    gameLoop();
}

void GameManager::gameLoop() {
    while (true) {
        if (_kbhit()) {
            char input = _getch();
            int newX = pacman->getX(), newY = pacman->getY();

            if (input == 'w') newY--;
            else if (input == 's') newY++;
            else if (input == 'a') newX--;
            else if (input == 'd') newX++;
            else if (input == 'q') break;

            if (!pacman->move(map, newX, newY)) {
                std::cout << "Game Over!" << std::endl;
                break; // Terminate the game loop if collision occurs
            }
            renderMap(map);
        }
    }
}