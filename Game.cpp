#include "Pacman.h"
#include "Map.h"
#include "ghost/RedGhost.h"
#include "ghost/BlueGhost.h"
#include "strategy/ChaseBehavior.h"
#include "strategy/RandomBehavior.h"
#include "decorator/SpeedBoostDecorator.h"
#include "decorator/GhostDecorator.h"
#include "factory/GhostFactory.h"
#include <iostream>

int main() {
    Map map;
    Pacman pacman(1, 1);
    GhostFactory* redGhostFactory = new RedGhostFactory();
    Ghost* redGhost = redGhostFactory->createGhost();
    redGhost->setBehavior(new ChaseBehavior());
    redGhost->display();
    redGhost->performBehavior();

    Ghost* boostedRedGhost = new SpeedBoostDecorator(redGhost);
    boostedRedGhost->display();
    boostedRedGhost->performBehavior();

    delete redGhostFactory;
    delete redGhost;
    delete boostedRedGhost;

    char input;
    while (true) {
        system("cls"); // Membersihkan layar (untuk Windows)
        map.display();
        std::cout << "Use WASD to move Pacman: ";
        std::cin >> input;

        map.placePacman(pacman.getX(), pacman.getY());
        pacman.move(input, map);
    }
    return 0;
}
