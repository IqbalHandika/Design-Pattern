#ifndef GHOST_STATE_H
#define GHOST_STATE_H

#include <vector>

class Ghost;

class GhostState {
public:
    virtual ~GhostState() = default;
    virtual void move(Ghost& ghost, std::vector<std::vector<char>>& map) = 0;
protected:
    std::pair<int, int> getNextPosition(Ghost& ghost, int dx, int dy, const std::vector<std::vector<char>>& map);
};

#endif // GHOST_STATE_H