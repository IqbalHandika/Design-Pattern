#ifndef PACMAN_H
#define PACMAN_H

#include <vector>

class Pacman {
public:
    // Singleton access method
    static Pacman& getInstance(int startX = 0, int startY = 0) {
        static Pacman instance(startX, startY);
        return instance;
    }

    // Delete copy constructor and assignment operator to enforce singleton
    Pacman(const Pacman&) = delete;
    Pacman& operator=(const Pacman&) = delete;

    // Existing methods
    bool checkCollisionWithGhost(const std::vector<std::vector<char>>& map);
    bool move(std::vector<std::vector<char>>& map, int newX, int newY);

    int getX() const;
    int getY() const;

    // Power mode methods
    bool isPowerModeActive() const { return powerModeActive; }
    void setPowerModeActive(bool active) { powerModeActive = active; }

private:
    // Private constructor for singleton
    Pacman(int startX, int startY);

    int x;
    int y;
    bool powerModeActive = false; // Flag for power mode
};

#endif // PACMAN_H