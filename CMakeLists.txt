cmake_minimum_required(VERSION 3.31)
project(furnace)

set(CMAKE_CXX_STANDARD 23)

add_executable(furnace main.cpp
        libs/json.hpp

        src/console/LogManager.cpp
        src/console/LogManager.h
        src/console/ColorHelper.cpp
        src/console/ColorHelper.h
        src/minecraft/MinecraftInstance.cpp
        src/minecraft/MinecraftInstance.h
        src/minecraft/MinecraftComponent.cpp
        src/minecraft/MinecraftComponent.h
        src/minecraft/MinecraftComponentUtil.cpp
        src/minecraft/MinecraftComponentUtil.h
        src/minecraft/MinecraftInstanceManager.cpp
        src/minecraft/MinecraftInstanceManager.h
        src/metadata/MetaDataHelper.cpp
        src/metadata/MetaDataHelper.h
        src/metadata/MetaData.cpp
        src/metadata/MetaData.h
        src/metadata/MetaDataLibrary.cpp
        src/metadata/MetaDataLibrary.h
        src/metadata/MetaDataAssetIndex.cpp
        src/metadata/MetaDataAssetIndex.h
        src/json/JsonManager.cpp
        src/json/JsonManager.h
)
target_link_libraries(furnace PRIVATE stdc++)