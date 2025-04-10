#include "Ghost.h"
#include "ChaseState.h"

Ghost::Ghost(int startX, int startY) : x(startX), y(startY), state(std::make_unique<ChaseState>()) {}

void Ghost::setState(std::unique_ptr<GhostState> newState) {
    state = std::move(newState);
}

void Ghost::move(std::vector<std::vector<char>>& map) {
    state->move(*this, map);
}

int Ghost::getX() const {
    return x;
}

int Ghost::getY() const {
    return y;
}

void Ghost::setPosition(int newX, int newY) {
    x = newX;
    y = newY;
}