#include "pacman.h"
#include <iostream>
#include <cstdlib> // For system()

Pacman::Pacman(int startX, int startY) : x(startX), y(startY) {}

bool Pacman::checkCollisionWithGhost(const std::vector<std::vector<char>>& map) {
    if (map[y][x] == 'R' || map[y][x] == 'B') {
        std::cout << "Pacman hit a ghost! Game over." << std::endl;
        return true;
    }
    return false;
}

void Pacman::move(std::vector<std::vector<char>>& map, int newX, int newY) {
    if (newX >= 0 && newX < map[0].size() && newY >= 0 && newY < map.size() && map[newY][newX] != '#') {
        if (checkCollisionWithGhost(map)) {
            std::cout << "Collision detected at (" << newX << ", " << newY << ")" << std::endl;
            exit(0); // Terminate the game
        }
        map[y][x] = ' '; // Clear old position
        x = newX;
        y = newY;
        map[y][x] = 'P'; // Set new position

        // Clear the console screen
        system("CLS");

    }
}

int Pacman::getX() const {
    return x;
}

int Pacman::getY() const {
    return y;
}