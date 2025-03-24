#pragma once
#include "Ghost.h"
#include "GhostFactory.h"

class OrangeGhost : public Ghost {
public:
    std::string getType() const override {
        return "OrangeGhost";
    }
};
