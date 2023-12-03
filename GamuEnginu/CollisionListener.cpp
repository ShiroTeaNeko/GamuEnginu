#include "pch.h"
#include "CollisionListener.h"
#include <iostream>
#include "CollisionComponent.h"
#include "A_Entity.h"
#include "CharacterController.h"
#include "Application.h"

void MyGameEngine::CollisionListener::BeginContact(b2Contact* contact)
{
	MyGameEngine::Application* app = MyGameEngine::Application::GetInstance();
	CharacterController* cc = app->GetComponentFromEntity<CharacterController>(app->GetEntityByName("Character"));

	b2Body* bodyA = contact->GetFixtureA()->GetBody();

	for (A_Entity* entity : MyGameEngine::Application::GetInstance()->GetEntities()) {
		for (A_Component* component : entity->_components) {

			RigidBody* currentRb = dynamic_cast<RigidBody*>(component);

			if (currentRb) {

				if (currentRb->GetBody() == bodyA) {

					if (currentRb->GetBodyData()->bodyType == 1)
					{
						//std::cout << "hit 1 " << std::endl;
						cc->setGrounded(true);
					}
					for (A_Component* componentInEntityOfRigidbody : entity->_components) {

						ICollisionable* currentICollisionable = dynamic_cast<ICollisionable*>(componentInEntityOfRigidbody);

						if (currentICollisionable) {
							currentICollisionable->BeginCollision(contact);
						}
					}
				}
			}
		}
	}

	b2Body* bodyB = contact->GetFixtureB()->GetBody();

	for (A_Entity* entity : MyGameEngine::Application::GetInstance()->GetEntities()) {
		for (A_Component* component : entity->_components) {

			RigidBody* currentRb = dynamic_cast<RigidBody*>(component);

			if (currentRb) {

				if (currentRb->GetBody() == bodyB) {

					if (currentRb->GetBodyData()->bodyType == 1)
					{
						//std::cout << "hit 2" << std::endl;
						cc->setGrounded(true);
					}
					for (A_Component* componentInEntityOfRigidbody : entity->_components) {

						ICollisionable* currentICollisionable = dynamic_cast<ICollisionable*>(componentInEntityOfRigidbody);

						if (currentICollisionable) {
							currentICollisionable->BeginCollision(contact);
						}
					}
				}
			}
		}
	}

    //std::cout << "Collision has started" << std::endl;
}

void MyGameEngine::CollisionListener::EndContact(b2Contact* contact)
{
    /*b2BodyUserData* userDataA = &contact->GetFixtureA()->GetBody()->GetUserData();
	b2BodyUserData* userDataB = &contact->GetFixtureB()->GetBody()->GetUserData();*/

	//std::cout << "Collision has ended" << std::endl;
}
