#pragma once
#include "A_Component.h"
#include "box2d/box2d.h"

namespace MyGameEngine {
	class A_Collider : public A_Component
	{
	private:
	protected:
		b2FixtureDef fixtureDef;
	    b2Fixture* fixture;
	public:
		A_Collider();
		~A_Collider();
		void createFixture(b2Body* body);
		virtual b2Shape* GetColliderShape() = 0;
		//setters
		void setDensity(float density);
		void setFriction(float friction);
	};
}

