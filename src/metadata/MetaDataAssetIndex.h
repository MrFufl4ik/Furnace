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

    const int           &getId()        { return id; };
    const std::string   &getSha1()      { return sha1; };
    const int           &getSize()      { return size; };
    const int           &getTotalSize() { return totalSize; };
    const std::string   &getUrl()       { return url; };
};