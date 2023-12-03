#include "pch.h"
#include "CharacterController.h"
#include "RigidBody.h"

MyGameEngine::CharacterController::CharacterController()
{
	//_speed = speed;
}

MyGameEngine::CharacterController::~CharacterController()
{
}

void MyGameEngine::CharacterController::Awake()
{
}

void MyGameEngine::CharacterController::Start()
{
}

void MyGameEngine::CharacterController::Update(float deltaTime)
{
	MyGameEngine::Application* app = MyGameEngine::Application::GetInstance();
	MyGameEngine::RigidBody* rb = app->GetComponentFromEntity<MyGameEngine::RigidBody>(entity);
	//std::cout << state << std::endl;
	//std::cout << _isGrounded << std::endl;

	switch (state)
	{
	case STAND:

		//std::cout << "stand" << std::endl;
		rb->StopVelocityX();

		if (!_isGrounded) {
			state = JUMP;
			break;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q) != sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			state = WALK;
			break;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
			std::cout << "jump" << std::endl;
			_isGrounded = false;
			rb->Jump(2500000);
			state = JUMP;
			break;
		}

		break;
	case JUMP:
		//std::cout << "jump state" << std::endl;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q) == sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			rb->StopVelocityX();
			//break;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			/*if (pushesRightWall)
				setXSpeed(0.0f);
			else*/
			rb->Move(b2Vec2(1000000, 0), 300.0f);
			//std::cout << "velocity is " << rb->GetLinearVelocity().y << std::endl;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
			/*if (pushesLeftWall)
				setXSpeed(0.0f);
			else*/
			rb->Move(b2Vec2(-1000000, 0), 300.0f);
		}
		//std::cout << _isGrounded << std::endl;
		if (_isGrounded) 
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q) == sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
				state = STAND;
				//std::cout << "stand" << std::endl;
				rb->StopVelocityX();
			}
			else {
				state = WALK;
			}
			break;
		}
		break;
	case WALK:

		//std::cout << "walk" << std::endl;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q) == sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			state = STAND;
			rb->Move(b2Vec2(0, 0), 300.0f);
			break;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			//check collid right wall
			/*if (againstRightWall)
				setXSpeed(0.0f);
			else*/
			rb->Move(b2Vec2(2500000, 0), 300.0f);
			//std::cout << "velocity is " << rb->GetLinearVelocity().y << std::endl;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
			//check collid left wall
			/*if (pushesLeftWall)
				setXSpeed(0.0f);
			else*/
			rb->Move(b2Vec2(-2500000, 0), 300.0f);
			//break;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
			rb->Jump(100000);
			state = JUMP;
			break;
		}
		else if (!_isGrounded) {
			state = JUMP;
			break;
		}
		break;
	}
}


void MyGameEngine::CharacterController::LateUpdate(float deltaTime)
{
}
