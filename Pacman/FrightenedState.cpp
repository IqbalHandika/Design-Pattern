#include "FrightenedState.h"
#include "Ghost.h"
#include <iostream>
#include <cstdlib>

void FrightenedState::move(Ghost& ghost, std::vector<std::vector<char>>& map) {
    // Implement the logic to move erratically
    std::cout << "Moving erratically" << std::endl;

    // Example logic: move to a random position with a higher chance of changing direction
    int dx = (std::rand() % 3) - 1; // -1, 0, or 1
    int dy = (std::rand() % 3) - 1; // -1, 0, or 1

    auto [newX, newY] = getNextPosition(ghost, dx, dy, map);
    ghost.setPosition(newX, newY);
}