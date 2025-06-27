#include "JsonUtils.h"

std::string JsonUtils::convertJsonToStringRepresentation(const nlohmann::json &json) {
    std::stringstream string_stream;
    string_stream << json;
    return string_stream.str();
}

nlohmann::json JsonUtils::convertMinecraftComponentToJson(const MinecraftComponent &minecraft_component) {
    nlohmann::json json = nlohmann::json();
    auto component_uid = minecraft_component.getUID();
    json["uid"] = component_uid == nullptr ? "null" : *component_uid;
    auto component_version = minecraft_component.getVersion();
    json["version"] = component_version == nullptr ? "null" : *component_version;
    return json;
}
