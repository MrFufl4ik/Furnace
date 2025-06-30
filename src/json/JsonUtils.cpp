#include "JsonUtils.h"

std::string JsonUtils::convertJsonToStringRepresentation(const nlohmann::json &json) {
    std::stringstream string_stream;
    string_stream << json;
    return string_stream.str();
}

nlohmann::json JsonUtils::convertMinecraftComponentToJson(const MinecraftComponent &minecraft_component) {
    nlohmann::json json = nlohmann::json();
    json["uid"] = minecraft_component.hasUid() ? minecraft_component.getUid() : "null";
    json["version"] = minecraft_component.hasVersion() ? minecraft_component.getVersion() : "null";
    return json;
}
