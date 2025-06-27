#pragma once
#ifndef FURNACE_INSTANCE_MANAGER_H
#define FURNACE_INSTANCE_MANAGER_H


#include "MinecraftInstance.h"
#include "../metadata/MetaDataHelper.h"
#include "filesystem"

class MinecraftInstanceManager {
private:
    static MinecraftInstanceManager *instance;
    MinecraftInstanceManager();
    ~MinecraftInstanceManager();

    LogManager *log_manager{LogManager::getInstance()};
public:
    int runMinecraftInstance(MinecraftInstance &minecraftInstance);
    void stopMinecraftInstance(MinecraftInstance &minecraftInstance);

    bool validateLibraries(std::vector<std::string> libraries, std::string libraries_root);
    std::string convertLibrariesToStringRepresentation(std::vector<std::string> libraries, std::string libraries_root);

    static MinecraftInstanceManager *getInstance();

    MinecraftInstanceManager(const MinecraftInstanceManager &) = delete;
    MinecraftInstanceManager &operator=(const MinecraftInstanceManager &) = delete;
};

#endif //FURNACE_INSTANCE_MANAGER_H