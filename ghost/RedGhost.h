#ifndef REDGHOST_H
#define REDGHOST_H

#include "Ghost.h"
#include "GhostBehavior.h"

class RedGhost : public Ghost {
private:
    GhostBehavior* behavior;
public:
    RedGhost();
    ~RedGhost();
    void display() override;
    void setBehavior(GhostBehavior* behavior) override;
    void performBehavior() override;
};

#endif // REDGHOST_H