#pragma once
#include <SFML/Graphics.hpp>
#include <string>

namespace MyGameEngine {
	class A_Component
	{
	protected:
		const static int _id = 0;
	public:
		int getId() {
			return _id;
		}
		A_Component();
		virtual void Awake() = 0;
		virtual void Start() = 0;
		virtual void Update(float deltaTime) = 0;
		virtual void LateUpdate(float deltaTime) = 0;
	};
}