cmake_minimum_required(VERSION 3.31)
project(furnace)

set(CMAKE_CXX_STANDARD 23)

add_executable(furnace main.cpp
        src/LogManager.cpp
        src/LogManager.h
        src/ColorHelper.cpp
        src/ColorHelper.h)
target_link_libraries(furnace PRIVATE stdc++)