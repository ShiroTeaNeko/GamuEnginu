#pragma once

#include "A_Component.h"
#include <SFML/Graphics.hpp>
namespace MyGameEngine {
	class MeshFilter : public A_Component
	{
	private:
	protected:
	public:
		sf::Drawable* drawable;
		sf::Drawable* GetObject() { return drawable; }
		MeshFilter();
		void Awake() override;
		void Start() override;
		void Update(float deltaTime) override;
		void LateUpdate(float deltaTime) override;
	};
}