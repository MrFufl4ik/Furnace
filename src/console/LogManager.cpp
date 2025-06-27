#include "LogManager.h"
#include "ColorHelper.h"

void LogManager::sendInfoLog(std::string info_text) {
    const std::string& textToLog = std::format("[Info] {}", info_text);
    latest_log = textToLog;
    std::cout << textToLog << std::endl;
}

void LogManager::sendWarnLog(std::string warn_text) {
    const std::string& textToLog =
        std::format(
            "{} {}", ColorHelper::colorize("[Warning]", {ColorHelper::FG_YELLOW}), warn_text
        );
    latest_log = textToLog;
    std::cout << textToLog << std::endl;
}

void LogManager::sendErrorLog(std::string error_text) {
    const std::string& textToLog =
        std::format(
            "{} {}", ColorHelper::colorize("[Error]", {ColorHelper::FG_RED}), error_text
        );
    latest_log = textToLog;
    std::cout << textToLog << std::endl;
}


void LogManager::sendSuccessLog(std::string success_text) {
    const std::string& textToLog =
        std::format(
            "{} {}", ColorHelper::colorize("[Success]", {ColorHelper::FG_GREEN}), success_text
        );
    latest_log = textToLog;
    std::cout << textToLog << std::endl;
}

void LogManager::sendSeparator() {
    if (latest_log == "\n") return;
    latest_log = "\n";
    std::cout << std::endl;
}

LogManager::LogManager() = default;
LogManager *LogManager::instance = nullptr;

LogManager *LogManager::getInstance() {
    if (instance == nullptr) if (instance == nullptr) instance = new LogManager();
    return instance;
}

