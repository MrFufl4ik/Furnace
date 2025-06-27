#pragma once
#ifndef FURNACE_MINECRAFT_INSTANCE_H
#define FURNACE_MINECRAFT_INSTANCE_H

#include "iostream"
#include "vector"
#include "MinecraftComponent.h"

class MinecraftInstance {
private:
    std::vector<MinecraftComponent *> components;
    std::string *javaPath{nullptr};
    std::string *javaVersion{nullptr};
    std::string *javaVendor{nullptr};
    std::string *jwwArgs{nullptr};

    LogManager *logManager{LogManager::getInstance()};

public:
    MinecraftInstance();
    ~MinecraftInstance();

    void setComponents(const std::vector<MinecraftComponent *> &_components);
    std::vector<MinecraftComponent *> getComponents() {return components; };
    bool hasComponents() { return !components.empty(); };

    void setJavaPath(const std::string &_java_path);
    std::string getJavaPath() { return *javaPath; };
    bool hasJavaPath() { return javaPath != nullptr; };

    void setJavaVersion(const std::string &_java_version);
    std::string getJavaVersion() { return *javaVersion; };
    bool hasJavaVersion() { return javaVersion != nullptr; };

    void setJavaVendor(const std::string &_java_vendor);
    std::string getJavaVendor() { return *javaVendor; };
    bool hasJavaVendor() { return javaVendor != nullptr; };

    void setJWMArgs(const std::string &_jwm_args);
    std::string getJWMArgs() { return *jwwArgs; };
    bool hasJWMArgs() { return jwwArgs != nullptr; };
};

#endif //FURNACE_MINECRAFT_INSTANCE_H