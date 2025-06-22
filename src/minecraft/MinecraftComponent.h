#pragma once

#include "iostream"
#include "../LogManager.h"

class MinecraftComponent {
public:
    MinecraftComponent();

    ~MinecraftComponent();

    void setComponentUID(const std::string &_component_uid);
    std::string *getComponentUID();

    void setComponentVersion(const std::string &_component_version);
    std::string *getComponentVersion();

    LogManager *logManager{LogManager::getInstance()};
private:
    std::string *component_uid;
    std::string *component_version;
};