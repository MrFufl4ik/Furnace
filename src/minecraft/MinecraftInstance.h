#pragma once
#ifndef FURNACE_MINECRAFT_INSTANCE_H
#define FURNACE_MINECRAFT_INSTANCE_H

#include "iostream"
#include "vector"
#include "MinecraftComponent.h"

class MinecraftInstance {
private:
    std::vector<MinecraftComponent *> components;
    std::string *java_path{nullptr};
    std::string *java_version{nullptr};
    std::string *java_vendor{nullptr};
    std::string *jwm_args{nullptr};

    LogManager *logManager{LogManager::getInstance()};

public:
    MinecraftInstance();
    ~MinecraftInstance();

    void setComponents(const std::vector<MinecraftComponent *> &_components);
    std::vector<MinecraftComponent *> getComponents() {return components; };
    bool hasComponents() { return !components.empty(); };

    void setJavaPath(const std::string &_java_path);
    std::string getJavaPath() { return *java_path; };
    bool hasJavaPath() { return java_path != nullptr; };

    void setJavaVersion(const std::string &_java_version);
    std::string getJavaVersion() { return *java_version; };
    bool hasJavaVersion() { return java_version != nullptr; };

    void setJavaVendor(const std::string &_java_vendor);
    std::string getJavaVendor() { return *java_vendor; };
    bool hasJavaVendor() { return java_vendor != nullptr; };

    void setJWMArgs(const std::string &_jwm_args);
    std::string getJWMArgs() { return *jwm_args; };
    bool hasJWMArgs() { return jwm_args != nullptr; };
};

#endif //FURNACE_MINECRAFT_INSTANCE_H