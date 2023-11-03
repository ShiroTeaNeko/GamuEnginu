#pragma once
#include "A_Collider.h"

namespace MyGameEngine {
	class BoxCollider : public A_Collider
	{
	private:
	protected:
		b2PolygonShape shape;
		float _height;
		float _width;
	public:
		BoxCollider();
		~BoxCollider();
		
		//setters
		void SetHeight(float height);

		void Awake() override;
		void Start() override;
		void Update(float deltaTime) override;
		void LateUpdate(float deltaTime) override;
		b2Shape* GetColliderShape() override;
		void SetSize(float width, float height);
	};
}

