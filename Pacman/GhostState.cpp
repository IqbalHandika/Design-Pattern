#include "GhostState.h"
#include "Ghost.h"

std::pair<int, int> GhostState::getNextPosition(Ghost& ghost, int dx, int dy, const std::vector<std::vector<char>>& map) {
    int newX = ghost.getX() + dx;
    int newY = ghost.getY() + dy;

    if (newX >= 0 && newX < map[0].size() && newY >= 0 && newY < map.size() && map[newY][newX] != '#') {
        return {newX, newY};
    }
    return {ghost.getX(), ghost.getY()};
}