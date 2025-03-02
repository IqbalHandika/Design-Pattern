#ifndef CHASEBEHAVIOR_H
#define CHASEBEHAVIOR_H

#include "GhostBehavior.h"

class ChaseBehavior : public GhostBehavior {
public:
    void move() override;
};

#endif // CHASEBEHAVIOR_H