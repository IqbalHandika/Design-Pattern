#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include "pacman.h"
#include "GhostFactory.h"
#include "TimeSystem.h"
#include "PowerPellet.h"
#include <vector>
#include <memory>

class GameManager {
public:
    GameManager();
    void startGame();

private:
    std::vector<std::vector<char>> map;
    Pacman* pacman; // Pointer to the singleton Pacman instance
    TimeSystem timeSystem; // Time system for managing timers
    std::vector<std::unique_ptr<Ghost>> ghosts; // List of ghosts
    PowerPellet* powerPellet; // Power pellet manager

    void initializeMap();
    void placeGhosts();
    void gameLoop();
};

#endif // GAME_MANAGER_H