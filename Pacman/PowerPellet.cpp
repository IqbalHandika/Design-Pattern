#include "PowerPellet.h"
#include "SpeedBoostDecorator.h"
#include "FrightenedState.h"
#include "WanderState.h"
#include "TimeSystem.h"
#include <iostream>

PowerPellet::PowerPellet(TimeSystem& timeSystem, std::vector<std::unique_ptr<Ghost>>& ghosts)
    : timeSystem(timeSystem), ghosts(ghosts) {}

void PowerPellet::activate(Pacman& pacman, std::vector<std::vector<char>>& map) {
    std::cout << "Pac-Man ate a Power Pellet!" << std::endl;

    // Activate power mode for Pac-Man
    pacman.setPowerModeActive(true);

    // Switch all ghosts to FrightenedState with SpeedBoostDecorator
    for (auto& ghost : ghosts) {
        ghost->setState(std::make_unique<SpeedBoostDecorator>(
            std::make_unique<FrightenedState>()
        ));
    }

    // Start the Power Pellet timer
    timeSystem.startTimer("PowerPellet");
    isActive = true;
}

void PowerPellet::update(Pacman& pacman) {
    if (isActive && timeSystem.isTimerExpired("PowerPellet", 5.0)) {
        std::cout << "Pac-Man's power mode expired!" << std::endl;

        // Reset all ghosts to their normal state
        for (auto& ghost : ghosts) {
            ghost->setState(std::make_unique<WanderState>());
        }

        // Deactivate power mode
        pacman.setPowerModeActive(false);
        isActive = false;
    }
}

double PowerPellet::getRemainingTime() const {
    if (isActive) {
        auto elapsed = timeSystem.isTimerExpired("PowerPellet", 0.0) ? 0.0 : 5.0 - std::chrono::duration<double>(
            std::chrono::steady_clock::now() - timeSystem.timers.at("PowerPellet")).count();
        return elapsed > 0 ? elapsed : 0.0;
    }
    return 0.0;
}