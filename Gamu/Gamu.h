#pragma once
#include <SFML/Graphics.hpp>
#include <GamuEnginu/Application.h>
#include <GamuEnginu/MeshFilter.h>
#include <GamuEnginu/Camera.h>
#include <GamuEnginu/ResourceManager.h>
#include <GamuEnginu/RigidBody.h>
#include <GamuEnginu/BoxCollider.h>
#include <GamuEnginu/CollisionComponent.h>
#include <yaml-cpp/yaml.h>
#include <GamuEnginu/Physics.h>
#include <GamuEnginu/CharacterController.h>

void CreateGrounds(MyGameEngine::Application* app, MyGameEngine::ResourceManager* rm, int nb, int sizeX, int sizeY, int posX, int posY, sf::Drawable* sprite);
void PlaceGrounds(MyGameEngine::Application* app, MyGameEngine::ResourceManager* rm, sf::Drawable* drawable);
void PlacePlatform(MyGameEngine::Application* app, MyGameEngine::ResourceManager* rm, sf::Drawable* drawable);
void DrawBackground(MyGameEngine::Application* app, MyGameEngine::ResourceManager* rm, sf::Drawable* drawable);