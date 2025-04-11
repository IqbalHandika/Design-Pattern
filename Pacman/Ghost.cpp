#include "Ghost.h"
#include "WanderState.h"
#include "ChaseState.h"

Ghost::Ghost(int startX, int startY) 
    : x(startX), y(startY), state(std::make_unique<WanderState>()) {
    // Start the timer for the initial state
    timeSystem.startTimer("StateTimer");
}

void Ghost::setState(std::unique_ptr<GhostState> newState) {
    state = std::move(newState);
    timeSystem.startTimer("StateTimer"); // Reset the timer for the new state
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

void Ghost::updateState() {
    // Check if the timer for the current state has expired
    if (timeSystem.isTimerExpired("StateTimer", 10.0)) { // Example: 10 seconds per state
        if (dynamic_cast<WanderState*>(state.get())) {
            // Switch from WanderState to ChaseState
            setState(std::make_unique<ChaseState>());
        } else if (dynamic_cast<ChaseState*>(state.get())) {
            // Switch from ChaseState to WanderState
            setState(std::make_unique<WanderState>());
        }
    }
}