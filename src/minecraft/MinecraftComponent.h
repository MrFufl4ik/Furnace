#pragma once
#ifndef FURNACE_MINECRAFT_COMPONENT_H
#define FURNACE_MINECRAFT_COMPONENT_H

#include "iostream"
#include "../console/LogManager.h"

class LogManager;

class MinecraftComponent {
public:
    MinecraftComponent();
    ~MinecraftComponent();

    void setUID(const std::string &component_uid);
    std::string *getUID() const { return componentUid; };

    void setVersion(const std::string &component_version);
    std::string *getVersion() const { return componentVersion; };

    LogManager *logManager;
private:
    std::string *componentUid;
    std::string *componentVersion;
};

#endif //FURNACE_MINECRAFT_COMPONENT_H