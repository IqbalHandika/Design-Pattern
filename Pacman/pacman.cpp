#include "pacman.h"
#include <iostream>
#include <cstdlib> // For system()
#include <unordered_set>

Pacman::Pacman(int startX, int startY) : x(startX), y(startY) {}

bool Pacman::checkCollisionWithGhost(const std::vector<std::vector<char>>& map) {
    // Set of ghost symbols
    std::unordered_set<char> ghostSymbols = {'R', 'B', 'P', 'O'};
    
    if (ghostSymbols.find(map[y][x]) != ghostSymbols.end()) {
        std::cout << "Pacman hit a ghost! Game over." << std::endl;
        return true;
    }
    return false;
}

bool Pacman::move(std::vector<std::vector<char>>& map, int newX, int newY) {
    if (newX >= 0 && newX < map[0].size() && newY >= 0 && newY < map.size() && map[newY][newX] != '#') {
        if (map[newY][newX] == 'R' || map[newY][newX] == 'B' || map[newY][newX] == 'P' || map[newY][newX] == 'O') {
            std::cout << "Collision detected at (" << newX << ", " << newY << ")" << std::endl;
            return false; // Indicate collision
        }
        map[y][x] = ' '; // Clear old position
        x = newX;
        y = newY;
        map[y][x] = 'P'; // Set new position

        // Clear the console screen
        system("CLS");

    }
    return true; // Indicate no collision
}

int Pacman::getX() const {
    return x;
}

int Pacman::getY() const {
    return y;
}