#ifndef GHOSTBEHAVIOR_H
#define GHOSTBEHAVIOR_H

class GhostBehavior {
public:
    virtual ~GhostBehavior() {}
    virtual void move() = 0;
};

#endif // GHOSTBEHAVIOR_H