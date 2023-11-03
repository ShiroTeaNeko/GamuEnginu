#pragma once
#include "pch.h"
#include "A_Entity.h"
#include "A_Component.h"
#include "MeshFilter.h"
#include "RenderComponent.h"
#include "Application.h"

MyGameEngine::A_Entity::A_Entity(std::string name)
{
	_name = name;

}


void MyGameEngine::A_Entity::ManageRenderer(sf::RenderWindow& rw)
{
	sf::RenderStates state;
	state.transform.combine(getTransform());
	if (_renderComponent != nullptr)
	{
		_renderComponent->Render(rw, state);
	}
}

void MyGameEngine::A_Entity::Awake()
{
	MeshFilter* meshFilter = nullptr;;

	for (A_Component* component : _components)
	{
		component->Awake();
		if (dynamic_cast<RenderComponent*>(component))
		{
			_renderComponent = (RenderComponent*)component;
		}
		else if (dynamic_cast<MeshFilter*>(component))
		{
			meshFilter = (MeshFilter*)component;
		}
	}

	if (!meshFilter || !_renderComponent) return;

	_renderComponent->SetMeshToRender(meshFilter);
}

void MyGameEngine::A_Entity::Start()
{
	for (A_Component* component : _components)
	{
		component->Start();
	}
}

void MyGameEngine::A_Entity::Update(float deltaTime)
{
	for (A_Component* component : _components)
	{
		component->Update(deltaTime);
	}
}

void MyGameEngine::A_Entity::LateUpdate(float deltaTime)
{
	for (A_Component* component : _components)
	{
		component->LateUpdate(deltaTime);
	}
}

void MyGameEngine::A_Entity::SetEntityPosition(sf::Vector2f position)
{
	setPosition(position);
}

sf::Vector2f MyGameEngine::A_Entity::GetEntityPosition()
{
	return getPosition();
}

