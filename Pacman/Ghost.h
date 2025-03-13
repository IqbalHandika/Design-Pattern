#pragma once
#include <string>

// Base class for Ghosts
class Ghost {
public:
    virtual ~Ghost() = default;
    virtual std::string getType() const = 0;
};

// Derived classes for each type of Ghost
class RedGhost : public Ghost {
public:
    std::string getType() const override {
        return "RedGhost";
    }
};

class BlueGhost : public Ghost {
public:
    std::string getType() const override {
        return "BlueGhost";
    }
};

