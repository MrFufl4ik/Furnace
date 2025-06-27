#pragma once

#include <string>

class MetaDataLibrary {
private:
    std::string name;
    std::string downloadArtifactSha1;
    std::string downloadArtifactSize;
    std::string downloadArtifactUrl;
public:
    MetaDataLibrary(
            const std::string &_name,
            const std::string &_downloadArtifactSha1,
            const std::string &_downloadArtifactSize,
            const std::string &_downloadArtifactUrl
    );

    const std::string &getName() { return name; };
    const std::string &getDownloadArtifactSha1()   { return downloadArtifactSha1;  };
    const std::string &getDownloadArtifactSize()   { return downloadArtifactSize;  };
    const std::string &getDownloadArtifactUrl()    { return downloadArtifactUrl;   };
};