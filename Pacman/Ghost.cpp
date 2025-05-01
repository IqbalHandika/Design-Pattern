#include "Ghost.h"
#include "WanderState.h"
#include "ChaseState.h"
#include "Pacman.h"
#include <chrono>
#include <iostream>

Ghost::Ghost(int startX, int startY) 
    : x(startX), y(startY), state(std::make_unique<WanderState>()), running(false) {
    timeSystem.startTimer("StateTimer");
}

Ghost::~Ghost() {
    stopMovement(); // Ensure the thread is stopped
}

void Ghost::setState(std::unique_ptr<GhostState> newState) {
    state = std::move(newState);
    timeSystem.startTimer("StateTimer");
}

void Ghost::move(std::vector<std::vector<char>>& map) {
    // Store the old position
    int oldX = x, oldY = y;

    // Move the ghost
    state->move(*this, map);

    // Check if the ghost's new position is the same as Pac-Man's position
    Pacman& pacman = Pacman::getInstance();
    if (x == pacman.getX() && y == pacman.getY()) {
        // Handle collision (e.g., game over)
        std::cout << "Pac-Man collided with a ghost! Game over!" << std::endl;
        running = false; // Stop the ghost's movement thread
        return;
    }

    // Update only the changed positions
    updatePositionOnMap(map, oldX, oldY, x, y, getIcon());
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
    if (timeSystem.isTimerExpired("StateTimer", 10.0)) {
        if (dynamic_cast<WanderState*>(state.get())) {
            setState(std::make_unique<ChaseState>());
        } else if (dynamic_cast<ChaseState*>(state.get())) {
            setState(std::make_unique<WanderState>());
        }
    }
}

void Ghost::startMovement(std::vector<std::vector<char>>& map) {
    running = true;
    movementThread = std::thread([this, &map]() {
        while (running) {
            move(map); // Move the ghost
            std::this_thread::sleep_for(std::chrono::milliseconds(500)); // Adjust speed as needed
        }
    });
}

void Ghost::stopMovement() {
    running = false;
    if (movementThread.joinable()) {
        movementThread.join();
    }
}