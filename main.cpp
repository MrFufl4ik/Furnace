#include "vector"
#include "format"
#include "src/console/LogManager.h"
#include "src/minecraft/MinecraftComponent.h"
#include "src/minecraft/MinecraftInstance.h"
#include "src/minecraft/MinecraftComponentUtil.h"
#include "src/minecraft/MinecraftInstanceManager.h"
#include "src/json/JsonManager.h"
#include "src/operatingsystem/OperatingSystemManager.h"


int main(int argc, char **argv) {
    std::vector<std::string> main_args;
    for (int i = 1; i < argc; i++) main_args.emplace_back(argv[i]);
    auto *logManager = LogManager::getInstance();
    logManager->sendSuccessLog("Furnace initialized!");
    for (int i = 0; i < main_args.size(); i++)
        logManager->sendInfoLog(std::format("Argument {}: {}", std::to_string(i), main_args[i]));

//    auto mcMinecraftComponent = new MinecraftComponent();
//    mcMinecraftComponent->setUID("net.minecraft");
//    mcMinecraftComponent->setVersion("1.21.1");
//
//    auto newMinecraftComponent = new MinecraftComponent();
//    newMinecraftComponent->setUID("org.lwjgl3");
//    newMinecraftComponent->setVersion("3.3.3");
//
//    MinecraftInstance baseInstance = MinecraftInstance();
//    baseInstance.setJavaPath(
//            "/home/mrfufl4ik/programming/cpp/furnace/launcher/java/java-runtime-delta/bin/java"
//    );
//    baseInstance.setComponents({mcMinecraftComponent, newMinecraftComponent});
//
//    MinecraftInstanceManager::getInstance()->runMinecraftInstance(baseInstance);

    JsonManager *jsonManager = JsonManager::getInstance();
    OperatingSystemManager *operatingSystemManager = OperatingSystemManager::getInstance();
    std::filesystem::path prismLauncherDirectory = operatingSystemManager->getPrismLauncherDirectory();
    logManager->sendInfoLog(std::format("Prism Launcher directory: {}", prismLauncherDirectory.string()));
    if (!std::filesystem::exists(prismLauncherDirectory)) {
        logManager->sendInfoLog("Prism Launcher directory not exists. Folder created!");
        std::filesystem::create_directories(prismLauncherDirectory);
    }

    return 0;
}