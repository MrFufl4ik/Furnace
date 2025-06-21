#include "LogManager.h"
#include "ColorHelper.h"

void LogManager::sendInfoLog(std::string info_text) {
    std::cout << std::format("[Info] {}", info_text) << std::endl;
}

void LogManager::sendWarnLog(std::string warn_text) {
    std::cout <<
        std::format(
            "{} {}", ColorHelper::colorize("[Warning]", {ColorHelper::FG_YELLOW}), warn_text
        )
        << std::endl;
}

void LogManager::sendErrorLog(std::string error_text) {
    std::cout <<
        std::format(
            "{} {}", ColorHelper::colorize("[Error]", {ColorHelper::FG_RED}), error_text
        )
        << std::endl;
}


void LogManager::sendSuccessLog(std::string success_text) {
    std::cout <<
        std::format(
            "{} {}", ColorHelper::colorize("[Success]", {ColorHelper::FG_GREEN}), success_text
        )
        << std::endl;
}

void LogManager::sendSeparator() {
    std::cout << std::endl;
}