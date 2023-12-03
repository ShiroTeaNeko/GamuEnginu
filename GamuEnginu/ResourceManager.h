#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <yaml-cpp/yaml.h>
#include <windows.h>
#include <filesystem>
#include "LuaScript.h"

namespace MyGameEngine {
	class ResourceManager
	{
	private:    
		std::map<std::string, sf::Texture> textures;
		std::map<std::string, sf::SoundBuffer> soundBuffers;
		std::map<std::string, std::string> luaScripts;
	protected:
		static ResourceManager* _instance;
	public:
		ResourceManager();
		~ResourceManager();
		static ResourceManager* GetInstance(); 
		sf::Texture& getTexture(const std::string& id);
		sf::SoundBuffer& getSoundBuffer(const std::string& id);
		std::string getScript(const std::string& id);
		void init(const std::string& configFile);
		std::string getExecutablePath();
	};
}

