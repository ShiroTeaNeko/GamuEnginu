#pragma once
#include "A_Component.h"
#include "box2d/box2d.h"
#include "Application.h"

namespace MyGameEngine {
	class RigidBody : public A_Component
	{
	private:
	protected:
		b2BodyDef bodyDef;
		b2Body* body;
	public:
		RigidBody();
		~RigidBody();
		// Setters
		void SetBodyType(b2BodyType type);
		void SetPosition(b2Vec2 position, float angle);
		void SetLinearVelocity(b2Vec2 velocity);
		void SetAngularVelocity(float velocity);
		//void SetUserData(void* data);

		// Getters
		b2Vec2 GetPosition();
		float GetAngle();
		b2Vec2 GetLinearVelocity();
		float GetAngularVelocity();
		b2Body* GetBody();

		void Awake() override;
		void Start() override;
		void Update(float deltaTime) override;
		void LateUpdate(float deltaTime) override;
	};
}

