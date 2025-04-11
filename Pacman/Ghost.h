#ifndef GHOST_H
#define GHOST_H

#include "GhostState.h"
#include "TimeSystem.h"
#include <memory>
#include <string>

// Base class for Ghosts
class Ghost {
public:
    virtual ~Ghost() = default; // Keep the virtual destructor for polymorphism

    // Add new functionality
    Ghost(int startX, int startY);
    void setState(std::unique_ptr<GhostState> newState);
    void move(std::vector<std::vector<char>>& map);
    int getX() const;
    int getY() const;
    void setPosition(int newX, int newY);

    // Update the ghost's state based on the timer
    void updateState();

    // Existing functionality
    virtual std::string getType() const = 0;

private:
    int x;
    int y;
    std::unique_ptr<GhostState> state;
    TimeSystem timeSystem; // Timer for managing state transitions
};

#endif // GHOST_H