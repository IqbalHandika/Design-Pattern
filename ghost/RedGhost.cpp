#include "RedGhost.h"
#include <iostream>

RedGhost::RedGhost() : behavior(nullptr) {}

RedGhost::~RedGhost() {
    delete behavior;
}

void RedGhost::display() {
    std::cout << "I am Red Ghost" << std::endl;
}

void RedGhost::setBehavior(GhostBehavior* behavior) {
    delete this->behavior;
    this->behavior = behavior;
}

void RedGhost::performBehavior() {
    if (behavior) {
        behavior->move();
    }
}