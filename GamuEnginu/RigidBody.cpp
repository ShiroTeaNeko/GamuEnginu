#include "pch.h"
#include "Physics.h"
#include "RigidBody.h"

void MyGameEngine::RigidBody::Awake()
{
}

void MyGameEngine::RigidBody::Start()
{

}

void MyGameEngine::RigidBody::Update(float deltaTime)
{
}

void MyGameEngine::RigidBody::LateUpdate(float deltaTime)
{
}

MyGameEngine::RigidBody::RigidBody()
{
	body = MyGameEngine::Application::GetInstance()->getphysics()->GetWorld()->CreateBody(&bodyDef);
}

MyGameEngine::RigidBody::~RigidBody()
{
}

void MyGameEngine::RigidBody::SetBodyType(b2BodyType type)
{
	body->SetType(type);
}

void MyGameEngine::RigidBody::SetPosition(b2Vec2 position, float angle)
{
	MyGameEngine::Application::GetEntity(this)->setPosition(sf::Vector2f(position.x * MyGameEngine::Physics::WorldScale, position.y * MyGameEngine::Physics::WorldScale));

	if (body == nullptr) {
		bodyDef.position = position;
		bodyDef.angle = angle;
	}
	else {

		body->SetTransform(position, angle);
	}
}

void MyGameEngine::RigidBody::SetLinearVelocity(b2Vec2 velocity)
{
	if (body == nullptr) {
		bodyDef.linearVelocity = velocity;
	}
	else {
		body->SetLinearVelocity(velocity);
	}
}

void MyGameEngine::RigidBody::SetAngularVelocity(float velocity)
{
	if (body == nullptr) {
		bodyDef.angularVelocity = velocity;
	}
	else {
		body->SetAngularVelocity(velocity);
	}
}

/*void MyGameEngine::RigidBody::SetUserData(void* data)
{
	body->SetUserData(data);
}*/

b2Vec2 MyGameEngine::RigidBody::GetPosition()
{
	if (body == nullptr) {
		return bodyDef.position;
	}
	else {
		return body->GetTransform().p;
	}
}

float MyGameEngine::RigidBody::GetAngle()
{
	if (body == nullptr) {
		return bodyDef.angle;
	}
	else {
		return body->GetAngle();
	}
}

b2Vec2 MyGameEngine::RigidBody::GetLinearVelocity()
{
	if (body == nullptr) {
		return bodyDef.linearVelocity;
	}
	else {
		return body->GetLinearVelocity();
	}
}

float MyGameEngine::RigidBody::GetAngularVelocity()
{
	if (body == nullptr) {
		return bodyDef.angularVelocity;
	}
	else {
		return body->GetAngularVelocity();
	}
}

b2Body* MyGameEngine::RigidBody::GetBody()
{
	if (body == nullptr) 
	{
		return body = MyGameEngine::Application::GetInstance()->getphysics()->GetWorld()->CreateBody(&bodyDef);
	}
	else 
	{
		return body;
	}
}
