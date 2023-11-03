#include "pch.h"
#include "RenderComponent.h"

MyGameEngine::RenderComponent::RenderComponent()
{
}

void MyGameEngine::RenderComponent::Render(sf::RenderWindow& ref, sf::RenderStates& state)
{
	ref.draw(*(m_drawableObj->GetObject()), state);
}

void MyGameEngine::RenderComponent::Awake()
{
}

void MyGameEngine::RenderComponent::Start()
{
}

void MyGameEngine::RenderComponent::Update(float deltaTime)
{
}

void MyGameEngine::RenderComponent::LateUpdate(float deltaTime)
{
}
