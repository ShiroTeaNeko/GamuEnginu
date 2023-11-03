#include <iostream>
#include <SFML/Graphics.hpp>

#include "pch.h"
#include "Application.h"

MyGameEngine::Application* MyGameEngine::Application::_instance;

MyGameEngine::Application::Application()
{
	_instance = this;
}

MyGameEngine::Application::~Application()
{
}

void MyGameEngine::Application::Awake(int windowSizeX, int windowSizeY, std::string windowName)
{
    window.create(sf::VideoMode(windowSizeX, windowSizeY), windowName);

    for (A_Entity* entity : _entities)
    {
        entity->Awake();
    }
}

void MyGameEngine::Application::Start()
{
    for (A_Entity* entity : _entities)
    {
		entity->Start();
	}
}

void MyGameEngine::Application::Loop()
{
    sf::Clock clock;

    while (window.isOpen())
    {
        
        float deltaTime = clock.restart().asMilliseconds();

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        for (A_Entity* entity : _entities)
        {
            entity->Update(deltaTime);
        }

        for (A_Entity* entity : _entities)
        {
            entity->LateUpdate(deltaTime);
        }

        _physics.Update(deltaTime);

        window.clear();

        for (A_Entity* entity : _entities)
        {
            entity->ManageRenderer(window);
        }

        window.display();

    }
}

MyGameEngine::A_Entity* MyGameEngine::Application::CreateEntity(std::string name)
{
    A_Entity* entity = new A_Entity(name);

    _entities.push_back(entity);
    return entity;
}

MyGameEngine::Application* MyGameEngine::Application::GetInstance()
{
    if (_instance == nullptr)
    {
        _instance = new Application();
    }
    return _instance;
}

MyGameEngine::A_Entity* MyGameEngine::Application::GetEntity(A_Component* component)
{
    auto app = GetInstance();

    for (A_Entity* entity : app->_entities) {
        for (A_Component* entityComponent : entity->_components) {
            if (entityComponent == component) {
                return entity;
            }
        }
    }

    //return nullptr;
}


void MyGameEngine::Application::SetView(sf::View& view)
{
    window.setView(view);
}