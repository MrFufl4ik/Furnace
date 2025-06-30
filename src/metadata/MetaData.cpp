#include "MetaData.h"

void MetaData::setMetaDataLibraries(const std::vector<MetaDataLibrary> &meta_data_libraries) {
    this->metaDataLibraries.clear();
    for (const auto &element: meta_data_libraries) this->metaDataLibraries.emplace_back(element);
}

void MetaData::setCompatibleJavaMajors(const std::vector<int> &compatible_java_majors) {
    this->compatibleJavaMajors.clear();
    for (auto element: compatible_java_majors) this->compatibleJavaMajors.emplace_back(element);
}

void MetaData::setMetaDataAssetIndex(const MetaDataAssetIndex &meta_data_asset_index) {
    *this->assetIndex = meta_data_asset_index;
}

void MetaData::setCompatibleJavaName(const std::string &compatible_java_name) {
    *this->compatibleJavaName = compatible_java_name;
}

void MetaData::setName(const std::string &name) {
    *this->name = name;
}

void MetaData::setOrder(int order) {
    *this->order = order;
}

void MetaData::setType(const std::string &type) {
    *this->type = type;
}

void MetaData::setUid(const std::string &uid) {
    *this->uid = uid;
}

void MetaData::setVersion(const std::string &version) {
    *this->version = version;
}

void MetaData::setRequiresMinecraftComponent(const std::vector<MinecraftComponent> &requires_minecraft_component) {
    this->requiresMinecraftComponent.clear();
    for (const auto &element: requires_minecraft_component) this->requiresMinecraftComponent.emplace_back(element);
}

void MetaData::setConflictsMinecraftComponent(const std::vector<MinecraftComponent> &conflicts_minecraft_component) {
    this->conflictsMinecraftComponent.clear();
    for (const auto &element: conflicts_minecraft_component) this->conflictsMinecraftComponent.emplace_back(element);
}
