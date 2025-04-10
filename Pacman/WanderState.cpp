#include "WanderState.h"
#include "Ghost.h"
#include <iostream>
#include <cstdlib>

void WanderState::move(Ghost& ghost, std::vector<std::vector<char>>& map) {
    // Implement the logic to move randomly
    std::cout << "Wandering randomly" << std::endl;

    // Example logic: move to a random adjacent position
    int dx = (std::rand() % 3) - 1; // -1, 0, or 1
    int dy = (std::rand() % 3) - 1; // -1, 0, or 1

    auto [newX, newY] = getNextPosition(ghost, dx, dy, map);
    ghost.setPosition(newX, newY);
}