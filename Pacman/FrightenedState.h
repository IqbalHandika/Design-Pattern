#ifndef FRIGHTENED_STATE_H
#define FRIGHTENED_STATE_H

#include "GhostState.h"

class FrightenedState : public GhostState {
public:
    void move(Ghost& ghost, std::vector<std::vector<char>>& map) override;
};

#endif // FRIGHTENED_STATE_H