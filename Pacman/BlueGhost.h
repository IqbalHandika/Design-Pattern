#pragma once
#include "Ghost.h"
#inlcude "GhostFactory.h"

class BlueGhost : public Ghost {
public:
    std::string getType() const override {
        return "BlueGhost";
    }
};
