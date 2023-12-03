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
		b2Body* _child;
		b2Vec2 _childOffset;
		struct bodyData {
			int bodyType;
		};
		bodyData* data;

	public:
		RigidBody();
		~RigidBody();
		// Setters
		void SetBodyType(b2BodyType type);
		void SetPosition(b2Vec2 position, float angle);
		void SetLocalPosition(b2Vec2 position, float angle);
		void SetLinearVelocity(b2Vec2 velocity);
		void SetAngularVelocity(float velocity);
		void AddForce(b2Vec2 force);
		void Move(b2Vec2 velocity, float maxSpeed);
		void Jump(float impulse);
		void StopVelocityX();
		void ChildrenFollow(b2Body* childBody, b2Vec2 offset);
		void SetUserData(int bodyType);

		// Getters
		b2Vec2 GetPosition();
		float GetAngle();
		b2Vec2 GetLinearVelocity();
		float GetAngularVelocity();
		b2Body* GetBody();
		bodyData* GetBodyData() {
			return data;
		}

		void Awake() override;
		void Start() override;
		void Update(float deltaTime) override;
		void LateUpdate(float deltaTime) override;
	};
}

