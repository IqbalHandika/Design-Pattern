#ifndef RETURN_TO_BASE_STATE_H
#define RETURN_TO_BASE_STATE_H

#include "GhostState.h"

class ReturnToBaseState : public GhostState {
public:
    void move(Ghost& ghost, std::vector<std::vector<char>>& map) override;
};

#endif // RETURN_TO_BASE_STATE_H