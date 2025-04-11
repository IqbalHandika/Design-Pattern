#pragma once
#include "Ghost.h"
#include "GhostFactory.h"

class PinkGhost : public Ghost {
public:
    // Constructor that calls the base class constructor
    PinkGhost(int startX, int startY) : Ghost(startX, startY) {}

    char getIcon() const override {
        return 'P';
    }

    // Override the getType method
    std::string getType() const override {
        return "PinkGhost";
    }
};