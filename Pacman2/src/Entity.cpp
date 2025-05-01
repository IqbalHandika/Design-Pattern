#include "../include/Entity.h"
#include "../include/Map.h"
#include "../include/Tile.h"
#include <iostream>
#include <cmath>

Entity::Entity(Map* map, float x, float y, float speed)
    : x(x), y(y), speed(speed), direction(Direction::NONE), nextDirection(Direction::NONE),
      textureId("entity"), map(map) {
}

void Entity::setPosition(float newX, float newY) {
    x = newX;
    y = newY;
}

bool Entity::canMoveInDirection(Direction dir) const {
    int tileX = static_cast<int>(std::round(x));
    int tileY = static_cast<int>(std::round(y));
    
    // Check the next tile in the given direction
    switch (dir) {
        case Direction::UP:
            tileY -= 1;
            break;
        case Direction::RIGHT:
            tileX += 1;
            break;
        case Direction::DOWN:
            tileY += 1;
            break;
        case Direction::LEFT:
            tileX -= 1;
            break;
        default:
            return false;
    }
    
    // Check if the next tile is walkable
    std::shared_ptr<Tile> tile = map->getTileAt(tileX, tileY);
    return tile && tile->isWalkable();
}

void Entity::move(float deltaTime) {
    // Try to change to the next direction if we're at a grid center
    if (nextDirection != Direction::NONE && isAtCenterOfTile()) {
        if (canMoveInDirection(nextDirection)) {
            direction = nextDirection;
            nextDirection = Direction::NONE;
        }
    }
    
    // Move in the current direction
    float distance = speed * deltaTime;
    
    switch (direction) {
        case Direction::UP:
            if (canMoveInDirection(Direction::UP)) {
                y -= distance;
            }
            break;
        case Direction::RIGHT:
            if (canMoveInDirection(Direction::RIGHT)) {
                x += distance;
            }
            break;
        case Direction::DOWN:
            if (canMoveInDirection(Direction::DOWN)) {
                y += distance;
            }
            break;
        case Direction::LEFT:
            if (canMoveInDirection(Direction::LEFT)) {
                x -= distance;
            }
            break;
        default:
            break;
    }
}

bool Entity::isAtCenterOfTile() const {
    // Check if the entity is close to the center of a tile
    float centerX = std::round(x);
    float centerY = std::round(y);
    
    // Consider the entity at center if it's within a small threshold
    const float threshold = 0.1f;
    return std::abs(x - centerX) < threshold && std::abs(y - centerY) < threshold;
}

std::pair<int, int> Entity::getTilePosition() const {
    return {static_cast<int>(std::round(x)), static_cast<int>(std::round(y))};
}

void Entity::update(float deltaTime) {
    move(deltaTime);
}

void Entity::render() const {
    // This will be replaced with actual graphics rendering
    // For now, we're just printing to console for debugging
    std::cout << "Entity at position (" << x << ", " << y << ")" << std::endl;
}