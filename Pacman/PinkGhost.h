#pragma once
#include "Ghost.h"
#include "GhostFactory.h"

class PinkGhost : public Ghost {
public:
    std::string getType() const override {
        return "PinkGhost";
    }
};
