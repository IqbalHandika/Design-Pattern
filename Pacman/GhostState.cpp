#include "GhostState.h"
#include "Ghost.h"
#include <iostream>

std::pair<int, int> GhostState::getNextPosition(Ghost& ghost, int dx, int dy, const std::vector<std::vector<char>>& map) {
    int newX = ghost.getX() + dx;
    int newY = ghost.getY() + dy;

    // Check boundaries and ensure the position is valid
    if (newY >= 0 && newY < map.size() && newX >= 0 && newX < map[newY].size() && map[newY][newX] != '#' && map[newY][newX] != 'P') {
        return {newX, newY};
    }

    // Return current position if the move is invalid
    return {ghost.getX(), ghost.getY()};
}