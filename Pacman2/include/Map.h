#pragma once
#include <vector>
#include <string>
#include <memory>
#include <unordered_map>
#include <algorithm>

// Forward declarations
class Entity;
class Tile;

class Map {
private:
    int width;
    int height;
    std::vector<std::vector<std::shared_ptr<Tile>>> tiles;
    std::vector<std::shared_ptr<Entity>> entities;
    
public:
    Map(int width, int height);
    ~Map();
    
    // Basic map operations
    void loadFromFile(const std::string& filename);
    void saveToFile(const std::string& filename);
    
    // Tile management
    std::shared_ptr<Tile> getTileAt(int x, int y) const;
    void setTileAt(int x, int y, std::shared_ptr<Tile> tile);
    bool isValidPosition(int x, int y) const;
    
    // Entity management
    void addEntity(std::shared_ptr<Entity> entity);
    void removeEntity(std::shared_ptr<Entity> entity);
    std::vector<std::shared_ptr<Entity>> getEntitiesInArea(int x, int y, int width, int height);
    
    // Getters
    int getWidth() const { return width; }
    int getHeight() const { return height; }
    
    // Rendering
    void render();
    
    // Update all entities on map
    void update(float deltaTime);
};