#include "../include/GameManager.h"
#include "../include/Pacman.h"
#include "../include/Map.h"
#include "../include/Tile.h"
#include <chrono>
#include <iostream>
#include <thread>
#include <conio.h> // For _kbhit and _getch on Windows

// Initialize static instance pointer
GameManager* GameManager::instance = nullptr;

GameManager::GameManager() : isRunning(false), deltaTime(0.0f), pacman(nullptr) {
    // Initialize with a default map
    gameMap = std::make_unique<Map>(28, 31);
}

GameManager::~GameManager() {
    // Cleanup resources
}

GameManager* GameManager::getInstance() {
    if (instance == nullptr) {
        instance = new GameManager();
    }
    return instance;
}

void GameManager::initialize() {
    std::cout << "Initializing game..." << std::endl;
    
    // Create a basic map for testing
    for (int y = 0; y < gameMap->getHeight(); y++) {
        for (int x = 0; x < gameMap->getWidth(); x++) {
            // Create walls around the edges
            if (x == 0 || y == 0 || x == gameMap->getWidth() - 1 || y == gameMap->getHeight() - 1) {
                gameMap->setTileAt(x, y, std::make_shared<Tile>(TileType::WALL, false, "wall"));
            } else {
                // Add some pellets
                if ((x + y) % 5 == 0) {
                    gameMap->setTileAt(x, y, std::make_shared<Tile>(TileType::PELLET, true, "pellet"));
                } else if ((x + y) % 17 == 0) {
                    gameMap->setTileAt(x, y, std::make_shared<Tile>(TileType::POWER_PELLET, true, "power_pellet"));
                } else {
                    gameMap->setTileAt(x, y, std::make_shared<Tile>(TileType::FLOOR, true, "floor"));
                }
            }
        }
    }
    
    // Alternative: load map from file
    // gameMap->loadFromFile("assets/maps/level1.map");
    
    // Create Pacman at a starting position
    pacman = Pacman::getInstance(gameMap.get(), 14.0f, 23.0f);
    
    // Initialize timing
    previousTime = std::chrono::high_resolution_clock::now();
    
    isRunning = true;
    std::cout << "Game initialized successfully!" << std::endl;
    std::cout << "Controls: W=Up, A=Left, S=Down, D=Right, Q=Quit" << std::endl;
}

void GameManager::run() {
    std::cout << "Starting game loop..." << std::endl;
    
    while (isRunning) {
        // Calculate delta time
        auto currentTime = std::chrono::high_resolution_clock::now();
        deltaTime = std::chrono::duration<float>(currentTime - previousTime).count();
        previousTime = currentTime;
        
        // Run game loop components
        processInput();
        update();
        render();
        
        // Cap frame rate (optional)
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

void GameManager::shutdown() {
    std::cout << "Shutting down game..." << std::endl;
    // Clean up any resources, save game state, etc.
}

void GameManager::processInput() {
    // Check for keyboard input (Windows-specific)
    if (_kbhit()) {
        char ch = _getch();
        
        // Convert input to direction
        Direction input = Direction::NONE;
        switch (tolower(ch)) {
            case 'w': input = Direction::UP; break;
            case 'd': input = Direction::RIGHT; break;
            case 's': input = Direction::DOWN; break;
            case 'a': input = Direction::LEFT; break;
            case 'q': isRunning = false; break;
        }
        
        // Send input to Pacman if valid
        if (input != Direction::NONE) {
            pacman->handleInput(input);
        }
    }
}

void GameManager::update() {
    // Update all game objects
    gameMap->update(deltaTime);
    
    // Update Pacman specifically
    pacman->update(deltaTime);
    
    // More game logic will be added here
}

void GameManager::render() {
    // Clear screen (console based for now)
    system("cls"); // For Windows
    // system("clear"); // For Unix/Linux
    
    // Render map
    for (int y = 0; y < gameMap->getHeight(); y++) {
        for (int x = 0; x < gameMap->getWidth(); x++) {
            auto tile = gameMap->getTileAt(x, y);
            
            // Check if Pacman is at this position
            auto [pacmanX, pacmanY] = pacman->getTilePosition();
            
            if (pacmanX == x && pacmanY == y) {
                // Render Pacman
                char dirChar = 'C'; // Default
                switch (pacman->getDirection()) {
                    case Direction::UP: dirChar = 'V'; break;
                    case Direction::RIGHT: dirChar = '>'; break;
                    case Direction::DOWN: dirChar = '^'; break;
                    case Direction::LEFT: dirChar = '<'; break;
                    default: break;
                }
                std::cout << dirChar;
            } else if (tile) {
                // Render the tile
                switch (tile->getType()) {
                    case TileType::WALL: std::cout << "#"; break;
                    case TileType::PELLET: std::cout << "."; break;
                    case TileType::POWER_PELLET: std::cout << "O"; break;
                    case TileType::DOOR: std::cout << "-"; break;
                    default: std::cout << " "; break;
                }
            }
        }
        std::cout << std::endl;
    }
    
    // Print game info
    std::cout << "Score: " << pacman->getScore() << " | Lives: " << pacman->getLives() << std::endl;
    if (pacman->getIsPoweredUp()) {
        std::cout << "POWERED UP!" << std::endl;
    }
    
    // Print some debug info
    std::cout << "FPS: " << 1.0f / deltaTime << std::endl;
}