#include "OperatingSystemManager.h"

//Standalone

OperatingSystemManager *OperatingSystemManager::instance = nullptr;
OperatingSystemManager *OperatingSystemManager::getInstance() {
    if (instance == nullptr) if (instance == nullptr) instance = new OperatingSystemManager();
    return instance;
}

std::filesystem::path OperatingSystemManager::getExecutablePath() {
#ifdef _WIN32
    wchar_t path[MAX_PATH] = { 0 };
        GetModuleFileNameW(nullptr, path, MAX_PATH);
        return fs::path(path);
#elif defined(__linux__)
    char result[PATH_MAX];
    ssize_t count = readlink("/proc/self/exe", result, PATH_MAX);
    return std::filesystem::path(std::string(result, (count > 0) ? count : 0));
    #else
        #error "Unsupported platform"
#endif
}

std::filesystem::path OperatingSystemManager::getExecutableDirectory() {
    try {
#ifdef _WIN32
        wchar_t path[MAX_PATH] = { 0 };
            GetModuleFileNameW(nullptr, path, MAX_PATH);
            return fs::path(path).parent_path();
#elif defined(__linux__)
        char result[PATH_MAX];
        ssize_t count = readlink("/proc/self/exe", result, PATH_MAX);
        return std::filesystem::path(std::string(result, (count > 0) ? count : 0)).parent_path();
        #else
            #error "Unsupported platform"
#endif
    } catch (...) {
        return {};
    }
}