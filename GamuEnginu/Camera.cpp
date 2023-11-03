#include "pch.h"
#include "Camera.h"



MyGameEngine::Camera::Camera()
{
}

sf::View MyGameEngine::Camera::SetView(sf::Vector2u windowSize)
{
	sf::View view;
	view.zoom(_zoomLevel);
	view.setCenter(_centerPos);
	view.setSize(sf::Vector2f(windowSize.x, windowSize.y));
	//view.setViewport(sf::FloatRect(0.25f, 0.25, 0.5f, 0.5f));
	view.setRotation(_rotation);
	return view;
}

void MyGameEngine::Camera::Awake()
{

}

void MyGameEngine::Camera::Start()
{
}

void MyGameEngine::Camera::Update(float deltaTime)
{
}

void MyGameEngine::Camera::LateUpdate(float deltaTime)
{
}
