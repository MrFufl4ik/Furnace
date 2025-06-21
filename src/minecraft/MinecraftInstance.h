#pragma once
#include "iostream"

class MinecraftInstance {
public:
    MinecraftInstance();
    ~MinecraftInstance();
    void setJavaPath(const std::string& _java_path);
    void setJavaVersion(const std::string& _java_version);
    void setJavaVendor(const std::string& _java_vendor);
    void setJWMArgs(const std::string& _jwm_args);

private:
    std::string java_path;
    std::string java_version;
    std::string java_vendor;
    std::string jwm_args;

};