#include "pch.h"
#include "BoxCollider.h"

MyGameEngine::BoxCollider::BoxCollider() : _width(1), _height(1)
{
	shape.SetAsBox(_height / 2, _height / 2);
}

MyGameEngine::BoxCollider::~BoxCollider()
{

}

void MyGameEngine::BoxCollider::SetHeight(float height)
{
}

void MyGameEngine::BoxCollider::Awake()
{
}

void MyGameEngine::BoxCollider::Start()
{
}

void MyGameEngine::BoxCollider::Update(float deltaTime)
{
}

void MyGameEngine::BoxCollider::LateUpdate(float deltaTime)
{
}

b2Shape* MyGameEngine::BoxCollider::GetColliderShape()
{
	shape.SetAsBox(_width / 2, _height / 2);
	return &shape;
}

void MyGameEngine::BoxCollider::SetSize(float width, float height)
{
	_height = height;
	_width = width;

	shape.SetAsBox(_width / 2, _height / 2);
}
