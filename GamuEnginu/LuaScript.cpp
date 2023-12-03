#include "pch.h"
#include "LuaScript.h"
#include <iostream>
#include "ResourceManager.h"
#include "Application.h"
#include "CollisionComponent.h"

void MyGameEngine::LuaScript::ReportErrors(lua_State* luaState, int status)
{
	if (status == 0)
	{
		return;
	}

	std::cerr << "[LUA ERROR] " << lua_tostring(luaState, -1) << std::endl;

	lua_pop(luaState, 1);
}

MyGameEngine::LuaScript::LuaScript()
{
	// Créer un luaState et le stocker dans la variable membre luaState (luaL_newState)
	luaState = luaL_newstate();

	//Ajouter la lib standard du lua au state crée (luaL_openlibs(_luaState))
	luaL_openlibs(luaState);

	//Faire les déclarations des classes du moteurs accessible et utilisable en lua (luabridge::getGlobalNamespace(_luaState))
	luabridge::getGlobalNamespace(luaState)
		/*	.beginClass<MyGameEngine::ResourceManager>("ResourceManager")
			.addFunction("getTexture", &MyGameEngine::ResourceManager::getTexture)
			.endClass()*/
		.beginClass<MyGameEngine::Application>("Application")
		.addStaticFunction("GetInstance", &MyGameEngine::Application::GetInstance)
		.endClass();/*
		.beginClass<MyGameEngine::RigidBody>("RigidBody")
		.addFunction("GetBody", &MyGameEngine::RigidBody::GetBody)
		.endClass()
		.beginClass<MyGameEngine::ICollisionable>("ICollisionable")
		.addFunction("BeginCollision", &MyGameEngine::ICollisionable::BeginCollision)
		.endClass();*/

	//Ajouter des objets accessibles en lua (luabridge::setGlobal(_luaState, application, “app”)
	luabridge::setGlobal(luaState, MyGameEngine::Application::GetInstance(), "app");
}

MyGameEngine::LuaScript::~LuaScript()
{
	// Appeler la fonction de finalisation du script
	/*luabridge::LuaRef finalize = luabridge::getGlobal(luaState, "Finalize");
	if (finalize.isFunction())
	{
		finalize();
	}*/
}

void MyGameEngine::LuaScript::SetScript(std::string scriptName)
{
	std::string path = MyGameEngine::ResourceManager::GetInstance()->getScript(scriptName);

	int scriptLoadStatus = luaL_dofile(luaState, path.c_str());

	ReportErrors(luaState, scriptLoadStatus);

	// Appeler la fonction d'initialisation du script
	/*luabridge::LuaRef initialize = luabridge::getGlobal(luaState, "Initialize");
	if (initialize.isFunction())
	{
		initialize();
	}*/
}

void MyGameEngine::LuaScript::Update(float deltaTime)
{
	// Appeler la fonction update du script
	luabridge::LuaRef update = luabridge::getGlobal(luaState, "Update");
	if (update.isFunction())
	{
		update(deltaTime);
	}
}
