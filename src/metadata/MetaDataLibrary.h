#pragma once
#ifndef FURNACE_META_DATA_LIBRARY_H
#define FURNACE_META_DATA_LIBRARY_H

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

    const std::string &getName()                    const { return name; };
    const std::string &getDownloadArtifactSha1()    const { return downloadArtifactSha1;  };
    const std::string &getDownloadArtifactSize()    const { return downloadArtifactSize;  };
    const std::string &getDownloadArtifactUrl()     const { return downloadArtifactUrl;   };
};

#endif //FURNACE_META_DATA_LIBRARY_H