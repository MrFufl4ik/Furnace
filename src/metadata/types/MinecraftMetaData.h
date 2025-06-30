#pragma once
#ifndef FURNACE_MINECRAFTMETADATA_H
#define FURNACE_MINECRAFTMETADATA_H


#include "../MetaData.h"

class MinecraftMetaData: public MetaData {
private:
    std::string *minecraftArguments;
    std::string *mainClass;
    MetaDataLibrary *mainJar;
public:
    void setMinecraftArguments(const std::string &minecraft_arguments);
    const std::string &getMinecraftArguments() { return *minecraftArguments; };
    bool hasMinecraftArguments() { return minecraftArguments != nullptr; };

    void setMainClass(const std::string &main_class);
    const std::string &getMainClass() { return *mainClass; };
    bool hasMainClass() { return mainClass != nullptr; };

    void setMainJar(const MetaDataLibrary &main_jar);
    const MetaDataLibrary &getMainJar() { return *mainJar; };
    bool hasMainJar() { return mainJar != nullptr; };
};


#endif //FURNACE_MINECRAFTMETADATA_H
