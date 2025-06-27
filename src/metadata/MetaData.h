#pragma once

#include "MetaDataLibrary.h"
#include "MetaDataAssetIndex.h"
#include <iostream>
#include <vector>

class MetaData {
private:
    MetaDataAssetIndex assetIndex;
    std::vector<int> compatibleJavaMajors;
    std::vector<MetaDataLibrary> metaDataLibraries;
public:
    void setMetaDataAssetIndex(const MetaDataAssetIndex &meta_data_asset_index);
    const MetaDataAssetIndex &getMetaDataAssetIndex() { return assetIndex; };

    void setCompatibleJavaMajors(const std::vector<int> &compatible_java_majors);
    const std::vector<int> &getCompatibleJavaMajors() { return compatibleJavaMajors; };

    void setMetaDataLibraries(const std::vector<MetaDataLibrary> &meta_data_libraries);
    const std::vector<MetaDataLibrary> &getMetaDataLibraries() { return metaDataLibraries; };
};