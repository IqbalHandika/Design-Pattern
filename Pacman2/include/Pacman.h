#pragma once
#include "Entity.h"
#include <memory>

class Pacman : public Entity {
private:
    // Singleton instance
    static std::unique_ptr<Pacman> instance;
    
    // Pacman state
    bool isPoweredUp;
    float powerUpTime;
    int score;
    int lives;
    
    // Private constructor for singleton
    Pacman(Map* map, float x, float y);
    
public:
    // Delete copy constructor and assignment operator
    Pacman(const Pacman&) = delete;
    Pacman& operator=(const Pacman&) = delete;
    
    // Get singleton instance
    static Pacman* getInstance(Map* map, float x, float y);
    
    // Overridden methods
    void update(float deltaTime) override;
    void render() const override;
    
    // Pacman specific methods
    void handleInput(Direction input);
    void checkCollisions();
    void eatPellet();
    void eatPowerPellet();
    void die();
    
    // Getters and setters
    bool getIsPoweredUp() const { return isPoweredUp; }
    int getScore() const { return score; }
    int getLives() const { return lives; }
};