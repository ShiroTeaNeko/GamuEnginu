#pragma once
#include "A_Component.h"
#include <SFML/Graphics.hpp>

namespace MyGameEngine {
	class Camera : public A_Component
	{
	private:

	protected:

	public:
		Camera();
		sf::View SetView(sf::Vector2u windowSize);

		float _zoomLevel{};
		float _rotation{};
		sf::Vector2f _centerPos;

		void Awake() override;
		void Start() override;
		void Update(float deltaTime) override;
		void LateUpdate(float deltaTime) override;
	};
}

