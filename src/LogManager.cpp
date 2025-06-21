#include "LogManager.h"

LogManager::LogManager() = default;

LogManager *LogManager::getInstance() {
    if (instance == nullptr)
        if (instance == nullptr)
            instance == new LogManager();
    return instance;
}

void LogManager::sendInfoLog(std::string info_text) {
    std::cout << std::format("[Info] {}.", info_text);
}

void LogManager::sendErrorLog(std::string error_text) {
    std::cout << std::format("[Error] {}.", error_text);
}

void LogManager::sendSuccessLog(std::string success_text) {
    std::cout << std::format("[Success] {}.", success_text);
}

