#include "ReturnToBaseState.h"
#include "Ghost.h"
#include <iostream>

void ReturnToBaseState::move(Ghost& ghost, std::vector<std::vector<char>>& map) {
    // Example logic: move towards the ghost house position
    int baseX = 1; // Assuming the base is at (1, 1)
    int baseY = 1;

    int dx = (baseX > ghost.getX()) ? 1 : (baseX < ghost.getX()) ? -1 : 0;
    int dy = (baseY > ghost.getY()) ? 1 : (baseY < ghost.getY()) ? -1 : 0;

    auto [newX, newY] = getNextPosition(ghost, dx, dy, map);
    ghost.setPosition(newX, newY);
}