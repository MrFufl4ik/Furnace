#include "MinecraftInstanceManager.h"


int MinecraftInstanceManager::runMinecraftInstance(MinecraftInstance &minecraftInstance) {
    std::string command;
    if (!minecraftInstance.hasJavaPath()) return 101;
    command += std::format("{} ", minecraftInstance.getJavaPath());
    if (minecraftInstance.hasJWMArgs()) command += std::format("{} ", minecraftInstance.getJWMArgs());
    std::vector<std::string> mavenLibraries{
            "com.github.oshi:oshi-core:6.4.10",
            "com.google.code.gson:gson:2.10.1",
            "com.google.guava:failureaccess:1.0.1",
            "com.google.guava:guava:32.1.2-jre",
            "com.ibm.icu:icu4j:73.2",
            "com.mojang:authlib:6.0.54",
            "com.mojang:blocklist:1.0.10",
            "com.mojang:brigadier:1.3.10",
            "com.mojang:datafixerupper:8.0.16",
            "com.mojang:logging:1.2.7",
            "com.mojang:patchy:2.2.10",
            "com.mojang:text2speech:1.17.9",
            "commons-codec:commons-codec:1.16.0",
            "commons-io:commons-io:2.15.1",
            "commons-logging:commons-logging:1.2",
            "io.netty:netty-buffer:4.1.97.Final",
            "io.netty:netty-codec:4.1.97.Final",
            "io.netty:netty-common:4.1.97.Final",
            "io.netty:netty-handler:4.1.97.Final",
            "io.netty:netty-resolver:4.1.97.Final",
            "io.netty:netty-transport-classes-epoll:4.1.97.Final",
            "io.netty:netty-transport-native-epoll:4.1.97.Final:linux-aarch_64",
            "io.netty:netty-transport-native-epoll:4.1.97.Final:linux-x86_64",
            "io.netty:netty-transport-native-unix-common:4.1.97.Final",
            "io.netty:netty-transport:4.1.97.Final",
            "it.unimi.dsi:fastutil:8.5.12",
            "net.java.dev.jna:jna-platform:5.14.0",
            "net.java.dev.jna:jna:5.14.0",
            "net.sf.jopt-simple:jopt-simple:5.0.4",
            "org.apache.commons:commons-compress:1.26.0",
            "org.apache.commons:commons-lang3:3.14.0",
            "org.apache.httpcomponents:httpclient:4.5.13",
            "org.apache.httpcomponents:httpcore:4.4.16",
            "org.apache.logging.log4j:log4j-api:2.22.1",
            "org.apache.logging.log4j:log4j-core:2.22.1",
            "org.apache.logging.log4j:log4j-slf4j2-impl:2.22.1",
            "org.jcraft:jorbis:0.0.17",
            "org.joml:joml:1.10.5",
            "org.lz4:lz4-java:1.8.0",
            "org.lwjgl:lwjgl-freetype-natives-linux:3.3.3",
            "org.lwjgl:lwjgl-freetype:3.3.3",
            "org.lwjgl:lwjgl-glfw-natives-linux:3.3.3",
            "org.lwjgl:lwjgl-glfw:3.3.3",
            "org.lwjgl:lwjgl-jemalloc-natives-linux:3.3.3",
            "org.lwjgl:lwjgl-jemalloc:3.3.3",
            "org.lwjgl:lwjgl-natives-linux:3.3.3",
            "org.lwjgl:lwjgl:3.3.3",
            "org.lwjgl:lwjgl-openal-natives-linux:3.3.3",
            "org.lwjgl:lwjgl-openal:3.3.3",
            "org.lwjgl:lwjgl-opengl-natives-linux:3.3.3",
            "org.lwjgl:lwjgl-opengl:3.3.3",
            "org.lwjgl:lwjgl-stb-natives-linux:3.3.3",
            "org.lwjgl:lwjgl-stb:3.3.3",
            "org.lwjgl:lwjgl-tinyfd-natives-linux:3.3.3",
            "org.lwjgl:lwjgl-tinyfd:3.3.3",
            "org.slf4j:slf4j-api:2.0.9",
            "com.mojang:minecraft:1.21.1:client",
    };
    std::string librariesRoot = "/home/mrfufl4ik/programming/cpp/furnace/launcher/libraries";

    {
        bool result = validateLibraries(
                mavenLibraries,
                librariesRoot
        );
        if (!result) return 102;
    }
    std::string librariesStringRepresentation = convertLibrariesToStringRepresentation(mavenLibraries, librariesRoot);

    command.append("-cp ");
    command.append(librariesStringRepresentation);
    command.append(std::format(" {}", "net.minecraft.client.main.Main"));
    command.append(std::format(" {} {}", "--username", "Player"));
    command.append(std::format(" {} {}", "--version", "1.21.1"));
    command.append(
            std::format(
                    " --accessToken 0 {}",
                    "--userProperties "
            )
    ).append("{}");
    command.append(std::format(" {} {}", "--gameDir", "/home/mrfufl4ik/programming/cpp/furnace/minecraft"));
    command.append(std::format(" {} {}", "--assetsDir", "/home/mrfufl4ik/programming/cpp/furnace/launcher/assets"));
    command.append(std::format(" {} {}", "--assetIndex", "26"));

    log_manager->sendInfoLog(command);
    //system(command.c_str());
    return 0;
}

void MinecraftInstanceManager::stopMinecraftInstance(MinecraftInstance &minecraftInstance) {

}

MinecraftInstanceManager::MinecraftInstanceManager() = default;

MinecraftInstanceManager::~MinecraftInstanceManager() {
    delete log_manager;
}

MinecraftInstanceManager *MinecraftInstanceManager::instance = nullptr;

MinecraftInstanceManager *MinecraftInstanceManager::getInstance() {
    if (instance == nullptr) if (instance == nullptr) instance = new MinecraftInstanceManager();
    return instance;
}

bool MinecraftInstanceManager::validateLibraries(std::vector<std::string> libraries, std::string libraries_root) {
    log_manager->sendSeparator();
    log_manager->sendInfoLog("Validating libraries...");
    bool result = true;
    for (int i = 0; i < libraries.size(); i++) {
        std::string localPath = MetaDataHelper::convertMavenPathToJarPathRepresentation(libraries[i]);
        std::string absolutePath = std::format("{}/{}", libraries_root, localPath);
        bool status = std::filesystem::exists(absolutePath);
        if (status){
            log_manager->sendSuccessLog(
                    std::format("{}: {} | {}", i + 1, localPath, "OK")
            );
        }
        else {
            log_manager->sendErrorLog(
                    std::format("{}: {} | {}", i + 1, localPath, "Not Found")
            );
            result = false;
        }
    }
    log_manager->sendSeparator();
    return result;
}

std::string MinecraftInstanceManager::convertLibrariesToStringRepresentation(std::vector<std::string> libraries,
                                                                             std::string libraries_root) {
    std::string result;
    for (int i = 0; i < libraries.size(); i++) {
        std::string path = MetaDataHelper::convertMavenPathToJarPathRepresentation(libraries[i]);
        result.append(std::format("{}/{}", libraries_root, path));
        if ((i + 1) < libraries.size()) result.append(":");
    }
    return result;
}
