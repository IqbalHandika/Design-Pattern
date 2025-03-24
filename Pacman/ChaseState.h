#ifndef CHASE_STATE_H
#define CHASE_STATE_H

#include "GhostState.h"

class ChaseState : public GhostState {
public:
    void move(Ghost& ghost, std::vector<std::vector<char>>& map) override;
};

#endif // CHASE_STATE_H