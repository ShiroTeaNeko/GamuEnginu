#pragma once
#include "A_Component.h"
#include "ICollisionable.h"
#include "Application.h"

namespace MyGameEngine
{
	class CollisionComponent : public A_Component, public ICollisionable
	{
	private:
		//void* owner;
	public:
		CollisionComponent();
		~CollisionComponent();
		/*void* GetOwner() {
			return owner;
		}*/

		void BeginCollision(b2Contact* contact) override;
		void EndCollision(b2Contact* contact) override;
		void Awake() override;
		void Start() override;
		void Update(float deltaTime) override;
		void LateUpdate(float deltaTime) override;
	};
}

