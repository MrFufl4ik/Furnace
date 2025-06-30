#pragma once
#ifndef FURNACE_META_DATA_H
#define FURNACE_META_DATA_H

#include "MetaDataLibrary.h"
#include "MetaDataAssetIndex.h"
#include "../minecraft/MinecraftComponent.h"
#include <iostream>
#include <vector>

class MetaData {
private:
    MetaDataAssetIndex *assetIndex;
    std::vector<int> compatibleJavaMajors;
    std::string *compatibleJavaName;
    std::vector<MetaDataLibrary> metaDataLibraries;

    std::string *type;
    std::string *uid;
    std::string *version;

    std::vector<MinecraftComponent> requiresMinecraftComponent;
    std::vector<MinecraftComponent> conflictMinecraftComponent;
public:
    void setMetaDataAssetIndex(const MetaDataAssetIndex &meta_data_asset_index);
    const MetaDataAssetIndex &getMetaDataAssetIndex() { return *assetIndex; };
    bool hasMetaDataAssetIndex() { return assetIndex != nullptr; };

    void setCompatibleJavaMajors(const std::vector<int> &compatible_java_majors);
    const std::vector<int> &getCompatibleJavaMajors() { return compatibleJavaMajors; };
    bool hasCompatibleJavaMajors() { return !compatibleJavaMajors.empty(); };

    void setCompatibleJavaName(const std::string &compatible_java_name);
    const std::string &getCompatibleJavaName() { return *compatibleJavaName; };
    bool hasCompatibleJavaName() { return compatibleJavaName != nullptr; };

    void setMetaDataLibraries(const std::vector<MetaDataLibrary> &meta_data_libraries);
    const std::vector<MetaDataLibrary> &getMetaDataLibraries() { return metaDataLibraries; };
    bool hasMetaDataLibraries() { return !metaDataLibraries.empty(); };

    void setType(const std::string &type);
    const std::string &getType() { return *type; };
    bool hasType() { return type != nullptr; };

    void setUid(const std::string &uid);
    const std::string &getUid() { return *uid; };
    bool hasUid() { return uid != nullptr; };

    void setVersion(const std::string &version);
    const std::string &getVersion() { return *version; };
    bool hasVersion() { return version != nullptr; };

};

#endif //FURNACE_META_DATA_H