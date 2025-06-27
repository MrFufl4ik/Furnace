#pragma once

#include <iostream>

class MetaDataAssetIndex {
private:
    int id;
    std::string sha1;
    int size;
    int totalSize;
    std::string url;
public:
    MetaDataAssetIndex(
            const int &id,
            const std::string &sha1,
            const int &size,
            const int &total_size,
            const std::string &url
    );

    const int           &getId()        const { return this->id; };
    const std::string   &getSha1()      const { return this->sha1; };
    const int           &getSize()      const { return this->size; };
    const int           &getTotalSize() const { return this->totalSize; };
    const std::string   &getUrl()       const { return this->url; };
};