#ifndef REDGHOST_H
#define REDGHOST_H

#include "Ghost.h"

class RedGhost : public Ghost {
public:
    RedGhost(int startX, int startY) : Ghost(startX, startY) {}

    // Override to return the specific icon for RedGhost
    char getIcon() const override {
        return 'R';
    }

    std::string getType() const override {
        return "RedGhost";
    }
};

#endif // REDGHOST_H