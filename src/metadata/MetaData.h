#pragma once
#include "MetaDataLibrary.h"
#include <iostream>
#include <vector>

class MetaData {
private:
    std::vector<MetaDataLibrary> metaDataLibraries;
public:
    std::vector<MetaDataLibrary> getMetaDataLibraries() { return metaDataLibraries; };
};