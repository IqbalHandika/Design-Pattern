#pragma once
#include <string>

enum class TileType {
    EMPTY,
    WALL,
    FLOOR,
    DOOR,
    PELLET,
    POWER_PELLET,
    // Add more tile types as needed
};

class Tile {
private:
    TileType type;
    bool walkable;
    std::string textureId;
    
public:
    Tile(TileType type, bool walkable, const std::string& textureId);
    virtual ~Tile() = default;
    
    TileType getType() const { return type; }
    bool isWalkable() const { return walkable; }
    std::string getTextureId() const { return textureId; }
    
    virtual void render(int x, int y);
    virtual void onEntityEnter(class Entity* entity) {}
    virtual void onEntityLeave(class Entity* entity) {}
};