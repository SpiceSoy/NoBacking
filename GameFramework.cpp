#include "pch.h"
#include "GameFramework.h"
#include "ObjectContainer.h"
#include "GameObject.h"
#include "Collision.h"

GameFramework::GameFramework()
{
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
	CollisionResult::reserve(50);
	this->Load();
	this->container = new ObjectContainer(this);
}

void GameFramework::Destory()
{
	delete this->container;
}

void GameFramework::Update(float deltaTime)
{
	this->container->player->Update(deltaTime);
	this->container->sandBag->Update(deltaTime);
}

void GameFramework::Draw(PaintInfo info)
{
	info.DrawCollision = isDrawCollision;
	this->container->sandBag->Draw(info);
	this->container->player->Draw(info);
}

bool GameFramework::CheckCollision(GameStateObject& obj)
{
	if (this->container != nullptr)
	{
		return this->container->player->CheckCollision(*this->container->sandBag);
	}
}

void GameFramework::ToggleDebugCollision()
{
	isDrawCollision = !isDrawCollision;
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
