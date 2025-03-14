#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include "pacman.h"
#include <vector>

class GameManager {
public:
    GameManager();
    void startGame();

private:
    std::vector<std::vector<char>> map;
    Pacman pacman;

    void initializeMap();
    void gameLoop();
};

#endif // GAME_MANAGER_H