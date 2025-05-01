#pragma once
#include <memory>
#include <chrono>
#include "Map.h"
#include "Pacman.h" // Add Pacman include

class GameManager {
private:
    // Singleton instance
    static GameManager* instance;
    
    // Game state
    bool isRunning;
    std::unique_ptr<Map> gameMap;
    Pacman* pacman; // Add Pacman reference
    
    // Timing
    std::chrono::time_point<std::chrono::high_resolution_clock> previousTime;
    float deltaTime;
    
    // Private constructor for singleton
    GameManager();

public:
    // Delete copy constructor and assignment operator
    GameManager(const GameManager&) = delete;
    GameManager& operator=(const GameManager&) = delete;
    
    // Get singleton instance
    static GameManager* getInstance();
    
    // Destructor
    ~GameManager();
    
    // Game flow methods
    void initialize();
    void run();
    void shutdown();
    
    // Game loop components
    void processInput();
    void update();
    void render();
    
    // Helper methods
    float getDeltaTime() const { return deltaTime; }
    Map* getMap() const { return gameMap.get(); }
    Pacman* getPacman() const { return pacman; }
    bool getIsRunning() const { return isRunning; }
    void setIsRunning(bool running) { isRunning = running; }
};