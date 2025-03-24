#include "map.h"
#include <iostream>

// Function to initialize the map with a predefined maze layout
void initializeMap(std::vector<std::vector<char>>& map) {
    // Define the maze layout
    const char maze[MAP_HEIGHT][MAP_WIDTH] = {
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', '#'},
        {'#', '#', ' ', '#', '#', '#', '#', ' ', ' ', '#'},
        {'#', ' ', ' ', '#', ' ', ' ', '#', ' ', '#', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', '#'},
        {'#', ' ', '#', '#', '#', '#', '#', ' ', ' ', '#'},
        {'#', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', '#'},
        {'#', '#', ' ', ' ', ' ', ' ', '#', ' ', ' ', '#'},
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
    };

    // Copy the maze layout to the map
    for (int i = 0; i < MAP_HEIGHT; ++i) {
        for (int j = 0; j < MAP_WIDTH; ++j) {
            map[i][j] = maze[i][j];
        }
    }
}

// Function to place a character on the map
void placeCharacterOnMap(std::vector<std::vector<char>>& map, int x, int y, char character) {
    if (x >= 0 && x < MAP_WIDTH && y >= 0 && y < MAP_HEIGHT) {
        map[y][x] = character;
    }
}

// Function to render the map to the console
void renderMap(const std::vector<std::vector<char>>& map) {
    for (const auto& row : map) {
        for (const auto& cell : row) {
            std::cout << cell << ' ';
        }
        std::cout << std::endl;
    }
}