#include "GameManager.h"
#include "map.h"
#include <conio.h>
#include <iostream>
#include <iomanip> // For std::setprecision

GameManager::GameManager() {
    pacman = &Pacman::getInstance(1, 1); // Initialize Pacman at (1, 1)
    initializeMap();
    placeGhosts();

    // Initialize the PowerPellet manager
    powerPellet = new PowerPellet(ghosts);
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
    // Start ghost movement threads
    for (auto& ghost : ghosts) {
        ghost->startMovement(map); // Ensure this is called for each ghost
    }

    renderMap(map);
    gameLoop();

    // Stop ghost movement threads when the game ends
    for (auto& ghost : ghosts) {
        ghost->stopMovement();
    }
}

void GameManager::gameLoop() {
    char lastInput = 'd'; // Default direction for Pac-Man (right)
    bool gameRunning = true;

    while (gameRunning) {
        // Handle player input (non-blocking)
        if (_kbhit()) {
            char input = _getch();
            if (input == 'w' || input == 'a' || input == 's' || input == 'd') {
                lastInput = input; // Update Pac-Man's direction
            } else if (input == 'q') {
                gameRunning = false; // Quit the game
            }
        }

        // Move Pac-Man in the last input direction
        int newX = pacman->getX(), newY = pacman->getY();
        if (lastInput == 'w') newY--;
        else if (lastInput == 's') newY++;
        else if (lastInput == 'a') newX--;
        else if (lastInput == 'd') newX++;

        if (!pacman->move(map, newX, newY)) {
            std::cout << "Game Over!" << std::endl;
            break; // End the game if Pac-Man collides with a ghost
        }

        // Update the map for all ghosts
        for (auto& ghost : ghosts) {
            ghost->updateState(); // Handle state transitions
        }

        // Render the map
        renderMap(map);

        // Display remaining time for Power Pellet
        if (powerPellet->isActive()) {
            double remainingTime = powerPellet->getRemainingTime();
            std::cout << "\rPower Pellet Time Remaining: " << std::fixed << std::setprecision(2) << remainingTime << " seconds" << std::flush;
        } else {
            // Clear the timer line when the Power Pellet effect ends
            std::cout << "\r" << std::string(50, ' ') << "\r" << std::flush;
        }

        // Sleep for a short duration to control the game speed
        std::this_thread::sleep_for(std::chrono::milliseconds(200)); // Adjust speed as needed
    }

    // Stop ghost movement threads when the game ends
    for (auto& ghost : ghosts) {
        ghost->stopMovement();
    }
}