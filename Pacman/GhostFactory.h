#pragma once
#include "ghost.h"
#include <memory>
#include <string>
#include <unordered_map>
#include <functional>

// Factory class for creating Ghosts
class GhostFactory {
public:
    using CreateGhostFunc = std::function<std::unique_ptr<Ghost>()>;

    static GhostFactory& getInstance();

    void registerGhost(const std::string& type, CreateGhostFunc createFunc);

    std::unique_ptr<Ghost> createGhost(const std::string& type);

private:
    GhostFactory() = default;
    std::unordered_map<std::string, CreateGhostFunc> ghostCreators;
};

// Helper macros to register ghost types
#define REGISTER_GHOST_TYPE(TYPE) \
    GhostFactory::getInstance().registerGhost(#TYPE, []() { return std::unique_ptr<Ghost>(new TYPE()); })

// Register ghost types
void registerGhosts();