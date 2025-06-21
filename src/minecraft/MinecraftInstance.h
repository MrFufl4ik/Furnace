#pragma once
#include "iostream"
#include "vector"
#include "MinecraftComponent.h"

class MinecraftInstance {
public:
    MinecraftInstance();
    ~MinecraftInstance();

    void setComponents(const std::vector<MinecraftComponent*>& _components);
    std::vector<MinecraftComponent*> getComponents();

    void setJavaPath(const std::string& _java_path);
    std::string* getJavaPath();

    void setJavaVersion(const std::string& _java_version);
    std::string* getJavaVersion();

    void setJavaVendor(const std::string& _java_vendor);
    std::string* getJavaVendor();

    void setJWMArgs(const std::string& _jwm_args);
    std::string* getJWMArgs();
private:
    std::vector<MinecraftComponent*> components;
    std::string* java_path;
    std::string* java_version;
    std::string* java_vendor;
    std::string* jwm_args;
};