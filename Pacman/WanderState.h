#ifndef WANDER_STATE_H
#define WANDER_STATE_H

#include "GhostState.h"

class WanderState : public GhostState {
public:
    void move(Ghost& ghost, std::vector<std::vector<char>>& map) override;
};

#endif // WANDER_STATE_H