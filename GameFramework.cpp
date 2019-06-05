#include "pch.h"
#include "GameFramework.h"
#include "ObjectContainer.h"
#include "GameObject.h"
#include "Collision.h"
#include "Effect.h"
#include "Player.h"
#include "Camera.h"
#include "SoundSystem.h"

GameFramework::GameFramework()
{
}

GameFramework::~GameFramework()
{
	Destory();
}

void GameFramework::Start()
{
}

void GameFramework::End()
{
}

void GameFramework::Create()
{
	SoundSystem::OnInitalize();
	CollisionResult::reserve(50);
	this->Load();
	this->container = new ObjectContainer(this);
	SoundSystem::PlaySound("zero");

}

void GameFramework::Destory()
{
	SoundSystem::OnDestory();
	delete this->container;
}

void GameFramework::Update(float deltaTime)
{
	SoundSystem::Update();
	this->container->sandBag->Update(deltaTime);
	this->container->player->Update(deltaTime);
	for (auto& ptr : container->Effects)
	{
		ptr->Update(deltaTime);
	}
	//this->GetCamera().Teleport(this->GetPlayer().transform.Position - Vec2DF{ 500,500 });
	this->GetCamera().Lerp(this->GetPlayer().transform.Position - Vec2DF{ 500,550 },3 * deltaTime);
}

void GameFramework::Draw(PaintInfo info)
{
	info.DrawCollision = isDrawCollision;
	this->GetCamera().BackDraw(info);
	this->container->sandBag->Draw(info);
	this->container->player->Draw(info);
	for (auto& ptr : container->Effects)
	{
		ptr->Draw(info);
	}
	this->GetCamera().Draw(info);
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

void GameFramework::OnEffect(const std::string& tag, const Vec2DF& Position, bool isCopy)
{
	
	for (auto& ptr : container->Effects)
	{
		if (!ptr->GetActiveState())
		{
			static_cast<Effect*>(ptr.get())->EffectOn(tag, Position, isCopy);
			return;
		}
	}
	auto ptr = std::make_unique<Effect>(this, "Effects");
	ptr->EffectOn(tag, Position, isCopy);
	container->Effects.emplace_back(std::move(ptr));
}

Vec2DF GameFramework::GetDisplaySize() const
{
	return Vec2DF();
}

Vec2DF GameFramework::GetMargin() const
{
	return Vec2DF();
}
Camera& GameFramework::GetCamera() const 
{
	return *container->camera; 
}

Vec2DF GameFramework::GetCameraTransform(const Vec2DF& transform) const
{
	return container->camera->CameraTransform(transform);
}


void GameFramework::MouseInput(Vec2DU MousePos, UINT iMessage)
{
}

Player& GameFramework::GetPlayer() const
{
	return (Player&)(*this->container->player.get());
}
