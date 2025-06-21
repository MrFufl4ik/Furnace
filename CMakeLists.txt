cmake_minimum_required(VERSION 3.31)
project(furnace)

set(CMAKE_CXX_STANDARD 23)

add_executable(furnace main.cpp
        src/LogManager.cpp
        src/LogManager.h
        src/ColorHelper.cpp
        src/ColorHelper.h
        src/minecraft/MinecraftInstance.cpp
        src/minecraft/MinecraftInstance.h
        src/minecraft/MinecraftComponent.cpp
        src/minecraft/MinecraftComponent.h
)
target_link_libraries(furnace PRIVATE stdc++)