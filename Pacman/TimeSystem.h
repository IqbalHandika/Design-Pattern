#pragma once
#include <chrono>
#include <unordered_map>
#include <string>

class TimeSystem {
public:
    // Start a timer with a given name
    void startTimer(const std::string& timerName);

    // Check if a timer has expired
    bool isTimerExpired(const std::string& timerName, double durationInSeconds);

    // Get the elapsed time for a timer
    double getElapsedTime(const std::string& timerName) const;

    // Reset a timer
    void resetTimer(const std::string& timerName);

private:
    // Store the start time of each timer
    std::unordered_map<std::string, std::chrono::steady_clock::time_point> timers;
};