#ifndef GHOST_STATE_H
#define GHOST_STATE_H

#include <vector>

class Ghost;

class GhostState {
public:
    virtual ~GhostState() = default;
    virtual void move(Ghost& ghost, std::vector<std::vector<char>>& map) = 0;
};

#endif // GHOST_STATE_H