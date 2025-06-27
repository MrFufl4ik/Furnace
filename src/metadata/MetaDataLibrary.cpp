#include "MetaDataLibrary.h"

#include <utility>

MetaDataLibrary::MetaDataLibrary(const std::string &name,
                                 const std::string &download_artifact_sha1,
                                 const std::string &download_artifact_size,
                                 const std::string &download_artifact_url) {
    this->name = name;
    this->downloadArtifactSha1 = download_artifact_sha1;
    this->downloadArtifactSize = download_artifact_size;
    this->downloadArtifactUrl = download_artifact_url;
}
