#include "pch.h"
#include "GameFramework.h"
#include "ObjectContainer.h"
#include "GameObject.h"
#include "Collision.h"
#include "Effect.h"
#include "Player.h"
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
	this->container->player->Update(deltaTime);
	this->container->sandBag->Update(deltaTime);
	for (auto& ptr : container->Effects)
	{
		ptr->Update(deltaTime);
	}
}

void GameFramework::Draw(PaintInfo info)
{
	info.DrawCollision = isDrawCollision;
	this->container->sandBag->Draw(info);
	this->container->player->Draw(info);
	for (auto& ptr : container->Effects)
	{
		ptr->Draw(info);
	}
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

void GameFramework::OnEffect(const std::string& tag, const Vec2DF& Position, bool isXor)
{
	
	for (auto& ptr : container->Effects)
	{
		if (!ptr->GetActiveState())
		{
			static_cast<Effect*>(ptr.get())->EffectOn(tag, Position,isXor);
			return;
		}
	}
	auto ptr = std::make_unique<Effect>(this, "Effects");
	ptr->EffectOn(tag, Position, isXor);
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

void GameFramework::MouseInput(Vec2DU MousePos, UINT iMessage)
{
}

Player& GameFramework::GetPlayer() const
{
	return (Player&)(*this->container->player.get());
}
