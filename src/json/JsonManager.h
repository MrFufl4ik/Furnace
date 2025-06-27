#pragma once
#include <fstream>
#include "../../libs/json.hpp"
#include "../console/LogManager.h"

class JsonManager {
private:
    static JsonManager *instance;
    JsonManager() = default;

    LogManager *log_manager{LogManager::getInstance()};
public:
    nlohmann::json readJsonFile(const std::string &file_path);
    std::string convertJsonToStringRepresentation(nlohmann::json json);

    static JsonManager *getInstance();

    JsonManager(const JsonManager &) = delete;
    JsonManager &operator=(const JsonManager &) = delete;
};