#pragma once
#include <string>

// Base class for Ghosts
class Ghost {
public:
    virtual ~Ghost() = default;
    virtual std::string getType() const = 0;
};