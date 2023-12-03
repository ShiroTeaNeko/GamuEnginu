#include <Gamu/Gamu.h>


int main()
{
	MyGameEngine::Application* app = new MyGameEngine::Application();

	MyGameEngine::ResourceManager* resourceManager = MyGameEngine::ResourceManager::GetInstance();
	resourceManager->init("config.yaml");

	//setup background
	sf::Texture textureBackground = resourceManager->getTexture("background");
	sf::Sprite spriteBackground(textureBackground);
	spriteBackground.setScale(2.0f, 2.0f);
	sf::Vector2u size = textureBackground.getSize();
	spriteBackground.setOrigin(400, 125);

	DrawBackground(app, resourceManager, &spriteBackground);

	//Setup Character
	MyGameEngine::A_Entity* character = app->CreateEntity("Character");
	app->CreateComponent<MyGameEngine::RenderComponent>(*character);
	MyGameEngine::RigidBody* rigidBody = app->CreateComponent<MyGameEngine::RigidBody>(*character);
	MyGameEngine::RigidBody* rigidBodyFoot = app->CreateComponent<MyGameEngine::RigidBody>(*character);
	MyGameEngine::BoxCollider* boxCollider = app->CreateComponent<MyGameEngine::BoxCollider>(*character);
	MyGameEngine::CharacterController* characterController = app->CreateComponent<MyGameEngine::CharacterController>(*character);
	characterController->SetEntity(character);
	sf::Texture texture = resourceManager->getTexture("character");
	sf::IntRect rectSourceSprite(0, 0, 96, 96);
	sf::Sprite sprite(texture, rectSourceSprite);
	MyGameEngine::MeshFilter* mesh1 = new  MyGameEngine::MeshFilter();
	mesh1->drawable = &sprite;
	app->AttachComponentToEntity(mesh1, character);

	//Setup Foot
	rigidBodyFoot->SetBodyType(b2_dynamicBody);
	rigidBody->SetUserData(1); // 1 = character
	boxCollider->SetSize(20, 20);
	boxCollider->setSensor(true);
	//boxCollider->createFixture(rigidBodyFoot->GetBody());

	//Setup Body
	rigidBody->SetPosition(b2Vec2(0,300), 0);
	rigidBody->SetBodyType(b2_dynamicBody);
	rigidBody->ChildrenFollow(rigidBodyFoot->GetBody(), b2Vec2(0, 96));
	rigidBody->SetUserData(1); // 1 = character
	boxCollider->SetSize(96, 96);
	boxCollider->setDensity(1.0f);
	boxCollider->setFriction(0.3f);
	boxCollider->setSensor(false);
	boxCollider->createFixture(rigidBody->GetBody());
	MyGameEngine::CollisionComponent* collisionComponent = app->CreateComponent<MyGameEngine::CollisionComponent>(*character);
	
	//Setup Ground
	sf::Texture textureGround = resourceManager->getTexture("environnement");
	sf::IntRect rectSourceSpriteGround(0, 0, 64, 64);
	sf::Sprite spriteGround(textureGround, rectSourceSpriteGround);

	//setup platforms
	sf::Texture texturePlatform = resourceManager->getTexture("environnement");
	sf::IntRect rectSourceSpritePlatform(64*6, 0, 64, 64);
	sf::Sprite spritePlatform(texturePlatform, rectSourceSpritePlatform);


	PlaceGrounds(app, resourceManager, &spriteGround);
	PlacePlatform(app, resourceManager, &spritePlatform);



	//Setup Camera
	MyGameEngine::Camera* camera = app->CreateComponent<MyGameEngine::Camera>(*character);
	camera->EntityToFollow(character);
	camera->SetZoom(1.0f);
	camera->SetSize(1280, 720);

	app->Awake(1280, 720, "Platformer 2D");
	app->Start();
	app->Loop();
}

