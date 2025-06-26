#include "MetaDataLibrary.h"

#include <utility>

MetaDataLibrary::MetaDataLibrary(std::string _name, std::string _downloadArtifactSha1, std::string _downloadArtifactSize,
                                 std::string _downloadArtifactUrl) {
    name = std::move(_name);
    downloadArtifactSha1 = std::move(_downloadArtifactSha1);
    downloadArtifactSize = std::move(_downloadArtifactSize);
    downloadArtifactUrl = std::move(_downloadArtifactUrl);
}
