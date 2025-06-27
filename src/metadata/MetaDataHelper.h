#pragma once
#ifndef FURNACE_META_DATA_HELPER_H
#define FURNACE_META_DATA_HELPER_H

#include "iostream"
#include "vector"


class MetaDataHelper {
public:
    static std::string convertMavenPathToJarPathRepresentation(const std::string& mavenArtifact);
};

#endif //FURNACE_META_DATA_HELPER_H