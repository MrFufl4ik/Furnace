#include "MinecraftComponentUtil.h"

std::string
MinecraftComponentUtil::getStringRepresentationOfMinecraftComponent(MinecraftComponent &minecraftComponent) {
    return
            "{" +
            std::format(
                    "uuid: {}, version: {}",
                    *minecraftComponent.getComponentUID(),
                    *minecraftComponent.getComponentVersion()
            ) +
            "}";
}
