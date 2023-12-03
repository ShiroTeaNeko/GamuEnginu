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
	if (_child != nullptr)
	{
		_child->SetTransform(body->GetTransform().p + _childOffset, 0);
		//std::cout << "child x : " << _child->GetTransform().p.x << std::endl;
		//std::cout << "child y : " << _child->GetTransform().p.y << std::endl;
	}
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

void MyGameEngine::RigidBody::SetLocalPosition(b2Vec2 position, float angle)
{
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

void MyGameEngine::RigidBody::AddForce(b2Vec2 force)
{
	if (body == nullptr) {
		bodyDef.linearVelocity += force;
	}
	else {
		body->ApplyForceToCenter(force, true);
	}
}

void MyGameEngine::RigidBody::Move(b2Vec2 velocity, float maxSpeed)
{
	if (body == nullptr) {
		bodyDef.position += velocity;
	}
	else {
		if (body->GetLinearVelocity().x < maxSpeed)
		{
			//std::cout << body->GetLinearVelocity().y << std::endl;
			//body->SetLinearVelocity(body->GetLinearVelocity()+velocity);
			body->ApplyForceToCenter(velocity, true);
			//std::cout << body->GetLinearVelocity().y << std::endl;
		}
		else
		{
			//body->SetLinearVelocity(b2Vec2(maxSpeed, GetLinearVelocity().y));

			body->ApplyForceToCenter(velocity, true);
			//std::cout << "2" << std::endl;
		}
	}
}

void MyGameEngine::RigidBody::Jump(float impulse)
{
	//if (body == nullptr) {
		//bodyDef.linearVelocity += velocity;
	//}
	//else {
		//body->SetLinearVelocity(b2Vec2(body->GetLinearVelocity().x, -impulse));
		body->ApplyLinearImpulseToCenter(b2Vec2(0, -impulse), true);
		 //std::cout << "velocity is " << body->GetLinearVelocity().y << std::endl;
	//}
}

void MyGameEngine::RigidBody::StopVelocityX()
{
	if (body == nullptr) {
		bodyDef.linearVelocity.x = 0;
	}
	else {
		body->SetLinearVelocity(b2Vec2(0, body->GetLinearVelocity().y));
		//std::cout << "velocity is " << body->GetLinearVelocity().y << std::endl;
	}
}

void MyGameEngine::RigidBody::ChildrenFollow(b2Body* childBody, b2Vec2 offset)
{
	if (childBody != nullptr) {
		_child = childBody;
		_childOffset = offset;
	}
}

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


void MyGameEngine::RigidBody::SetUserData(int fixtureType)
{
	data = new bodyData();
	data->bodyType = fixtureType;
}