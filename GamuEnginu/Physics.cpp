#include "pch.h"
#include "Physics.h"
#include "RigidBody.h"
#include "Application.h"

MyGameEngine::Physics::Physics() : gravity(0.0f, 10.0f), world(gravity)
{
}

MyGameEngine::Physics::~Physics()
{
}

void MyGameEngine::Physics::Update(float deltaTime)
{
    MyGameEngine::Application* app = MyGameEngine::Application::GetInstance();

	//set rb position to entity position
    for (A_Entity* entity : app->GetEntities())
	{
		MyGameEngine::RigidBody* rb = app->GetComponentFromEntity<MyGameEngine::RigidBody>(entity);
		
		if (rb != nullptr)
		{
			b2Vec2 graphPos;
			graphPos.Set(entity->getPosition().x / WorldScale, entity->getPosition().y / WorldScale);
			rb->SetPosition(graphPos, entity->getRotation());
		}
	}


    int velocityIterations = 6;
    int positionIterations = 2;
	world.Step(deltaTime, velocityIterations, positionIterations);
    
	//set entity position to rb position
    for(A_Entity* entity : app->GetEntities())
	{
		MyGameEngine::RigidBody* rb = app->GetComponentFromEntity<MyGameEngine::RigidBody>(entity);

		if (rb != nullptr)
		{
			sf::Vector2f worldPos;
			worldPos.x = rb->GetPosition().x * WorldScale;
			worldPos.y = rb->GetPosition().y * WorldScale;
			entity->SetEntityPosition(worldPos);
		}
	}
}

b2World* MyGameEngine::Physics::GetWorld()
{
	return &world;
}
