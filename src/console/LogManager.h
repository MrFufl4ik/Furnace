#pragma once
#include "iostream"

class LogManager {
private:
    static LogManager *instance;
    LogManager();

    std::string latest_log;

public:
    void sendInfoLog(std::string info_text);
    void sendWarnLog(std::string warn_text);
    void sendErrorLog(std::string error_text);
    void sendSuccessLog(std::string success_text);
    void sendSeparator();

    static LogManager* getInstance();

    LogManager(const LogManager&) = delete;
    LogManager &operator=(const LogManager&) = delete;
};