#ifndef SPEEDBOOSTDECORATOR_H
#define SPEEDBOOSTDECORATOR_H

#include "GhostDecorator.h"

class SpeedBoostDecorator : public GhostDecorator {
public:
    SpeedBoostDecorator(Ghost* ghost);
    void display() override;
    void performBehavior() override;
};

#endif // SPEEDBOOSTDECORATOR_H