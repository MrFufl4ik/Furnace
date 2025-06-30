#pragma once
#ifndef FURNACE_MINECRAFT_COMPONENT_H
#define FURNACE_MINECRAFT_COMPONENT_H

#include "iostream"
#include "../console/LogManager.h"

class LogManager;

class MinecraftComponent {
private:
    std::string *uid;
    std::string *version;
public:
    MinecraftComponent();
    ~MinecraftComponent();

    void setUID(const std::string &component_uid);
    [[nodiscard]] const std::string &getUid() const { return *uid; };
    [[nodiscard]] bool hasUid() const { return uid != nullptr; };

    void setVersion(const std::string &component_version);
    [[nodiscard]] const std::string &getVersion() const { return *version; };
    [[nodiscard]] bool hasVersion() const { return version != nullptr; };

    LogManager *logManager;
};

#endif //FURNACE_MINECRAFT_COMPONENT_H