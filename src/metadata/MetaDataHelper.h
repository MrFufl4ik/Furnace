#pragma once
#include "iostream"
#include "vector"

class MetaDataHelper {
public:
    static std::string convertMavenPathToJarPathRepresentation(const std::string& mavenArtifact);
};
