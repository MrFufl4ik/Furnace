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

std::filesystem::path OperatingSystemManager::getPrismLauncherDirectory() {
    try {
#ifdef _WIN32
        // Windows: Get AppData/Roaming path
        wchar_t* roamingPath = nullptr;
        if (SHGetKnownFolderPath(FOLDERID_RoamingAppData, 0, nullptr, &roamingPath) != S_OK) {
            return {};
        }

        std::filesystem::path prismPath = fs::path(roamingPath) / "PrismLauncher";
        CoTaskMemFree(roamingPath);
        return prismPath;

#elif defined(__linux__)
        // Linux: Get $HOME/.local/share path
        const char* homeDir = getenv("HOME");
        if (!homeDir) {
            homeDir = getpwuid(getuid())->pw_dir;
            if (!homeDir) {
                return {};
            }
        }

        return std::filesystem::path(homeDir) / ".local" / "share" / "PrismLauncher";

#else
#error "Unsupported platform"
#endif
    } catch (...) {
        return {};
    }
}