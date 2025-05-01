#include "../include/Tile.h"
#include <iostream> // For console rendering - replace with your graphics library

Tile::Tile(TileType type, bool walkable, const std::string& textureId)
    : type(type), walkable(walkable), textureId(textureId) {
}

void Tile::render(int x, int y) {
    // For console-based rendering - replace with your actual rendering code
    char symbol = ' ';
    
    switch (type) {
        case TileType::WALL:
            symbol = '#';
            break;
        case TileType::FLOOR:
            symbol = ' ';
            break;
        case TileType::PELLET:
            symbol = '.';
            break;
        case TileType::POWER_PELLET:
            symbol = 'O';
            break;
        case TileType::DOOR:
            symbol = '-';
            break;
        default:
            symbol = ' ';
            break;
    }
    
    // For now, just print to console for debugging
    // In a real game, you would draw a sprite or texture here
    std::cout << symbol;
}