#include "MinecraftComponent.h"
#include "../console/LogManager.h"

MinecraftComponent::MinecraftComponent() {
    component_uid = new std::string;
    component_version = new std::string;
    logManager->sendSeparator();
    logManager->sendSuccessLog(std::format("Create minecraft component: {}", static_cast<void *>(this)));
}

MinecraftComponent::~MinecraftComponent() {
    delete component_uid;
    delete component_version;
    logManager->sendSeparator();
    logManager->sendSuccessLog(std::format("Destruct minecraft component: {}", static_cast<void *>(this)));
}

void MinecraftComponent::setComponentUID(const std::string &_component_uid) {
    *component_uid = _component_uid;
    logManager->sendInfoLog(
            std::format("Set minecraft component ({}) uid to: {}", (static_cast<void *>(this)), *component_uid)
    );
}

std::string *MinecraftComponent::getComponentUID() { return component_uid; }

void MinecraftComponent::setComponentVersion(const std::string &_component_version) {
    *component_version = _component_version;
    logManager->sendInfoLog(
            std::format("Set minecraft component ({}) version to {}", (static_cast<void *>(this)), *component_version)
    );
}

std::string *MinecraftComponent::getComponentVersion() { return component_version; }
