#include "BlueGhost.h"
#include <iostream>

BlueGhost::BlueGhost() : behavior(nullptr) {}

BlueGhost::~BlueGhost() {
    delete behavior;
}

void BlueGhost::display() {
    std::cout << "I am Blue Ghost" << std::endl;
}

void BlueGhost::setBehavior(GhostBehavior* behavior) {
    delete this->behavior;
    this->behavior = behavior;
}

void BlueGhost::performBehavior() {
    if (behavior) {
        behavior->move();
    }
}