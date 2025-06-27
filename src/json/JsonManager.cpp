#include "JsonManager.h"

nlohmann::json JsonManager::readJsonFile(const std::string &file_path) {
    std::fstream file_stream { file_path };
    if (!file_stream.is_open())

    return nlohmann::json();
}
