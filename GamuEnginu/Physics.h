#pragma once
#include "box2d/box2d.h"

namespace MyGameEngine {
	class Physics
	{
	private:
	protected:
		b2Vec2 gravity;
		b2World world;
	public:
		Physics();
		~Physics();
		void Update(float deltaTime);
		b2World* GetWorld();
		inline static float WorldScale = 1;
	};
}

