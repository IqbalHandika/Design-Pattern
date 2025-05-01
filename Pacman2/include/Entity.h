#pragma once
#include <string>

// Direction enum for entity movement
enum class Direction {
    NONE,
    UP,
    RIGHT,
    DOWN,
    LEFT
};

class Map; // Forward declaration

class Entity {
protected:
    float x, y;             // Position
    float speed;            // Movement speed (tiles per second)
    Direction direction;    // Current direction
    Direction nextDirection; // Next queued direction
    std::string textureId;  // For rendering
    Map* map;               // Reference to the game map
    
public:
    Entity(Map* map, float x, float y, float speed);
    virtual ~Entity() = default;
    
    // Getters and setters
    float getX() const { return x; }
    float getY() const { return y; }
    void setPosition(float newX, float newY);
    Direction getDirection() const { return direction; }
    void setDirection(Direction newDirection) { direction = newDirection; }
    void setNextDirection(Direction newDirection) { nextDirection = newDirection; }
    
    // Virtual methods to be overridden by derived classes
    virtual void update(float deltaTime);
    virtual void render() const;
    
    // Movement methods
    bool canMoveInDirection(Direction dir) const;
    void move(float deltaTime);
    
    // Helper methods
    bool isAtCenterOfTile() const;
    std::pair<int, int> getTilePosition() const;
};