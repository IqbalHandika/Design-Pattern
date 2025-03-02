#ifndef GHOSTFACTORY_H
#define GHOSTFACTORY_H

#include "ghost/Ghost.h"

class GhostFactory {
public:
    virtual ~GhostFactory() {}
    virtual Ghost* createGhost() = 0;
};

#endif // GHOSTFACTORY_H