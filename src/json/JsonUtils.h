#pragma once
#ifndef FURNACE_JSON_UTILS_H
#define FURNACE_JSON_UTILS_H

#include "../../libs/json.hpp"
#include "../minecraft/MinecraftComponent.h"

#include <iostream>

class MinecraftComponent;

class JsonUtils {
public:
    static std::string convertJsonToStringRepresentation(const nlohmann::json &json);
    static nlohmann::json convertMinecraftComponentToJson(const MinecraftComponent &minecraft_component);
};

#endif //FURNACE_JSON_UTILS_H