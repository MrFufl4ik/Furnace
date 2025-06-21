#include "vector"
#include "format"
#include "src/LogManager.h"
#include "src/minecraft/MinecraftComponent.h"
#include "src/minecraft/MinecraftInstance.h"


void print_components(const std::vector<MinecraftComponent *>& components){
    LogManager::sendSeparator();
    for (int i = 0; i < components.size(); i++){
        auto* component = components[i];
        LogManager::sendInfoLog(std::format("Component id: {}", i));
        LogManager::sendInfoLog(std::format("Component address: {}", static_cast<void*>(component)));
        LogManager::sendInfoLog(std::format("Component uid: {}", *component->getComponentUID()));
        LogManager::sendInfoLog(std::format("Component version{}", *component->getComponentVersion()));
    }
    LogManager::sendSeparator();
}


int main(int argc, char **argv) {
    std::vector<std::string> main_args;
    for (int i = 1; i < argc; i++) main_args.emplace_back(argv[i]);
    LogManager::sendSuccessLog("Furnace initialized!");
    for (int i = 0; i < main_args.size(); i++)
        LogManager::sendInfoLog(std::format("Argument {}: {}", std::to_string(i), main_args[i]));

    auto* mcMinecraftComponent = new MinecraftComponent();
    mcMinecraftComponent->setComponentUID("net.minecraft");
    mcMinecraftComponent->setComponentVersion("1.21.1");

    MinecraftInstance baseInstance = MinecraftInstance();
    baseInstance.setComponents({mcMinecraftComponent});


    return 0;
}