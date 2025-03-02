#ifndef BlueGHOST_H
#define BlueGHOST_H

#include "Ghost.h"
#include "GhostBehavior.h"

class BlueGhost : public Ghost {
private:
    GhostBehavior* behavior;
public:
    BlueGhost();
    ~BlueGhost();
    void display() override;
    void setBehavior(GhostBehavior* behavior) override;
    void performBehavior() override;
};

#endif // BlueGHOST_H