#include "Pacman.h"
#include "Map.h"

Pacman::Pacman(int startX, int startY) : x(startX), y(startY) {}

void Pacman::move(char direction, Map& map) {
    int newX = x, newY = y;
    switch (direction) {
        case 'w': newY--; break; // ke atas
        case 's': newY++; break; // ke bawah
        case 'a': newX--; break; // ke kiri
        case 'd': newX++; break; // ke kanan
    }
    if (map.isValidMove(newX, newY)) {
        x = newX;
        y = newY;
    }
}

int Pacman::getX() const {
    return x;
}

int Pacman::getY() const {
    return y;
}