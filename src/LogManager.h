#pragma once
#include "iostream"

class LogManager {
public:
    static void sendInfoLog(std::string info_text);
    static void sendWarnLog(std::string warn_text);
    static void sendErrorLog(std::string error_text);
    static void sendSuccessLog(std::string success_text);
};