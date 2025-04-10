#include "GhostFactory.h"
#include "RedGhost.h"
#include "BlueGhost.h"
#include "OrangeGhost.h"
#include "PinkGhost.h"

// Static method to get the singleton instance of GhostFactory
GhostFactory& GhostFactory::getInstance() {
    static GhostFactory instance;
    return instance;
}

// Method to register a ghost type with its creation function
void GhostFactory::registerGhost(const std::string& type, CreateGhostFunc createFunc) {
    ghostCreators[type] = createFunc;
}

// Method to create a ghost based on the type
std::unique_ptr<Ghost> GhostFactory::createGhost(const std::string& type) {
    auto it = ghostCreators.find(type);
    if (it != ghostCreators.end()) {
        return it->second();
    }
    return nullptr;
}

// Function to register all ghost types
void registerGhosts() {
    GhostFactory::getInstance().registerGhost("RedGhost", []() { return std::make_unique<RedGhost>(0, 0); });
    GhostFactory::getInstance().registerGhost("BlueGhost", []() { return std::make_unique<BlueGhost>(0, 0); });
    GhostFactory::getInstance().registerGhost("OrangeGhost", []() { return std::make_unique<OrangeGhost>(0, 0); });
    GhostFactory::getInstance().registerGhost("PinkGhost", []() { return std::make_unique<PinkGhost>(0, 0); });
}