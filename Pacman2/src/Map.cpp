#include "../include/Map.h"
#include "../include/Tile.h"
#include <fstream>
#include <iostream>

// Forward declaration - will be defined in Entity.h later
class Entity {
public:
    virtual void update(float deltaTime) {}
    virtual void render() {}
};

Map::Map(int width, int height) : width(width), height(height) {
    // Initialize empty map
    tiles.resize(height, std::vector<std::shared_ptr<Tile>>(width));
    
    // Fill with default empty tiles
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            tiles[y][x] = std::make_shared<Tile>(TileType::EMPTY, true, "empty");
        }
    }
}

Map::~Map() {
    // Clean up if necessary
}

void Map::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open map file: " << filename << std::endl;
        return;
    }
    
    // Read map dimensions
    file >> width >> height;
    
    // Resize grid
    tiles.resize(height, std::vector<std::shared_ptr<Tile>>(width));
    
    // Read map data
    char tileChar;
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            file >> tileChar;
            
            // Convert character to tile type
            switch (tileChar) {
                case '#': // Wall
                    tiles[y][x] = std::make_shared<Tile>(TileType::WALL, false, "wall");
                    break;
                case '.': // Pellet
                    tiles[y][x] = std::make_shared<Tile>(TileType::PELLET, true, "pellet");
                    break;
                case 'O': // Power pellet
                    tiles[y][x] = std::make_shared<Tile>(TileType::POWER_PELLET, true, "power_pellet");
                    break;
                case '-': // Door
                    tiles[y][x] = std::make_shared<Tile>(TileType::DOOR, true, "door");
                    break;
                default: // Empty/floor
                    tiles[y][x] = std::make_shared<Tile>(TileType::FLOOR, true, "floor");
                    break;
            }
        }
    }
    
    file.close();
}

void Map::saveToFile(const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open map file for writing: " << filename << std::endl;
        return;
    }
    
    // Write dimensions
    file << width << " " << height << std::endl;
    
    // Write map data
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            char tileChar = ' ';
            if (tiles[y][x]) {
                switch (tiles[y][x]->getType()) {
                    case TileType::WALL:
                        tileChar = '#';
                        break;
                    case TileType::PELLET:
                        tileChar = '.';
                        break;
                    case TileType::POWER_PELLET:
                        tileChar = 'O';
                        break;
                    case TileType::DOOR:
                        tileChar = '-';
                        break;
                    default:
                        tileChar = ' ';
                        break;
                }
            }
            file << tileChar;
        }
        file << std::endl;
    }
    
    file.close();
}

bool Map::isValidPosition(int x, int y) const {
    return x >= 0 && x < width && y >= 0 && y < height;
}

std::shared_ptr<Tile> Map::getTileAt(int x, int y) const {
    if (!isValidPosition(x, y)) {
        return nullptr;
    }
    return tiles[y][x];
}

void Map::setTileAt(int x, int y, std::shared_ptr<Tile> tile) {
    if (isValidPosition(x, y)) {
        tiles[y][x] = tile;
    }
}

void Map::addEntity(std::shared_ptr<Entity> entity) {
    entities.push_back(entity);
}

void Map::removeEntity(std::shared_ptr<Entity> entity) {
    auto it = std::find(entities.begin(), entities.end(), entity);
    if (it != entities.end()) {
        entities.erase(it);
    }
}

std::vector<std::shared_ptr<Entity>> Map::getEntitiesInArea(int x, int y, int width, int height) {
    std::vector<std::shared_ptr<Entity>> result;
    // This is a placeholder - you'll need to implement proper entity area detection
    // based on your entity class that will have position information
    return result;
}

void Map::update(float deltaTime) {
    for (auto& entity : entities) {
        entity->update(deltaTime);
    }
}

void Map::render() {
    // Render tiles
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            if (tiles[y][x]) {
                tiles[y][x]->render(x, y);
            }
        }
        std::cout << std::endl; // New line after each row
    }
    
    // Render entities - would need to be updated with proper positioning
    for (auto& entity : entities) {
        entity->render();
    }
}