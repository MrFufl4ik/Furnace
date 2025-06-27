#include "MinecraftComponent.h"
#include "../console/LogManager.h"

MinecraftComponent::MinecraftComponent() {
    componentUid = new std::string;
    componentVersion = new std::string;
    logManager = LogManager::getInstance();
    logManager->sendSeparator();
    logManager->sendCreateObjectLog(*this);
}

MinecraftComponent::~MinecraftComponent() {
    delete componentUid;
    delete componentVersion;
    logManager->sendSeparator();
    logManager->sendDestructObjectLog(*this);
}

void MinecraftComponent::setUID(const std::string &_component_uid) {
    *componentUid = _component_uid;
    logManager->sendInfoLog(
            std::format("Set minecraft component ({}) uid to: {}", (static_cast<void *>(this)), *componentUid)
    );
}

void MinecraftComponent::setVersion(const std::string &_component_version) {
    *componentVersion = _component_version;
    logManager->sendInfoLog(
            std::format("Set minecraft component ({}) version to {}", (static_cast<void *>(this)), *componentVersion)
    );
}