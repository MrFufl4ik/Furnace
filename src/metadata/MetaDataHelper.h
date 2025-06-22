#pragma once
#include "iostream"

class MetaDataHelper {
    static std::string convertMavenPathToJarPathRepresentation(const std::string& mavenArtifact);
};
