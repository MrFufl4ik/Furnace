#include "MinecraftMetaData.h"

void MinecraftMetaData::setMinecraftArguments(const std::string &minecraft_arguments) {
    *this->minecraftArguments = minecraft_arguments;
}

void MinecraftMetaData::setMainClass(const std::string &main_class) {
    *this->mainClass = main_class;
}

void MinecraftMetaData::setMainJar(const MetaDataLibrary &main_jar) {
    *this->mainJar = main_jar;
}