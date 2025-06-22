#include "MinecraftInstance.h"
#include "../LogManager.h"
#include "MinecraftComponentUtil.h"

MinecraftInstance::MinecraftInstance() {
    java_vendor = new std::string;
    java_path = new std::string;
    java_version = new std::string;
    jwm_args = new std::string;
    logManager->sendSeparator();
    logManager->sendSuccessLog(std::format("Create minecraft instance: {}", static_cast<void *>(this)));
}

MinecraftInstance::~MinecraftInstance() {
    delete java_vendor;
    delete java_path;
    delete java_version;
    delete jwm_args;
    logManager->sendSeparator();
    logManager->sendSuccessLog(std::format("Destruct minecraft instance: {}", static_cast<void *>(this)));
}

void MinecraftInstance::setComponents(const std::vector<MinecraftComponent *> &_components) {
    components.clear();
    std::string componentsStringRepresentation;
    for (int i = 0; i < _components.size(); i++) {
        auto *component = _components[i];
        components.emplace_back(component);
        componentsStringRepresentation +=
                MinecraftComponentUtil::getStringRepresentationOfMinecraftComponent(*component);
        if (i + 1 < _components.size()) componentsStringRepresentation += ", ";
    }
    logManager->sendInfoLog(
            std::format(
                    "Set minecraft instance ({}) components to: {}",
                    static_cast<void *>(this),
                    componentsStringRepresentation
            )
    );
}

std::vector<MinecraftComponent *> MinecraftInstance::getComponents() {
    return components;
}

bool MinecraftInstance::hasComponents() {
    return !components.empty();
}

void MinecraftInstance::setJavaPath(const std::string &_java_path) {
    *java_path = _java_path;
    logManager->sendInfoLog(
            std::format(
                    "Set minecraft instance ({}) java path to: {}", static_cast<void *>(this), *java_path
            )
    );
}

std::string *MinecraftInstance::getJavaPath() {
    return java_path;
}

bool MinecraftInstance::hasJavaPath() {
    return java_path != nullptr;
}

void MinecraftInstance::setJavaVersion(const std::string &_java_version) {
    *java_version = _java_version;
    logManager->sendInfoLog(
            std::format(
                    "Set minecraft instance ({}) java version to: {}", static_cast<void *>(this), *java_version
            )
    );
}

std::string *MinecraftInstance::getJavaVersion() {
    return java_version;
}

bool MinecraftInstance::hasJavaVersion() {
    return java_version != nullptr;
}

void MinecraftInstance::setJavaVendor(const std::string &_java_vendor) {
    *java_vendor = _java_vendor;
    logManager->sendInfoLog(
            std::format(
                    "Set minecraft instance ({}) java vendor to: {}", static_cast<void *>(this), *java_vendor
            )
    );
}

std::string *MinecraftInstance::getJavaVendor() {
    return java_vendor;
}

bool MinecraftInstance::hasJavaVendor() {
    return java_vendor != nullptr;
}

void MinecraftInstance::setJWMArgs(const std::string &_jwm_args) {
    *jwm_args = _jwm_args;
    logManager->sendInfoLog(
            std::format(
                    "Set minecraft instance ({}) jwm args to: {}", static_cast<void *>(this), *jwm_args
            )
    );
}

bool MinecraftInstance::hasJWMArgs() {
    return jwm_args != nullptr;
}


std::string *MinecraftInstance::getJWMArgs() {
    return jwm_args;
}