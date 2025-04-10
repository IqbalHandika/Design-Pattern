#pragma once
#include "GhostState.h"
#include <memory>

class GhostDecorator : public GhostState {
public:
    GhostDecorator(std::unique_ptr<GhostState> wrappedState)
        : wrappedState(std::move(wrappedState)) {}

    void move(Ghost& ghost, std::vector<std::vector<char>>& map) override {
        wrappedState->move(ghost, map); // Delegate to the wrapped state
    }

protected:
    std::unique_ptr<GhostState> wrappedState; // The wrapped state
};