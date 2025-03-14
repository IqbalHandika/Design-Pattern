#ifndef PACMAN_H
#define PACMAN_H

#include <vector>
#include <iostream>

class Pacman {
public:
    Pacman(int startX, int startY);
    bool checkCollisionWithGhost(const std::vector<std::vector<char>>& map);
    void move(std::vector<std::vector<char>>& map, int newX, int newY);

    int getX() const;
    int getY() const;

private:
    int x;
    int y;
};

#endif // PACMAN_H