#include "MetaDataHelper.h"

std::string MetaDataHelper::convertMavenPathToJarPathRepresentation(const std::string& mavenArtifact) {
    size_t firstColon = mavenArtifact.find(':');
    size_t lastColon = mavenArtifact.rfind(':');

    if (firstColon == std::string::npos || lastColon == std::string::npos || firstColon == lastColon) return "";

    std::string groupId = mavenArtifact.substr(0, firstColon);
    std::string artifactId = mavenArtifact.substr(firstColon + 1, lastColon - firstColon - 1);
    std::string version = mavenArtifact.substr(lastColon + 1);

    std::string groupPath = groupId;
    std::replace(groupPath.begin(), groupPath.end(), '.', '/');

    std::string jarPath = groupPath + "/" + artifactId + "/" + version + "/" + artifactId + "-" + version + ".jar";

    return jarPath;
}
