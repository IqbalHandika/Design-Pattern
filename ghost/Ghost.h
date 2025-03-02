#ifndef GHOST_H
#define GHOST_H

class GhostBehavior;

class Ghost {
public:
    virtual ~Ghost() {}
    virtual void display() = 0;
    virtual void setBehavior(GhostBehavior* behavior) = 0;
    virtual void performBehavior() = 0;
};

#endif // GHOST_H