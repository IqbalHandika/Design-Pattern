#include "SpeedBoostDecorator.h"
#include <iostream>

SpeedBoostDecorator::SpeedBoostDecorator(Ghost* ghost) : GhostDecorator(ghost) {}

void SpeedBoostDecorator::display() {
    GhostDecorator::display();
    std::cout << " with Speed Boost" << std::endl;
}

void SpeedBoostDecorator::performBehavior() {
    GhostDecorator::performBehavior();
    std::cout << "Moving faster!" << std::endl;
}