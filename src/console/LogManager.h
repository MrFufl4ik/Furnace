#pragma once
#ifndef FURNACE_LOG_MANAGER_H
#define FURNACE_LOG_MANAGER_H


#include "iostream"
#include "../metadata/MetaDataAssetIndex.h"
#include "../metadata/MetaDataLibrary.h"
#include "../../libs/json.hpp"
#include "../json/JsonUtils.h"

class JsonUtils;

class LogManager {
private:
    static LogManager *instance;
    LogManager() = default;

    std::string latestLog;
public:
    void sendInfoLog(const std::string &info_text);
    void sendWarnLog(const std::string &warn_text);
    void sendErrorLog(const std::string &error_text);
    void sendSuccessLog(const std::string &success_text);
    void sendSeparator();

    //object

    template<typename T> void sendCreateObjectLog(T &obj);
    template<typename T> void sendDestructObjectLog(T &obj);
    template<typename T> void sendChangeValueJsonLog(const nlohmann::json& json, T &obj);

    static LogManager* getInstance();

    LogManager(const LogManager&) = delete;
    LogManager &operator=(const LogManager&) = delete;
};

#endif //FURNACE_LOG_MANAGER_H