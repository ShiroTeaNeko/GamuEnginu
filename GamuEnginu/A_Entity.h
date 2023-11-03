#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include "A_Component.h"
#include "RenderComponent.h"
#include "Camera.h"

namespace MyGameEngine {
	class A_Entity : public sf::Transformable
	{

	private:
	protected:
		sf::Transformable transform;
		static int _id;
		std::string _name;
		RenderComponent* _renderComponent;
	public:
		std::vector<MyGameEngine::A_Component*> _components;
		A_Entity(std::string name);
		int getId() {
			return _id;
		}
		std::string getName() {
			return _name;
		}
		void ManageRenderer(sf::RenderWindow& rw);
		void ManageCamera(sf::RenderWindow& rw, Camera& camera);

		void Awake();
		void Start();
		void Update(float deltaTime);
		void LateUpdate(float deltaTime);

		//check if entity has specific component
		template <typename T>
		bool HasComponent() const
		{
			return std::find_if(_components.begin(), _components.end(), [](A_Component* component) { return dynamic_cast<T*>(component); }) != _components.end();
		}

//get specific component with GetComponent<MyGameEngine::RigidBody>()
		void SetEntityPosition(sf::Vector2f position);
		sf::Vector2f GetEntityPosition();
	};
}

