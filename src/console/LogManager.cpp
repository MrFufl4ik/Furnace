#include "LogManager.h"
#include "ColorHelper.h"

void LogManager::sendInfoLog(const std::string &info_text) {
    const std::string &text_to_log = std::format("[Info] {}", info_text);
    latest_log = text_to_log;
    std::cout << text_to_log << std::endl;
}

void LogManager::sendWarnLog(const std::string &warn_text) {
    const std::string &text_to_log =
            std::format(
                    "{} {}", ColorHelper::colorize("[Warning]", {ColorHelper::FG_YELLOW}), warn_text
            );
    latest_log = text_to_log;
    std::cout << text_to_log << std::endl;
}

void LogManager::sendErrorLog(const std::string &error_text) {
    const std::string &text_to_log =
            std::format(
                    "{} {}", ColorHelper::colorize("[Error]", {ColorHelper::FG_RED}), error_text
            );
    latest_log = text_to_log;
    std::cout << text_to_log << std::endl;
}


void LogManager::sendSuccessLog(const std::string &success_text) {
    const std::string &text_to_log =
            std::format(
                    "{} {}", ColorHelper::colorize("[Success]", {ColorHelper::FG_GREEN}), success_text
            );
    latest_log = text_to_log;
    std::cout << text_to_log << std::endl;
}

void LogManager::sendSeparator() {
    if (latest_log == "\n") return;
    latest_log = "\n";
    std::cout << std::endl;
}

void LogManager::sendMetaDataAssetIndexLog(const MetaDataAssetIndex &meta_data_asset_index) {
    const std::string &text_to_log = std::string("")
            .append("{")
            .append(std::format("object_id: {}", static_cast<void *>(this))).append(", ")
            .append(std::format("id: {}", meta_data_asset_index.getId())).append(", ")
            .append(std::format("sha1: \"{}\"", meta_data_asset_index.getSha1())).append(", ")
            .append(std::format("size: {}", meta_data_asset_index.getSize())).append(", ")
            .append(std::format("total_size: {}", meta_data_asset_index.getTotalSize())).append(", ")
            .append(std::format("url: \"{}\"", meta_data_asset_index.getUrl()))
            .append("}");
    sendInfoLog(text_to_log);
}

void LogManager::sendMetaDataLibraryLog(const MetaDataLibrary &meta_data_library) {
    const std::string &text_to_log = std::string("")
            .append("{")
            .append(std::format("object_id: {}", static_cast<void *>(this))).append(", ")
            .append(std::format("name: \"{}\"", meta_data_library.getName())).append(", ")
            .append(std::format("artifact_sha1: \"{}\"", meta_data_library.getDownloadArtifactSha1())).append(", ")
            .append(std::format("artifact_size: \"{}\"", meta_data_library.getDownloadArtifactSize())).append(", ")
            .append(std::format("artifact_url: \"{}\"", meta_data_library.getDownloadArtifactUrl()))
            .append(std::format(""))
            .append("}");
    sendInfoLog(text_to_log);
}

LogManager::LogManager() = default;

LogManager *LogManager::instance = nullptr;

LogManager *LogManager::getInstance() {
    if (instance == nullptr) if (instance == nullptr) instance = new LogManager();
    return instance;
}