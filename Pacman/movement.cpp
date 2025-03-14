#include "movement.h"
#include "map.h"
#include <iostream> // Add this include for std::cout and std::endl

// Function to check for collisions with ghosts
bool checkCollisionWithGhost(const std::vector<std::vector<char>>& map, int pacmanX, int pacmanY) {
    if (map[pacmanY][pacmanX] == 'R' || map[pacmanY][pacmanX] == 'B') {
        std::cout << "Pacman hit a ghost! Game over." << std::endl;
        return true;
    }
    return false;
}

// Function to move Pacman on the map
void movePacman(std::vector<std::vector<char>>& map, int& pacmanX, int& pacmanY, int newX, int newY) {
    if (newX >= 0 && newX < MAP_WIDTH && newY >= 0 && newY < MAP_HEIGHT && map[newY][newX] != '#') {
        if (checkCollisionWithGhost(map, newX, newY)) {
            std::cout << "Collision detected at (" << newX << ", " << newY << ")" << std::endl;
            exit(0); // Terminate the game
        }
        map[pacmanY][pacmanX] = ' '; // Clear old position
        pacmanX = newX;
        pacmanY = newY;
        map[pacmanY][pacmanX] = 'P'; // Set new position
    }
}