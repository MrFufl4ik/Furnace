#pragma once

#include "MinecraftInstance.h"

class MinecraftInstanceManager{
private:
    static MinecraftInstanceManager *instance;
    MinecraftInstanceManager();

    LogManager *logManager{LogManager::getInstance()};
public:
    int runMinecraftInstance(MinecraftInstance minecraftInstance);
    void stopMinecraftInstance(MinecraftInstance minecraftInstance);

    static MinecraftInstanceManager* getInstance();

    MinecraftInstanceManager(const MinecraftInstanceManager&) = delete;
    MinecraftInstanceManager &operator=(const MinecraftInstanceManager&) = delete;
};
