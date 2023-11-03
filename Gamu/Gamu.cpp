#include <SFML/Graphics.hpp>
#include <GamuEnginu/Application.h>
#include <GamuEnginu/MeshFilter.h>
#include <GamuEnginu/Camera.h>
#include <GamuEnginu/ResourceManager.h>
#include <GamuEnginu/RigidBody.h>
#include <GamuEnginu/BoxCollider.h>
#include <yaml-cpp/yaml.h>
#include <GamuEnginu/Physics.h>


int main()
{
	MyGameEngine::Application* app = new MyGameEngine::Application();


	MyGameEngine::ResourceManager* resourceManager = MyGameEngine::ResourceManager::GetInstance();
	resourceManager->init("config.yaml");


	//Setup Tree
	MyGameEngine::A_Entity* treeEntity = app->CreateEntity("TreeEntity");
	app->CreateComponent<MyGameEngine::RenderComponent>(*treeEntity);
	MyGameEngine::RigidBody* rigidBody = app->CreateComponent<MyGameEngine::RigidBody>(*treeEntity);
	MyGameEngine::BoxCollider* boxCollider = app->CreateComponent<MyGameEngine::BoxCollider>(*treeEntity);
	//treeEntity->SetEntityPosition(sf::Vector2f(-200, -350));
	sf::Texture texture = resourceManager->getTexture("tree");
	sf::Sprite sprite;
	sprite.setTexture(texture);
	MyGameEngine::MeshFilter* mesh1 = new  MyGameEngine::MeshFilter();
	mesh1->drawable = &sprite;
	app->AttachComponentToEntity(mesh1, treeEntity);
	rigidBody->SetPosition(b2Vec2(0,0), 0);
	rigidBody->SetBodyType(b2_dynamicBody);
	boxCollider->SetSize(512, 512);
	boxCollider->setDensity(1.0f);
	boxCollider->setFriction(0.3f);
	boxCollider->createFixture(rigidBody->GetBody());
	
	//Setup Ground
	MyGameEngine::A_Entity* groundEntity = app->CreateEntity("GroundEntity");
	app->CreateComponent<MyGameEngine::RenderComponent>(*groundEntity);
	MyGameEngine::RigidBody* rigidBody2 = app->CreateComponent<MyGameEngine::RigidBody>(*groundEntity);
	MyGameEngine::BoxCollider* boxCollider2 = app->CreateComponent<MyGameEngine::BoxCollider>(*groundEntity);
	//groundEntity->SetEntityPosition(sf::Vector2f(-400, 0));
	sf::RectangleShape rectangle(Vector2f(800, 150));
	MyGameEngine::MeshFilter* mesh2 = new  MyGameEngine::MeshFilter();
	mesh2->drawable = &rectangle;
	app->AttachComponentToEntity(mesh2, groundEntity);
	b2Vec2 pos(0, 710);
	rigidBody2->SetPosition(pos, 0);
	rigidBody2->SetBodyType(b2_staticBody);
	boxCollider2->SetSize(2000, 100);
	boxCollider2->createFixture(rigidBody2->GetBody());

	//Setup Camera
	//MyGameEngine::A_Entity* cameraEntity = app->CreateEntity("EntityForCamera");
	//cameraEntity->setPosition(sf::Vector2f(0, 0));
	MyGameEngine::Camera* camera = app->CreateComponent<MyGameEngine::Camera>(*treeEntity);
	camera->EntityToFollow(treeEntity);
	camera->SetZoom(0.5f);


	//app->CreateComponent<MyGameEngine::Camera>(cameraEntity);
	//app->AttachComponentToEntity(camera, treeEntity);

	app->Awake(1280, 720, "app");
	app->Start();
	app->Loop();
}