#include "pch.h"
#include "GameFramework.h"
#include "ObjectContainer.h"
#include "GameObject.h"
#include "Collision.h"

GameFramework::GameFramework()
{
	this->Create();
	CollisionResult::reserve(50);
}

GameFramework::~GameFramework()
{
}

void GameFramework::Start()
{
}

void GameFramework::End()
{
}

void GameFramework::Create()
{
	this->container = new ObjectContainer(this);
}

void GameFramework::Destory()
{
	delete this->container;
}

void GameFramework::Update(float deltaTime)
{
	this->container->player->Update(deltaTime);
}

void GameFramework::Draw(PaintInfo info)
{
	this->container->player->Draw(info);
}

bool GameFramework::CheckCollision(GameObject& obj)
{
	return false;
}

Vec2DF GameFramework::GetDisplaySize() const
{
	return Vec2DF();
}

Vec2DF GameFramework::GetMargin() const
{
	return Vec2DF();
}

void GameFramework::MouseInput(Vec2DU MousePos, UINT iMessage)
{
}
