#include "pch.h"
#include "A_Collider.h"

MyGameEngine::A_Collider::A_Collider()
{
}

MyGameEngine::A_Collider::~A_Collider()
{
}

void MyGameEngine::A_Collider::createFixture(b2Body* body)
{
	fixtureDef.shape = GetColliderShape();
	fixture = body->CreateFixture(&fixtureDef);
}

void MyGameEngine::A_Collider::setDensity(float density)
{
	if (fixture == nullptr) {
		fixtureDef.density = density;
	}
	else {
		fixture->SetDensity(density);
	}
}

void MyGameEngine::A_Collider::setFriction(float friction)
{
	if (fixture == nullptr) {
		fixtureDef.friction = friction;
	}
	else {
		fixture->SetFriction(friction);
	}
}
