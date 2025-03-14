#include "movement.h"
#include "map.h"

// Function to move Pacman on the map
bool checkCollisionWithGhost(const std::vector<std::vector<char>>& map, int pacmanX, int pacmanY) {
    if (map[pacmanY][pacmanX] == 'R' || map[pacmanY][pacmanX] == 'B') {
        std::cout << "Pacman hit a ghost! Game over." << std::endl;
        return true;
    }
    return false;
}

void movePacman(std::vector<std::vector<char>>& map, int& pacmanX, int& pacmanY, int newX, int newY) {
    if (newX >= 0 && newX < MAP_WIDTH && newY >= 0 && newY < MAP_HEIGHT && map[newY][newX] != '#') {
        if (checkCollisionWithGhost(map, newX, newY)) {
            exit(0); // Terminate the game
        }
        map[pacmanY][pacmanX] = ' '; // Clear old position
        pacmanX = newX;
        pacmanY = newY;
        map[pacmanY][pacmanX] = 'P'; // Set new position
    }
}