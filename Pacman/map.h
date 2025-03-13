#pragma once
#include <vector>

const int MAP_WIDTH = 10;
const int MAP_HEIGHT = 10;

void initializeMap(std::vector<std::vector<char>>& map);
void placeCharacterOnMap(std::vector<std::vector<char>>& map, int x, int y, char character);
void renderMap(const std::vector<std::vector<char>>& map);