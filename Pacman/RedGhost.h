#pragma once
#include "Ghost.h"
#include "GhostFactory.h"

class RedGhost : public Ghost {
public:
    std::string getType() const override {
        return "RedGhost";
    }
};
