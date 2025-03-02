#ifndef MAP_H
#define MAP_H

class Map {
private:
    static const int width = 10;
    static const int height = 10;
    char grid[height][width];
public:
    Map();
    void display() const;
    bool isValidMove(int x, int y) const;
    void placePacman(int x, int y);
};

#endif // MAP_H