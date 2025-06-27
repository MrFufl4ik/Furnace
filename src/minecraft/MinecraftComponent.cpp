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

void MinecraftComponent::setUID(const std::string &component_uid) {
    *componentUid = component_uid;
    nlohmann::json json = nlohmann::json();
    json["uid"] = *componentUid;
    logManager->sendChangeValueJsonLog(json, *this);
}

void MinecraftComponent::setVersion(const std::string &component_version) {
    *componentVersion = component_version;
    nlohmann::json json = nlohmann::json();
    json["version"] = *componentVersion;
    logManager->sendChangeValueJsonLog(json, *this);
}