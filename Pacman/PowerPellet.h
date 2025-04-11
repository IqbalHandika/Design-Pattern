#pragma once
#include <vector>
#include <thread>
#include <atomic>
#include "pacman.h"
#include "Ghost.h"

class PowerPellet {
public:
    PowerPellet(std::vector<std::unique_ptr<Ghost>>& ghosts);
    ~PowerPellet();

    // Activate the power pellet effect
    void activate(Pacman& pacman);

    // Check if the power pellet effect is active
    bool isActive() const;

    // Get the remaining time for the power pellet effect
    double getRemainingTime() const;

private:
    void countdownTimer(int seconds); // Declare the countdownTimer function

    std::vector<std::unique_ptr<Ghost>>& ghosts; // Reference to the ghosts
    std::atomic<bool> active; // Whether the power pellet effect is active
    std::atomic<double> remainingTime; // Remaining time for the effect
    std::thread timerThread; // Background thread for the timer
};