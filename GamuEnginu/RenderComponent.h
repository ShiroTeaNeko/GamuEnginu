#pragma once
#include "A_Component.h"
#include <SFML/Graphics.hpp>
#include "MeshFilter.h"


using namespace sf;

namespace MyGameEngine {
	class RenderComponent : public A_Component
	{
	private:
		MeshFilter* m_drawableObj;
	protected:
		sf::Transformable transform;
	public:

		RenderComponent();
		void Render(sf::RenderWindow& ref, sf::RenderStates& state);

		void SetMeshToRender(MeshFilter* a_meshfilter) { m_drawableObj = a_meshfilter; }


		void Awake() override;
		void Start() override;
		void Update(float deltaTime)override;
		void LateUpdate(float deltaTime)override;

	};
}

