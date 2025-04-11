#ifndef GHOST_H
#define GHOST_H

#include "GhostState.h"
#include "TimeSystem.h"
#include <memory>
#include <string>
#include <thread>
#include <atomic>

// Base class for Ghosts
class Ghost {
public:
    virtual ~Ghost();
    Ghost(int startX, int startY);

    void setState(std::unique_ptr<GhostState> newState);
    void move(std::vector<std::vector<char>>& map);
    int getX() const;
    int getY() const;
    void setPosition(int newX, int newY);

    // Update the ghost's state based on the timer
    void updateState();

    // Start the ghost's movement thread
    void startMovement(std::vector<std::vector<char>>& map);

    // Stop the ghost's movement thread
    void stopMovement();

    // Existing functionality
    virtual std::string getType() const = 0;

    virtual char getIcon() const = 0;


private:
    int x;
    int y;
    std::unique_ptr<GhostState> state;
    TimeSystem timeSystem; // Timer for managing state transitions

    std::thread movementThread; // Thread for real-time movement
    std::atomic<bool> running;  // Flag to control the thread
};

#endif // GHOST_H