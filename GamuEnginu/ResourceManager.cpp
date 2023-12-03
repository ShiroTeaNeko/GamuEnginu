#include "pch.h"
#include "ResourceManager.h"
#include <yaml-cpp/yaml.h>
#include <windows.h>
#include <filesystem>
#include "LuaScript.h"

MyGameEngine::ResourceManager::ResourceManager()
{
}

MyGameEngine::ResourceManager::~ResourceManager()
{
}

MyGameEngine::ResourceManager* MyGameEngine::ResourceManager::_instance = nullptr;

MyGameEngine::ResourceManager* MyGameEngine::ResourceManager::GetInstance()
{
    if (_instance == nullptr)
    {
        _instance = new ResourceManager();
    }
    return _instance;
}

sf::Texture& MyGameEngine::ResourceManager::getTexture(const std::string& id)
{
    return textures.at(id);
}

sf::SoundBuffer& MyGameEngine::ResourceManager::getSoundBuffer(const std::string& id)
{
    return soundBuffers.at(id);
}

std::string MyGameEngine::ResourceManager::getScript(const std::string& id)
{
    return luaScripts.at(id);
}

void MyGameEngine::ResourceManager::init(const std::string& configFile)
{
    YAML::Node config = YAML::LoadFile(configFile);

    // Chargez les textures à partir du YAML
    for (const auto& entry : config["textures"]) {
        std::string id = entry["id"].as<std::string>();
        std::string path = entry["path"].as<std::string>();
        textures[id] = sf::Texture();
        textures[id].loadFromFile(path);
    }

    for (const auto& entry : config["sounds"]) {
        std::string id = entry["id"].as<std::string>();
        std::string path = entry["path"].as<std::string>();
        soundBuffers[id] = sf::SoundBuffer();
        soundBuffers[id].loadFromFile(path);
    }

    //charger les scripts lua a partir du yaml
    for (const auto& entry : config["luaScripts"]) {
		std::string id = entry["id"].as<std::string>();
		std::string path = entry["path"].as<std::string>();
		luaScripts[id] = path;
	}
}

/*std::string MyGameEngine::ResourceManager::getExecutablePath()
{
    return sf::IntRect(0, 0, 1, 1).getSize().x;
}*/

