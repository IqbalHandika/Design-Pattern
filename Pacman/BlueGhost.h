#pragma once
#include "Ghost.h"
#include "GhostFactory.h"

class BlueGhost : public Ghost {
public:
    // Constructor that calls the base class constructor
    BlueGhost(int startX, int startY) : Ghost(startX, startY) {}

    // Override the getType method
    std::string getType() const override {
        return "BlueGhost";
    }
};