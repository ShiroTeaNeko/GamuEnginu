#pragma once
#include <SFML/Graphics.hpp>
#include "A_Entity.h"
#include "A_Component.h"
#include "Physics.h"
#include "Camera.h"

namespace MyGameEngine {
	class Application
	{
	private:
	protected:
		sf::RenderWindow window;
		std::vector<MyGameEngine::A_Entity*> _entities;
		std::vector<MyGameEngine::A_Component*> _components;
		std::map<A_Entity*, A_Component*> _linkComponentAndEntity;
		Physics _physics;
		static Application* _instance;
	public:
		Application();
		~Application();
		void Awake(int windowSizeX, int windowSizeY, std::string windowName);
		void Start();
		void Loop(Camera& camera);


		A_Entity* CreateEntity(std::string name);

		static Application* GetInstance();

		template<typename T>
		T* CreateComponent(A_Entity* entity)
		{
			T* component = new T();
			_linkComponentAndEntity[entity] = component;
			entity->_components.push_back(component);
			return component;
		}


		void AttachComponentToEntity(A_Component* comp, A_Entity* entity)
		{
			entity->_components.push_back(comp);
		}

		template<typename T>
		std::string GenerateID(A_Entity* parent)
		{
			parent->_id++;
		}
		//get all components
		std::vector<A_Component*> GetComponents()
		{
			return _components;
		}

		//get all entities 
		std::vector<A_Entity*> GetEntities()
		{
			return _entities;
		}

		//get all components from entity
		template<typename T>
		std::vector<T*> GetComponentsFromEntity(A_Entity* entity)
		{
			std::vector<T*> components;
			for (auto component : entity->_components)
			{
				T* castedComponent = dynamic_cast<T*>(component);
				if (castedComponent != nullptr)
				{
					components.push_back(castedComponent);
				}
			}
			return components;
		}

		//get component from entity
		template<typename T>
		T* GetComponentFromEntity(A_Entity* entity)
		{
			for (auto component : entity->_components)
			{
				T* castedComponent = dynamic_cast<T*>(component);
				if (castedComponent != nullptr)
				{
					return castedComponent;
				}
			}
			return nullptr;
		}

		Physics* getphysics()
		{
			return &_physics;
		}

		static A_Entity* GetEntity(A_Component* component);
	};

}