//create a ground
void CreateGrounds(MyGameEngine::Application* app, MyGameEngine::ResourceManager* rm,int nb, int sizeX, int sizeY, int posX, int posY, sf::Drawable* drawable)
{
	MyGameEngine::A_Entity* groundEntity = app->CreateEntity("GroundEntity" + std::to_string(nb));
	app->CreateComponent<MyGameEngine::RenderComponent>(*groundEntity);
	MyGameEngine::RigidBody* rigidBody2 = app->CreateComponent<MyGameEngine::RigidBody>(*groundEntity);
	MyGameEngine::BoxCollider* boxCollider2 = app->CreateComponent<MyGameEngine::BoxCollider>(*groundEntity);
	MyGameEngine::MeshFilter* mesh2 = new  MyGameEngine::MeshFilter();
	mesh2->drawable = drawable;
	app->AttachComponentToEntity(mesh2, groundEntity);
	b2Vec2 pos(posX, posY);
	rigidBody2->SetPosition(pos, 0);
	rigidBody2->SetBodyType(b2_staticBody);
	rigidBody2->SetUserData(3); // 3 = grounds
	boxCollider2->SetSize(sizeX, 100);
	boxCollider2->createFixture(rigidBody2->GetBody());
}

void PlaceGrounds(MyGameEngine::Application* app, MyGameEngine::ResourceManager* rm, sf::Drawable* drawable) {
	CreateGrounds(app, rm,1, 64, 64, 0, 710, drawable);
	CreateGrounds(app, rm,2, 64, 64, 64, 710, drawable);
	CreateGrounds(app, rm,3, 64, 64, 64*2, 710, drawable);
	CreateGrounds(app, rm,4, 64, 64, 64*3, 710, drawable);
	CreateGrounds(app, rm,5, 64, 64, 64*4, 710, drawable);
	CreateGrounds(app, rm,6, 64, 64, 64*5, 710, drawable);
	CreateGrounds(app, rm,7, 64, 64, 64*6, 710, drawable);
	CreateGrounds(app, rm,8, 64, 64, 64*7, 710, drawable);
	CreateGrounds(app, rm,9, 64, 64, 64*8, 710, drawable);
	CreateGrounds(app, rm,10, 64, 64, 64*9, 710, drawable);
	CreateGrounds(app, rm,11, 64, 64, 64*10, 710, drawable);
	CreateGrounds(app, rm,12, 64, 64, 64*11, 710, drawable);
	CreateGrounds(app, rm,13, 64, 64, 64*12, 710, drawable);
	CreateGrounds(app, rm,14, 64, 64, 64*13, 710, drawable);
	CreateGrounds(app, rm,15, 64, 64, 64*14, 710, drawable);
	CreateGrounds(app, rm,16, 64, 64, 64*15, 710, drawable);
}

void PlacePlatform(MyGameEngine::Application* app, MyGameEngine::ResourceManager* rm, sf::Drawable* drawable) {
	CreateGrounds(app, rm,22, 64, 64, 64 * 5, 500, drawable);
	CreateGrounds(app, rm,23, 64, 64, 64 * 6, 500, drawable);
	CreateGrounds(app, rm,24, 64, 64, 64 * 7, 500, drawable);
	CreateGrounds(app, rm,25, 64, 64, 64 * 11, 500, drawable);
	CreateGrounds(app, rm,26, 64, 64, 64 * 12, 500, drawable);
	CreateGrounds(app, rm,27, 64, 64, 64 * 13, 500, drawable);
}

void DrawBackground(MyGameEngine::Application* app, MyGameEngine::ResourceManager* rm, sf::Drawable* drawable) {
	MyGameEngine::A_Entity* backgroundEntity = app->CreateEntity("BackgroundEntity");
	app->CreateComponent<MyGameEngine::RenderComponent>(*backgroundEntity);
	MyGameEngine::MeshFilter* mesh = new  MyGameEngine::MeshFilter();
	mesh->drawable = drawable;
	app->AttachComponentToEntity(mesh, backgroundEntity);
}