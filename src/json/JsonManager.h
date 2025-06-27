#pragma once
#ifndef FURNACE_JSON_MANAGER_H
#define FURNACE_JSON_MANAGER_H

#include "../../libs/json.hpp"
#include "../console/LogManager.h"

#include <fstream>

class JsonManager {
private:
    static JsonManager *instance;

    JsonManager() = default;

    LogManager *log_manager{LogManager::getInstance()};
public:
    nlohmann::json readJsonFile(const std::string &file_path);

    static JsonManager *getInstance();

    JsonManager(const JsonManager &) = delete;
    JsonManager &operator=(const JsonManager &) = delete;
};

#endif //FURNACE_JSON_MANAGER_H