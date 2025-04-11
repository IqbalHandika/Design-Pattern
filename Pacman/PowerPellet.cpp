#include "PowerPellet.h"
#include "SpeedBoostDecorator.h"
#include "FrightenedState.h"
#include "WanderState.h"
#include <iostream>
#include <chrono>
#include <thread>

PowerPellet::PowerPellet(std::vector<std::unique_ptr<Ghost>>& ghosts)
    : ghosts(ghosts), active(false), remainingTime(0.0) {}

PowerPellet::~PowerPellet() {
    if (timerThread.joinable()) {
        timerThread.join(); // Ensure the thread is properly joined
    }
}

void PowerPellet::activate(Pacman& pacman) {
    if (active) {
        std::cout << "Power Pellet is already active!" << std::endl;
        return; // If already active, do nothing
    }

    std::cout << "Pac-Man ate a Power Pellet!" << std::endl;

    // Activate power mode for Pac-Man
    pacman.setPowerModeActive(true);

    // Switch all ghosts to FrightenedState with SpeedBoostDecorator
    for (auto& ghost : ghosts) {
        ghost->setState(std::make_unique<SpeedBoostDecorator>(
            std::make_unique<FrightenedState>()
        ));
    }

    // Start the timer in a separate thread
    active = true;
    remainingTime = 5.0; // Set the duration to 5 seconds

    // If a previous thread exists, join it before starting a new one
    if (timerThread.joinable()) {
        timerThread.join();
    }

    timerThread = std::thread(&PowerPellet::countdownTimer, this, 5);
}

bool PowerPellet::isActive() const {
    return active;
}

double PowerPellet::getRemainingTime() const {
    return remainingTime;
}

void PowerPellet::countdownTimer(int seconds) {
    for (int i = seconds; i >= 0; --i) {
        remainingTime = i;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    // Timer expired, deactivate power mode
    active = false;
    remainingTime = 0;

    // Reset all ghosts to their normal state
    for (auto& ghost : ghosts) {
        ghost->setState(std::make_unique<WanderState>());
    }

    std::cout << "Pac-Man's power mode expired!" << std::endl;
}