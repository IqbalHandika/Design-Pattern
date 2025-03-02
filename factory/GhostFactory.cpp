#include "GhostFactory.h"
#include "ghost/RedGhost.h"
#include "ghost/BlueGhost.h"

class RedGhostFactory : public GhostFactory {
public:
    Ghost* createGhost() override {
        return new RedGhost();
    }
};

class BlueGhostFactory : public GhostFactory {
public:
    Ghost* createGhost() override {
        return new BlueGhost();
    }
};