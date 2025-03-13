#include "GhostFactory.h"
#include "map.h"
#include "movement.h"
#include <iostream>
#include <vector>
#include <conio.h> // For _kbhit() and _getch()

int main() {
    // Register all ghost types
    registerGhosts();

    // Create ghosts dynamically
    auto redGhost = GhostFactory::getInstance().createGhost("RedGhost");
    auto blueGhost = GhostFactory::getInstance().createGhost("BlueGhost");

    // Initialize the map
    std::vector<std::vector<char>> map(MAP_HEIGHT, std::vector<char>(MAP_WIDTH));
    initializeMap(map);

    // Place Pacman and ghosts on the map
    int pacmanX = 1, pacmanY = 1;
    placeCharacterOnMap(map, pacmanX, pacmanY, 'P'); // Place Pacman at (1, 1)
    placeCharacterOnMap(map, 3, 3, 'R'); // Place RedGhost at (3, 3)
    placeCharacterOnMap(map, 4, 6, 'B'); // Place BlueGhost at (4, 6)

    // Render the initial map
    renderMap(map);

    // Main loop to handle user input and move Pacman
    while (true) {
        if (_kbhit()) {
            char input = _getch();
            int newX = pacmanX, newY = pacmanY;

            if (input == 'w') newY--; // Move up
            else if (input == 's') newY++; // Move down
            else if (input == 'a') newX--; // Move left
            else if (input == 'd') newX++; // Move right
            else if (input == 'q') break; // Quit the game

            movePacman(map, pacmanX, pacmanY, newX, newY);

            // Render the updated map
            system("cls"); // Clear the console (Windows-specific)
            renderMap(map);
        }
    }

    return 0;
}