#include "vector"
#include "format"
#include "src/LogManager.h"
#include "src/minecraft/MinecraftComponent.h"


int main(int argc, char **argv) {
    std::vector<std::string> main_args;
    for (int i = 1; i < argc; i++) main_args.emplace_back(argv[i]);
    LogManager::sendSuccessLog("Furnace initialized!");
    for (int i = 0; i < main_args.size(); i++)
        LogManager::sendInfoLog(std::format("Argument {}: {}", std::to_string(i), main_args[i]));

    MinecraftComponent mcMinecraftComponent = MinecraftComponent();
    mcMinecraftComponent.setComponentUID("net.minecraft");
    mcMinecraftComponent.setComponentVersion("1.21.1");

    return 0;
}