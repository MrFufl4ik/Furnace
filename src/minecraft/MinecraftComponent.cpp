#include "MinecraftComponent.h"
#include "../console/LogManager.h"

MinecraftComponent::MinecraftComponent() {
    uid = new std::string;
    version = new std::string;
    logManager = LogManager::getInstance();
    logManager->sendSeparator();
    logManager->sendCreateObjectLog(*this);
}

MinecraftComponent::~MinecraftComponent() {
    delete uid;
    delete version;
    logManager->sendSeparator();
    logManager->sendDestructObjectLog(*this);
}

void MinecraftComponent::setUID(const std::string &component_uid) {
    *uid = component_uid;
    nlohmann::json json = nlohmann::json();
    json["uid"] = *uid;
    logManager->sendChangeValueJsonLog(json, *this);
}

void MinecraftComponent::setVersion(const std::string &component_version) {
    *version = component_version;
    nlohmann::json json = nlohmann::json();
    json["version"] = *version;
    logManager->sendChangeValueJsonLog(json, *this);
}