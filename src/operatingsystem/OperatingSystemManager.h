#pragma once

#include "../console/LogManager.h"
#include <filesystem>

#ifdef _WIN32
#include <windows.h>
#elif defined(__linux__)
#include <unistd.h>
#include <limits.h>
#endif

class OperatingSystemManager {
private:
    static OperatingSystemManager *instance;
    OperatingSystemManager() = default;

    LogManager *log_manager{LogManager::getInstance()};
public:
    static OperatingSystemManager *getInstance();


    std::filesystem::path getExecutablePath();
    std::filesystem::path getExecutableDirectory();

    OperatingSystemManager(const OperatingSystemManager &) = delete;
    OperatingSystemManager &operator=(const OperatingSystemManager &) = delete;
};