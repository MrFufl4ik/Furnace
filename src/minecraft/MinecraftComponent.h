#pragma oncecom
#include "iostream"

class MinecraftComponent {
public:
    MinecraftComponent();
    ~MinecraftComponent();

    void setComponentUID(const std::string& _component_uid);
    std::string *getComponentUID();

    void setComponentVersion(const std::string& _component_version);
    std::string *getComponentVersion();
private:
    std::string *component_uid;
    std::string *component_version;
};