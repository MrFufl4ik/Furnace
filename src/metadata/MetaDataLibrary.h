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
            std::string _name,
            std::string _downloadArtifactSha1,
            std::string _downloadArtifactSize,
            std::string _downloadArtifactUrl
    );

    std::string getName() { return name; };
    std::string getDownloadArtifactSha1()   { return downloadArtifactSha1;  };
    std::string getDownloadArtifactSize()   { return downloadArtifactSize;  };
    std::string getDownloadArtifactUrl()    { return downloadArtifactUrl;   };
};