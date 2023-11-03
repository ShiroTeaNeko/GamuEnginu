#pragma once
#include <SFML/Graphics.hpp>
#include "A_Component.h"

namespace MyGameEngine {
	class A_Entity;
	class Camera : public A_Component
	{
	private:

	protected:
		A_Entity* entityToFollow;
	public:
		Camera();
		virtual void EntityToFollow(A_Entity* entityToFollow);
		
		virtual void SetZoom(float zoom);
		virtual void SetSize(float sizeX, float sizeY);

		virtual void SetViewport(sf::FloatRect viewport);

		virtual void SetRotation(float rotation);
		virtual void Rotate(float rotateAmount);
		sf::View view;

		void Awake() override;
		void Start() override;
		void Update(float deltaTime) override;
		void LateUpdate(float deltaTime) override;
	};
}

