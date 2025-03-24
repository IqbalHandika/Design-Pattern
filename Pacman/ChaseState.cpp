#include "ChaseState.h"
#include "Ghost.h"
#include "Pacman.h"
#include <iostream>

void ChaseState::move(Ghost& ghost, std::vector<std::vector<char>>& map) {
    // Implement the logic to actively pursue Pac-Man
    std::cout << "Chasing Pac-Man" << std::endl;

    // Example logic: move towards Pac-Man's position
    Pacman& pacman = Pacman::getInstance(); // Assuming Pacman is a singleton
    int dx = (pacman.getX() > ghost.getX()) ? 1 : (pacman.getX() < ghost.getX()) ? -1 : 0;
    int dy = (pacman.getY() > ghost.getY()) ? 1 : (pacman.getY() < ghost.getY()) ? -1 : 0;

    auto [newX, newY] = getNextPosition(ghost, dx, dy, map);
    ghost.setPosition(newX, newY);
}