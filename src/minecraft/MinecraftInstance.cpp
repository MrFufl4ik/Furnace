#include "MinecraftInstance.h"
#include "../console/LogManager.h"
#include "MinecraftComponentUtil.h"

MinecraftInstance::MinecraftInstance() {
    logManager->sendSeparator();
    logManager->sendCreateObjectLog(*this);
}

MinecraftInstance::~MinecraftInstance() {
    logManager->sendSeparator();
    logManager->sendDestructObjectLog(*this);
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

void MinecraftInstance::setJavaPath(const std::string &_java_path) {
    if (java_path == nullptr) java_path = new std::string;
    *java_path = _java_path;
    logManager->sendInfoLog(
            std::format(
                    "Set minecraft instance ({}) java path to: {}", static_cast<void *>(this), *java_path
            )
    );
}

void MinecraftInstance::setJavaVersion(const std::string &_java_version) {
    if (java_version == nullptr) java_version = new std::string;
    *java_version = _java_version;
    logManager->sendInfoLog(
            std::format(
                    "Set minecraft instance ({}) java version to: {}", static_cast<void *>(this), *java_version
            )
    );
}
void MinecraftInstance::setJavaVendor(const std::string &_java_vendor) {
    if (java_vendor == nullptr) java_vendor = new std::string;
    *java_vendor = _java_vendor;
    logManager->sendInfoLog(
            std::format(
                    "Set minecraft instance ({}) java vendor to: {}", static_cast<void *>(this), *java_vendor
            )
    );
}
void MinecraftInstance::setJWMArgs(const std::string &_jwm_args) {
    if (jwm_args == nullptr) jwm_args = new std::string;
    *jwm_args = _jwm_args;
    logManager->sendInfoLog(
            std::format(
                    "Set minecraft instance ({}) jwm args to: {}", static_cast<void *>(this), *jwm_args
            )
    );
}