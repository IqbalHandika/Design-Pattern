#include "movement.h"
#include "map.h"

// Function to move Pacman on the map
void movePacman(std::vector<std::vector<char>>& map, int& pacmanX, int& pacmanY, int newX, int newY) {
    if (newX >= 0 && newX < MAP_WIDTH && newY >= 0 && newY < MAP_HEIGHT && map[newY][newX] != '#') {
        map[pacmanY][pacmanX] = ' '; // Clear old position
        pacmanX = newX;
        pacmanY = newY;
        map[pacmanY][pacmanX] = 'P'; // Set new position
    }
}