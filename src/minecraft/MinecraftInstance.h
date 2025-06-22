#pragma once

#include "iostream"
#include "vector"
#include "MinecraftComponent.h"

class MinecraftInstance {
private:
    std::vector<MinecraftComponent *> components;
    std::string *java_path;
    std::string *java_version;
    std::string *java_vendor;
    std::string *jwm_args;

    LogManager *logManager{LogManager::getInstance()};

public:
    MinecraftInstance();
    ~MinecraftInstance();

    void setComponents(const std::vector<MinecraftComponent *> &_components);
    std::vector<MinecraftComponent *> getComponents();
    bool hasComponents();

    void setJavaPath(const std::string &_java_path);
    std::string *getJavaPath();
    bool hasJavaPath();

    void setJavaVersion(const std::string &_java_version);
    std::string *getJavaVersion();
    bool hasJavaVersion();

    void setJavaVendor(const std::string &_java_vendor);
    std::string *getJavaVendor();
    bool hasJavaVendor();

    void setJWMArgs(const std::string &_jwm_args);
    std::string *getJWMArgs();
    bool hasJWMArgs();
};