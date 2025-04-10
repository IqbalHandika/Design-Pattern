#pragma once
#include <vector>
#include "pacman.h"
#include "Ghost.h"
#include "TimeSystem.h"

class PowerPellet {
public:
    PowerPellet(TimeSystem& timeSystem, std::vector<std::unique_ptr<Ghost>>& ghosts);

    // Activate the power pellet effect
    void activate(Pacman& pacman, std::vector<std::vector<char>>& map);

    // Check if the power pellet effect has expired
    void update(Pacman& pacman);

    // Get the remaining time for the power pellet effect
    double getRemainingTime() const;

private:
    TimeSystem& timeSystem; // Reference to the time system
    std::vector<std::unique_ptr<Ghost>>& ghosts; // Reference to the ghosts
    bool isActive = false; // Whether the power pellet effect is active
};