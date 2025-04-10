#pragma once
#include "GhostDecorator.h"

class SpeedBoostDecorator : public GhostDecorator {
public:
    SpeedBoostDecorator(std::unique_ptr<GhostState> wrappedState)
        : GhostDecorator(std::move(wrappedState)) {}

    void move(Ghost& ghost, std::vector<std::vector<char>>& map) override {
        // Call the wrapped state's move method twice to simulate increased speed
        wrappedState->move(ghost, map);
        wrappedState->move(ghost, map);
    }
};