#include "MetaDataHelper.h"

std::string MetaDataHelper::convertMavenPathToJarPathRepresentation(const std::string& mavenArtifact) {
    std::vector<std::string> parts;
    size_t start = 0;
    size_t end = mavenArtifact.find(':');

    while (end != std::string::npos) {
        parts.push_back(mavenArtifact.substr(start, end - start));
        start = end + 1;
        end = mavenArtifact.find(':', start);
    }
    parts.push_back(mavenArtifact.substr(start));

    if (parts.size() < 3) return "";

    std::string groupId = parts[0];
    std::string artifactId = parts[1];
    std::string version = parts[2];
    std::string classifier = parts.size() > 3 ? parts[3] : "";

    std::string groupPath = groupId;
    std::replace(groupPath.begin(), groupPath.end(), '.', '/');

    std::string jarPath = groupPath + "/" + artifactId + "/" + version + "/";

    if (!classifier.empty()) jarPath += classifier + "/";

    std::string fileName = artifactId + "-" + version;
    if (!classifier.empty()) fileName += "-" + classifier;
    fileName += ".jar";

    std::replace(fileName.begin(), fileName.end(), ':', '-');

    return jarPath + fileName;
}
