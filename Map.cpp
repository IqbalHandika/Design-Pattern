#include "Map.h"
#include <iostream>

Map::Map() {
    // Inisialisasi peta dengan dinding ('#') dan jalan kosong ('.')
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            if (i == 0 || i == height - 1 || j == 0 || j == width - 1) {
                grid[i][j] = '#';
            } else {
                grid[i][j] = '.';
            }
        }
    }
}

void Map::display() const {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            std::cout << grid[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}

bool Map::isValidMove(int x, int y) const {
    return grid[y][x] == '.';
}

void Map::placePacman(int x, int y) {
    grid[y][x] = 'P';
}