#include "MetaData.h"

void MetaData::setMetaDataLibraries(const std::vector<MetaDataLibrary> &meta_data_libraries) {
    this->metaDataLibraries.clear();
    for (const auto &element: meta_data_libraries) this->metaDataLibraries.emplace_back(element);
}

void MetaData::setCompatibleJavaMajors(const std::vector<int> &compatible_java_majors) {
    this->compatibleJavaMajors.clear();
    for (auto element : compatible_java_majors) this->compatibleJavaMajors.emplace_back(element);
}

void MetaData::setMetaDataAssetIndex(const MetaDataAssetIndex &meta_data_asset_index) {
    this->assetIndex = meta_data_asset_index
}
