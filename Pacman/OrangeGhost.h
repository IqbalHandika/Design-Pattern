#pragma once
#include "Ghost.h"
#include "GhostFactory.h"

class OrangeGhost : public Ghost {
public:
    // Constructor that calls the base class constructor
    OrangeGhost(int startX, int startY) : Ghost(startX, startY) {}

    char getIcon() const override {
        return 'O';
    }

    // Override the getType method
    std::string getType() const override {
        return "OrangeGhost";
    }
};