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
    if (active) return; // If already active, do nothing

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
    timerThread = std::thread(&PowerPellet::timerThreadFunction, this, 5.0);
}

bool PowerPellet::isActive() const {
    return active;
}

double PowerPellet::getRemainingTime() const {
    return remainingTime;
}

void PowerPellet::timerThreadFunction(double duration) {
    auto startTime = std::chrono::steady_clock::now();
    while (remainingTime > 0) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Update every 100ms
        auto elapsed = std::chrono::duration<double>(std::chrono::steady_clock::now() - startTime).count();
        remainingTime = duration - elapsed;

        if (remainingTime <= 0) {
            remainingTime = 0;
            active = false;

            // Reset all ghosts to their normal state
            for (auto& ghost : ghosts) {
                ghost->setState(std::make_unique<WanderState>());
            }

            std::cout << "Pac-Man's power mode expired!" << std::endl;
            break;
        }
    }
}