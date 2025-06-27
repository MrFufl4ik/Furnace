#pragma once
#include "iostream"
#include "../metadata/MetaDataAssetIndex.h"
#include "../metadata/MetaDataLibrary.h"

class LogManager {
private:
    static LogManager *instance;
    LogManager();

    std::string latest_log;

public:
    void sendInfoLog(const std::string &info_text);
    void sendWarnLog(const std::string &warn_text);
    void sendErrorLog(const std::string &error_text);
    void sendSuccessLog(const std::string &success_text);
    void sendSeparator();

    //object
    template<typename T>
    void sendDestructObjectLog(T &obj) {
        const std::string &type_name = typeid(obj).name();
        const std::string &address = std::format("{}", static_cast<const void *>(&obj));
        const std::string &text_to_log = std::format("Destruct object: {}, with memory address: {}", type_name, address);
        sendSuccessLog(text_to_log);
    }

    template<typename T>
    void sendCreateObjectLog(T &obj) {
        const std::string &type_name = typeid(obj).name();
        const std::string &address = std::format("{}", static_cast<const void *>(&obj));
        const std::string &text_to_log = std::format("Create object: {}, with memory address: {}", type_name, address);
        sendSuccessLog(text_to_log);
    }

    void sendMetaDataAssetIndexLog(const MetaDataAssetIndex &meta_data_asset_index);
    void sendMetaDataLibraryLog(const MetaDataLibrary &meta_data_library);

    static LogManager* getInstance();

    LogManager(const LogManager&) = delete;
    LogManager &operator=(const LogManager&) = delete;
};