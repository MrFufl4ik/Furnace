#include "vector"
#include "format"
#include "src/LogManager.h"
#include "src/minecraft/MinecraftComponent.h"
#include "src/minecraft/MinecraftInstance.h"
#include "src/minecraft/MinecraftComponentUtil.h"


int main(int argc, char **argv) {
    std::vector<std::string> main_args;
    for (int i = 1; i < argc; i++) main_args.emplace_back(argv[i]);
    auto *logManager = LogManager::getInstance();
    logManager->sendSuccessLog("Furnace initialized!");
    for (int i = 0; i < main_args.size(); i++)
        logManager->sendInfoLog(std::format("Argument {}: {}", std::to_string(i), main_args[i]));

    auto *mcMinecraftComponent = new MinecraftComponent();
    mcMinecraftComponent->setComponentUID("net.minecraft");
    mcMinecraftComponent->setComponentVersion("1.21.1");

    auto *newMinecraftComponent = new MinecraftComponent();
    newMinecraftComponent->setComponentUID("org.lwjgl3");
    newMinecraftComponent->setComponentVersion("org.lwjgl3");

    MinecraftInstance baseInstance = MinecraftInstance();
    baseInstance.setJavaPath(
            "/home/mrfufl4ik/programming/cpp/furnace/launcher/java/java-runtime-delta/bin/java"
    );
    baseInstance.setComponents({mcMinecraftComponent, newMinecraftComponent});


    return 0;
}