#include "MinecraftInstance.h"

MinecraftInstance::MinecraftInstance() {
    logManager->sendSeparator();
    logManager->sendCreateObjectLog(*this);
}

MinecraftInstance::~MinecraftInstance() {
    logManager->sendSeparator();
    logManager->sendDestructObjectLog(*this);
}

void MinecraftInstance::setComponents(const std::vector<MinecraftComponent *> &components) {
    this->components.clear();
    for (auto component : components) this->components.emplace_back(component);
    nlohmann::json json = nlohmann::json();
    json["components"] = {};
    for (auto component: this->components)
        json["components"].emplace_back(JsonUtils::convertMinecraftComponentToJson(*component));
    logManager->sendChangeValueJsonLog(json, *this);
}

void MinecraftInstance::setJavaPath(const std::string &_java_path) {
    if (java_path == nullptr) java_path = new std::string;
    *java_path = _java_path;
    nlohmann::json json = nlohmann::json();
    json["java_path"] = *java_path;
    logManager->sendChangeValueJsonLog(json, *this);
}

void MinecraftInstance::setJavaVersion(const std::string &_java_version) {
    if (java_version == nullptr) java_version = new std::string;
    *java_version = _java_version;
    nlohmann::json json = nlohmann::json();
    json["java_version"] = *java_version;
    logManager->sendChangeValueJsonLog(json, *this);
}
void MinecraftInstance::setJavaVendor(const std::string &_java_vendor) {
    if (java_vendor == nullptr) java_vendor = new std::string;
    *java_vendor = _java_vendor;
    nlohmann::json json = nlohmann::json();
    json["java_vendor"] = *java_vendor;
    logManager->sendChangeValueJsonLog(json, *this);
}
void MinecraftInstance::setJWMArgs(const std::string &_jwm_args) {
    if (jwm_args == nullptr) jwm_args = new std::string;
    *jwm_args = _jwm_args;
    nlohmann::json json = nlohmann::json();
    json["jwm_args"] = *jwm_args;
    logManager->sendChangeValueJsonLog(json, *this);
}