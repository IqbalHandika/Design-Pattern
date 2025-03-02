#ifndef PACMAN_H
#define PACMAN_H

class Map;

class Pacman {
private:
    int x, y; // posisi Pacman
public:
    Pacman(int startX, int startY);
    void move(char direction, Map& map);
    int getX() const;
    int getY() const;
};

#endif // PACMAN_H