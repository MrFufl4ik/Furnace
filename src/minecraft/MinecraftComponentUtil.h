#pragma once
#ifndef FURNACE_COMPONENT_UTIL_H
#define FURNACE_COMPONENT_UTIL_H

#include "MinecraftComponent.h"

class MinecraftComponentUtil {
public:
    static std::string getStringRepresentationOfMinecraftComponent(MinecraftComponent &minecraftComponent);
};

#endif //FURNACE_COMPONENT_UTIL_H