#ifndef BLUEGHOST_H
#define BLUEGHOST_H

#include "Ghost.h"

class BlueGhost : public Ghost {
public:
    BlueGhost(int startX, int startY) : Ghost(startX, startY) {}

    // Override to return the specific icon for BlueGhost
    char getIcon() const override {
        return 'B';
    }

    std::string getType() const override {
        return "BlueGhost";
    }
};

#endif // BLUEGHOST_H