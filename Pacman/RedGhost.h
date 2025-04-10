#pragma once
#include "Ghost.h"
#include "GhostFactory.h"

class RedGhost : public Ghost {
public:
    // Constructor that calls the base class constructor
    RedGhost(int startX, int startY) : Ghost(startX, startY) {}

    // Override the getType method
    std::string getType() const override {
        return "RedGhost";
    }
};