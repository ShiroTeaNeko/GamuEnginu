#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <yaml-cpp/yaml.h>
#include <windows.h>
#include <filesystem>

namespace MyGameEngine {
	class ResourceManager
	{
	private:    
		std::map<std::string, sf::Texture> textures;
		std::map<std::string, sf::SoundBuffer> soundBuffers;
	protected:
		static ResourceManager* _instance;
	public:
		ResourceManager();
		~ResourceManager();
		static ResourceManager* GetInstance(); 
		sf::Texture& getTexture(const std::string& id);
		sf::SoundBuffer& getSoundBuffer(const std::string& id);
		void init(const std::string& configFile);
		std::string getExecutablePath();
	};
}

