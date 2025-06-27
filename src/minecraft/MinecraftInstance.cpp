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
    if (javaPath == nullptr) javaPath = new std::string;
    *javaPath = _java_path;
    nlohmann::json json = nlohmann::json();
    json["java_path"] = *javaPath;
    logManager->sendChangeValueJsonLog(json, *this);
}

void MinecraftInstance::setJavaVersion(const std::string &_java_version) {
    if (javaVersion == nullptr) javaVersion = new std::string;
    *javaVersion = _java_version;
    nlohmann::json json = nlohmann::json();
    json["java_version"] = *javaVersion;
    logManager->sendChangeValueJsonLog(json, *this);
}
void MinecraftInstance::setJavaVendor(const std::string &_java_vendor) {
    if (javaVendor == nullptr) javaVendor = new std::string;
    *javaVendor = _java_vendor;
    nlohmann::json json = nlohmann::json();
    json["java_vendor"] = *javaVendor;
    logManager->sendChangeValueJsonLog(json, *this);
}
void MinecraftInstance::setJWMArgs(const std::string &_jwm_args) {
    if (jwwArgs == nullptr) jwwArgs = new std::string;
    *jwwArgs = _jwm_args;
    nlohmann::json json = nlohmann::json();
    json["jwm_args"] = *jwwArgs;
    logManager->sendChangeValueJsonLog(json, *this);
}