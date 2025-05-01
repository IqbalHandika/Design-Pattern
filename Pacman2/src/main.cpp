#include <iostream>
#include "../include/GameManager.h"

int main() {
    // Get the GameManager instance
    GameManager* gameManager = GameManager::getInstance();
    
    try {
        // Initialize the game
        gameManager->initialize();
        
        // Run the main game loop
        gameManager->run();
        
        // Clean up when the game ends
        gameManager->shutdown();
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    
    // Clean up the singleton instance
    delete gameManager;
    
    return 0;
}