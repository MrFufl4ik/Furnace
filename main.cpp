#include <iostream>
#include "vector"
#include "format"
#include "src/LogManager.h"


int main(int argc, char **argv) {
    std::vector<std::string> main_args;
    for (int i = 1; i < argc; i++) main_args.emplace_back(argv[i]);
    LogManager::sendInfoLog("Furnace initialized!");
    for (int i = 0; i < main_args.size(); i++)
        LogManager::sendInfoLog(std::format("Argument {}: {}", std::to_string(i), main_args[i]));

    //test
    LogManager::sendInfoLog("Test info log!");
    LogManager::sendErrorLog("Test error log!");
    LogManager::sendSuccessLog("Test success log!");

    return 0;
}