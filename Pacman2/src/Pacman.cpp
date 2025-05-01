#include "../include/Pacman.h"
#include "../include/GameManager.h"
#include "../include/Map.h"
#include "../include/Tile.h"
#include <iostream>

// Initialize static instance
std::unique_ptr<Pacman> Pacman::instance = nullptr;

Pacman::Pacman(Map* map, float x, float y)
    : Entity(map, x, y, 5.0f), // Speed = 5 tiles per second
      isPoweredUp(false), powerUpTime(0.0f), score(0), lives(3) {
    textureId = "pacman";
}

Pacman* Pacman::getInstance(Map* map, float x, float y) {
    if (!instance) {
        instance = std::unique_ptr<Pacman>(new Pacman(map, x, y));
    }
    return instance.get();
}

void Pacman::update(float deltaTime) {
    // Update movement
    Entity::update(deltaTime);
    
    // Check collisions with pellets, ghosts, etc.
    checkCollisions();
    
    // Update power-up state
    if (isPoweredUp) {
        powerUpTime -= deltaTime;
        if (powerUpTime <= 0.0f) {
            isPoweredUp = false;
        }
    }
}

void Pacman::render() const {
    // This will be replaced with actual graphics rendering
    // For now, just print to console for debugging
    auto [tileX, tileY] = getTilePosition();
    
    // In a real game, you'd render the Pacman sprite here
    // For console, we'll just use a simple character
    std::cout << "Pacman at grid position (" << tileX << ", " << tileY << ")" << std::endl;
    std::cout << "Score: " << score << ", Lives: " << lives << std::endl;
    if (isPoweredUp) {
        std::cout << "POWERED UP! Time remaining: " << powerUpTime << std::endl;
    }
}

void Pacman::handleInput(Direction input) {
    // Queue the next direction change
    setNextDirection(input);
}

void Pacman::checkCollisions() {
    // Get current tile position
    auto [tileX, tileY] = getTilePosition();
    
    // Check for pellets and power pellets
    std::shared_ptr<Tile> currentTile = map->getTileAt(tileX, tileY);
    if (currentTile) {
        switch (currentTile->getType()) {
            case TileType::PELLET:
                eatPellet();
                // Replace pellet with floor
                map->setTileAt(tileX, tileY, std::make_shared<Tile>(TileType::FLOOR, true, "floor"));
                break;
                
            case TileType::POWER_PELLET:
                eatPowerPellet();
                // Replace power pellet with floor
                map->setTileAt(tileX, tileY, std::make_shared<Tile>(TileType::FLOOR, true, "floor"));
                break;
                
            default:
                break;
        }
    }
    
    // Check for ghost collisions (will be implemented when we add ghosts)
}

void Pacman::eatPellet() {
    score += 10;
    // You could add sound effects or other feedback here
}

void Pacman::eatPowerPellet() {
    score += 50;
    isPoweredUp = true;
    powerUpTime = 10.0f; // Power-up lasts 10 seconds
    
    // In a real game, this would also trigger the ghosts to become vulnerable
}

void Pacman::die() {
    lives--;
    
    if (lives <= 0) {
        // Game over
        GameManager::getInstance()->setIsRunning(false);
    } else {
        // Reset Pacman position
        setPosition(14.0f, 23.0f); // Standard Pacman starting position
        direction = Direction::NONE;
        nextDirection = Direction::NONE;
    }
}