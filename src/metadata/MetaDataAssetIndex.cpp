#include "MetaDataAssetIndex.h"

MetaDataAssetIndex::MetaDataAssetIndex(const int &id,
                                       const std::string &sha1,
                                       const int &size,
                                       const int &total_size,
                                       const std::string &url) {
    this->id = id;
    this->sha1 = sha1;
    this->size = size;
    this->totalSize = total_size;
    this->url = url;
}
