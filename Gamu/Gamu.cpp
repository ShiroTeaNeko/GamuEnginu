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

	MyGameEngine::A_Entity* a = app->CreateEntity("Entity1");
	a->SetEntityPosition(sf::Vector2f(-200, -350));
	MyGameEngine::A_Entity* b = app->CreateEntity("Entity2");
	MyGameEngine::A_Entity* c = app->CreateEntity("EntityForCamera");

	sf::CircleShape circle(150);
	sf::Texture texture = resourceManager->getTexture("tree");
	sf::Sprite sprite;
	sprite.setTexture(texture);
	MyGameEngine::MeshFilter* mesh1 = new  MyGameEngine::MeshFilter();
	mesh1->drawable = &sprite;

	sf::RectangleShape rectangle(Vector2f(200, 150));
	MyGameEngine::MeshFilter* mesh2 = new  MyGameEngine::MeshFilter();
	mesh2->drawable = &rectangle;

	MyGameEngine::Camera* camera = new MyGameEngine::Camera();
	camera->_zoomLevel = 1.0f;
	camera->_rotation = .0f;
	camera->_centerPos = sf::Vector2f(0, 0);

	MyGameEngine::RigidBody* rigidBody = new MyGameEngine::RigidBody();
	rigidBody->SetPosition(b2Vec2(0,0), 0);
	rigidBody->SetBodyType(b2_dynamicBody);

	MyGameEngine::BoxCollider* boxCollider = new MyGameEngine::BoxCollider();
	boxCollider->SetSize(200, 150);
	boxCollider->setDensity(1.0f);
	boxCollider->setFriction(0.3f);

	boxCollider->createFixture(rigidBody->GetBody());


	app->CreateComponent<MyGameEngine::RenderComponent>(a);
	app->AttachComponentToEntity(mesh1, a);
	app->AttachComponentToEntity(rigidBody, a);
	app->AttachComponentToEntity(boxCollider, a);
	//app.CreateComponent<MyGameEngine::RenderComponent>(b);
	//app.AttachComponentToEntity(mesh2, b);
	app->CreateComponent<MyGameEngine::Camera>(c);
	app->AttachComponentToEntity(camera, c);
	c->setPosition(sf::Vector2f(0, 0));

	app->Awake(1280, 720, "app");
	app->Start();
	app->Loop(*camera);
}