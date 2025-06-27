#include "JsonManager.h"

//Standalone

JsonManager *JsonManager::instance = nullptr;
JsonManager *JsonManager::getInstance() {
    if (instance == nullptr) if (instance == nullptr) instance = new JsonManager();
    return instance;
}

nlohmann::json JsonManager::readJsonFile(const std::string &file_path) {
    std::fstream file_stream{file_path};
    if (!std::filesystem::exists(file_path)){
        log_manager->sendWarnLog(std::format("Json file ({}) not exists", file_path));
        return nlohmann::json::parse(
                R"(
                {
                    "read_json_status": "file_not_exists"
                }
            )"
        );
    }
    else if (!file_stream.is_open()) {
        log_manager->sendWarnLog(std::format("Json file ({}) not readable", file_path));
        return nlohmann::json::parse(
                R"(
                {
                    "read_json_status": "file_read_error"
                }
            )"
        );
    }
    nlohmann::json json;
    try {
        file_stream >> json;
    }
    catch (const nlohmann::json::parse_error &e) {
        log_manager->sendErrorLog(std::format("Json file ({}) not parsable", file_path));
        return nlohmann::json::parse(
            R"(
                {
                    "read_json_status": "file_parse_error"
                }
            )"
        );
    }
    return json;
}

std::string JsonManager::convertJsonToStringRepresentation(nlohmann::json json) {
    std::stringstream string_stream;
    string_stream << json;
    return string_stream.str();
}
