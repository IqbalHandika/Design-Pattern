#include "pacman.h"
#include <iostream>
#include <cstdlib> // For system()
#include <unordered_set>

// Private constructor for singleton
Pacman::Pacman(int startX, int startY) : x(startX), y(startY) {}

bool Pacman::checkCollisionWithGhost(const std::vector<std::vector<char>>& map) {
    // Set of ghost symbols
    std::unordered_set<char> ghostSymbols = {'R', 'B', 'P', 'O'}; // Ghost symbols only
    
    if (ghostSymbols.find(map[y][x]) != ghostSymbols.end()) {
        std::cout << "Pacman hit a ghost! Game over." << std::endl;
        return true;
    }
    return false;
}

bool Pacman::move(std::vector<std::vector<char>>& map, int newX, int newY) {
    if (newX >= 0 && newX < map[0].size() && newY >= 0 && newY < map.size() && map[newY][newX] != '#') {
        // Check for Power Pellet
        if (map[newY][newX] == 'o') {
            std::cout << "Pac-Man ate a Power Pellet!" << std::endl;
            powerModeActive = true; // Activate power mode
        }

        // Temporarily move Pac-Man to the new position to check for collision
        int oldX = x, oldY = y;
        x = newX;
        y = newY;

        if (checkCollisionWithGhost(map)) {
            // If collision is detected, reset Pac-Man's position and terminate the game
            x = oldX;
            y = oldY;
            return false; // Indicate collision
        }

        // No collision: update the map
        map[oldY][oldX] = ' '; // Clear old position
        map[y][x] = '<';       // Set new position with Pac-Man's new icon
    }
    return true; // Indicate no collision
}

int Pacman::getX() const {
    return x;
}

int Pacman::getY() const {
    return y;
}