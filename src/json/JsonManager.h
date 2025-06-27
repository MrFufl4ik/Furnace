#pragma once
#include <fstream>
#include "../../libs/json.hpp"

class JsonManager {
public:
    static nlohmann::json readJsonFile(const std::string &file_path);
};