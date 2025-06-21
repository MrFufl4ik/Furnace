#pragma once
#include "iostream"

class LogManager {
private:
    static LogManager *instance;
    LogManager();
public:
    static LogManager *getInstance();
    LogManager(const LogManager &) = delete;
    LogManager &operator=(const LogManager &) = delete;

    void sendInfoLog(std::string info_text);
    void sendErrorLog(std::string error_text);
    void sendSuccessLog(std::string success_text);
};