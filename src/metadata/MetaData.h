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

    std::string *name;
    int *order;
    std::string *type;
    std::string *uid;
    std::string *version;

    std::vector<MinecraftComponent> requiresMinecraftComponent;
    std::vector<MinecraftComponent> conflictsMinecraftComponent;
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

    void setName(const std::string &name);
    const std::string &getName() { return *name; };
    bool hasName() { return name != nullptr; };

    void setOrder(int order);
    int getOrder() { return *order; };
    bool hasOrder() { return order != nullptr; };

    void setType(const std::string &type);
    const std::string &getType() { return *type; };
    bool hasType() { return type != nullptr; };

    void setUid(const std::string &uid);
    const std::string &getUid() { return *uid; };
    bool hasUid() { return uid != nullptr; };

    void setVersion(const std::string &version);
    const std::string &getVersion() { return *version; };
    bool hasVersion() { return version != nullptr; };

    void setRequiresMinecraftComponent(const std::vector<MinecraftComponent> &requires_minecraft_component);
    const std::vector<MinecraftComponent> &getRequiresMinecraftComponent() { return requiresMinecraftComponent; };
    bool hasRequiresMinecraftComponent() { return !requiresMinecraftComponent.empty(); };

    void setConflictsMinecraftComponent(const std::vector<MinecraftComponent> &conflicts_minecraft_component);
    const std::vector<MinecraftComponent> &getConflictsMinecraftComponent() { return conflictsMinecraftComponent; };
    bool hasConflictsMinecraftComponent() { return !conflictsMinecraftComponent.empty(); };
};

#endif //FURNACE_META_DATA_H