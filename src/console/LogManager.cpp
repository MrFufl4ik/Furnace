#include "LogManager.h"
#include "ColorHelper.h"
#include "../minecraft/MinecraftInstance.h"

//Standalone

LogManager *LogManager::instance = nullptr;
LogManager *LogManager::getInstance() {
    if (instance == nullptr) if (instance == nullptr) instance = new LogManager();
    return instance;
}

void LogManager::sendInfoLog(const std::string &info_text) {
    const std::string &text_to_log = std::format("[Info] {}", info_text);
    latestLog = text_to_log;
    std::cout << text_to_log << std::endl;
}

void LogManager::sendWarnLog(const std::string &warn_text) {
    const std::string &text_to_log =
            std::format(
                    "{} {}", ColorHelper::colorize("[Warning]", {ColorHelper::FG_YELLOW}), warn_text
            );
    latestLog = text_to_log;
    std::cout << text_to_log << std::endl;
}

void LogManager::sendErrorLog(const std::string &error_text) {
    const std::string &text_to_log =
            std::format(
                    "{} {}", ColorHelper::colorize("[Error]", {ColorHelper::FG_RED}), error_text
            );
    latestLog = text_to_log;
    std::cout << text_to_log << std::endl;
}


void LogManager::sendSuccessLog(const std::string &success_text) {
    const std::string &text_to_log =
            std::format(
                    "{} {}", ColorHelper::colorize("[Success]", {ColorHelper::FG_GREEN}), success_text
            );
    latestLog = text_to_log;
    std::cout << text_to_log << std::endl;
}

void LogManager::sendSeparator() {
    if (latestLog == "\n") return;
    latestLog = "\n";
    std::cout << std::endl;
}

template<typename T>
void LogManager::sendCreateObjectLog(T &obj) {
    const std::string &type_name = typeid(obj).name();
    const std::string &address = std::format("{}", static_cast<const void *>(&obj));
    const std::string &text_to_log = std::format("Create object: {}, with memory address: {}", type_name, address);
    sendSuccessLog(text_to_log);
}

template<typename T>
void LogManager::sendDestructObjectLog(T &obj) {
    const std::string &type_name = typeid(obj).name();
    const std::string &address = std::format("{}", static_cast<const void *>(&obj));
    const std::string &text_to_log = std::format("Destruct object: {}, with memory address: {}", type_name, address);
    sendSuccessLog(text_to_log);
}

template<typename T>
void LogManager::sendChangeValueJsonLog(const nlohmann::json& json, T &obj) {
    const std::string &address = std::format("{}", static_cast<const void *>(&obj));
    const std::string &json_data = JsonUtils::convertJsonToStringRepresentation(json);
    const std::string &text_to_log = std::format("Value of object: {}, changed to: {}", address, json_data);
    sendInfoLog(text_to_log);
}

template void LogManager::sendCreateObjectLog<MinecraftInstance>(MinecraftInstance &obj);
template void LogManager::sendDestructObjectLog<MinecraftInstance>(MinecraftInstance &obj);
template void LogManager::sendChangeValueJsonLog<MinecraftInstance>(const nlohmann::json& json, MinecraftInstance &obj);

template void LogManager::sendCreateObjectLog<MinecraftComponent>(MinecraftComponent &obj);
template void LogManager::sendDestructObjectLog<MinecraftComponent>(MinecraftComponent &obj);
template void LogManager::sendChangeValueJsonLog<MinecraftComponent>(const nlohmann::json& json, MinecraftComponent &obj);