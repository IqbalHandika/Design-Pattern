#include "map.h"
#include <iostream>
#include <vector>


// Function to initialize the map with a predefined maze layout
void initializeMap(std::vector<std::vector<char>>& map) {
    // Define the maze layout
    const char maze[MAP_HEIGHT][MAP_WIDTH] = {
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', '#'},
        {'#', '#', ' ', '#', ' ', '#', '#', ' ', ' ', '#'},
        {'#', ' ', ' ', '#', ' ', ' ', ' ', ' ', '#', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', '#'},
        {'#', ' ', '#', '#', '#', ' ', '#', ' ', ' ', '#'},
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

// Function to update only the changed positions on the map
void updatePositionOnMap(const std::vector<std::vector<char>>& map, int oldX, int oldY, int newX, int newY, char character) {
    // Clear the old position
    if (oldX >= 0 && oldX < MAP_WIDTH && oldY >= 0 && oldY < MAP_HEIGHT) {
        std::cout << "\033[" << oldY + 1 << ";" << (oldX * 2) + 1 << "H "; // Clear old position
    }

    // Draw the new position
    if (newX >= 0 && newX < MAP_WIDTH && newY >= 0 && newY < MAP_HEIGHT) {
        std::cout << "\033[" << newY + 1 << ";" << (newX * 2) + 1 << "H" << character; // Draw new position
    }

    // Flush the output to ensure it appears immediately
    std::cout << std::flush;
}