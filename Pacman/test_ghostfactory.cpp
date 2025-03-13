#include "GhostFactory.h"
#include <iostream>
#include <cassert>

void testGhostFactory() {
    // Register all ghost types
    registerGhosts();

    // Create ghosts dynamically
    auto redGhost = GhostFactory::getInstance().createGhost("RedGhost");
    auto blueGhost = GhostFactory::getInstance().createGhost("BlueGhost");

    // Test if the ghosts are created correctly
    assert(redGhost != nullptr && redGhost->getType() == "RedGhost");
    assert(blueGhost != nullptr && blueGhost->getType() == "BlueGhost");

    std::cout << "All tests passed!" << std::endl;
}

int main() {
    testGhostFactory();
    return 0;
}