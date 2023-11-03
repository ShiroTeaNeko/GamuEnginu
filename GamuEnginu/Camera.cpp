#include "pch.h"
#include "Camera.h"
#include "Application.h"
#include "A_Entity.h"


MyGameEngine::Camera::Camera()
{
	view = sf::View(Application::GetInstance()->window.getDefaultView());
}

void MyGameEngine::Camera::EntityToFollow(A_Entity* entityToFollow)
{
	entityToFollow = entityToFollow;
}

void MyGameEngine::Camera::SetZoom(float zoom)
{
	view.zoom(zoom);
}

void MyGameEngine::Camera::SetSize(float sizeX, float sizeY)
{
	view.setSize(sizeX, sizeY);
}

void MyGameEngine::Camera::SetViewport(sf::FloatRect viewport)
{
	view.setViewport(viewport);
}

void MyGameEngine::Camera::SetRotation(float rotation)
{
	view.setRotation(rotation);
}

void MyGameEngine::Camera::Rotate(float rotateAmount)
{
	view.rotate(rotateAmount);
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
	if (entityToFollow)
	{
		view.setCenter(entityToFollow->getPosition());
		Application::GetInstance()->SetView(view);
	}
}
