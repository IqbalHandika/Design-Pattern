#include "TimeSystem.h"

// Start a timer with a given name
void TimeSystem::startTimer(const std::string& timerName) {
    timers[timerName] = std::chrono::steady_clock::now();
}

// Check if a timer has expired
bool TimeSystem::isTimerExpired(const std::string& timerName, double durationInSeconds) {
    auto it = timers.find(timerName);
    if (it != timers.end()) {
        auto elapsed = std::chrono::duration<double>(std::chrono::steady_clock::now() - it->second).count();
        return elapsed >= durationInSeconds;
    }
    return false; // Timer not found
}

// Get the elapsed time for a timer
double TimeSystem::getElapsedTime(const std::string& timerName) const {
    auto it = timers.find(timerName);
    if (it != timers.end()) {
        return std::chrono::duration<double>(std::chrono::steady_clock::now() - it->second).count();
    }
    return 0.0; // Timer not found
}

// Reset a timer
void TimeSystem::resetTimer(const std::string& timerName) {
    timers[timerName] = std::chrono::steady_clock::now();
}