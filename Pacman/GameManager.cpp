#include "GameManager.h"
#include "map.h"
#include <conio.h>
#include <iostream>
#include <iomanip> // For std::setprecision
#include <chrono> // For time-related functions

GameManager::GameManager() {
    pacman = &Pacman::getInstance(1, 1); // Initialize Pacman at (1, 1)
    initializeMap();
    placeGhosts();

    // Initialize the PowerPellet manager
    powerPellet = new PowerPellet(timeSystem, ghosts);
}

void GameManager::initializeMap() {
    // Initialize the map with your existing map values
    map = std::vector<std::vector<char>>(MAP_HEIGHT, std::vector<char>(MAP_WIDTH));
    ::initializeMap(map);
    placeCharacterOnMap(map, pacman->getX(), pacman->getY(), '<'); // Place Pacman with new icon

    // Place Power Pellets on the map
    placeCharacterOnMap(map, 2, 2, 'o'); // Example Power Pellet at (2, 2)
    placeCharacterOnMap(map, 6, 6, 'o'); // Example Power Pellet at (6, 6)
}

void GameManager::placeGhosts() {
    // Register all ghost types
    registerGhosts();

    // Create ghosts dynamically
    ghosts.push_back(GhostFactory::getInstance().createGhost("RedGhost"));
    ghosts.push_back(GhostFactory::getInstance().createGhost("BlueGhost"));
    ghosts.push_back(GhostFactory::getInstance().createGhost("PinkGhost"));
    ghosts.push_back(GhostFactory::getInstance().createGhost("OrangeGhost"));

    // Place ghosts on the map
    placeCharacterOnMap(map, 4, 4, 'R'); // Place RedGhost at (4, 4)
    placeCharacterOnMap(map, 4, 5, 'B'); // Place BlueGhost at (4, 5)
    placeCharacterOnMap(map, 5, 4, 'P'); // Place PinkGhost at (5, 4)
    placeCharacterOnMap(map, 5, 5, 'O'); // Place OrangeGhost at (5, 5)
}

void GameManager::startGame() {
    // Start timers for ghost state transitions and power pellet mode
    timeSystem.startTimer("GhostStateSwitch");
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

            // Check if Pac-Man ate a Power Pellet
            if (pacman->isPowerModeActive()) {
                powerPellet->activate(*pacman, map);
            }

            // Update the Power Pellet effect
            powerPellet->update(*pacman);

            // Display remaining time for Power Pellet
            double remainingTime = powerPellet->getRemainingTime();
            if (remainingTime > 0) {
                std::cout << "Power Pellet Time Remaining: " << std::fixed << std::setprecision(2) << remainingTime << " seconds" << std::endl;
            }

            renderMap(map);
        }
    }
}