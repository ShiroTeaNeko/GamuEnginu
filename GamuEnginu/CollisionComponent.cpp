#include "pch.h"
#include "CollisionComponent.h"
#include <iostream>


MyGameEngine::CollisionComponent::CollisionComponent()
{
}

MyGameEngine::CollisionComponent::~CollisionComponent()
{
}

void MyGameEngine::CollisionComponent::BeginCollision(b2Contact* contact)
{
	//std::cout << "Collision Begin" << std::endl;
}

void MyGameEngine::CollisionComponent::EndCollision(b2Contact* contact)
{
	//std::cout << "Collision End" << std::endl;
}

void MyGameEngine::CollisionComponent::Awake()
{
}

void MyGameEngine::CollisionComponent::Start()
{
}

void MyGameEngine::CollisionComponent::Update(float deltaTime)
{
}

void MyGameEngine::CollisionComponent::LateUpdate(float deltaTime)
{
}