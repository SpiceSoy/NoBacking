#include "pch.h"
#include "GameFramework.h"
#include "ObjectContainer.h"
#include "GameObject.h"
#include "UIObject.h"
#include "Collision.h"
#include "Effect.h"
#include "Player.h"
#include "Camera.h"
#include "SoundSystem.h"
#include "PlayerHPBar.h"
#include "UITItle.h"
#include "UIDie.h"

GameFramework::GameFramework()
{
}

GameFramework::~GameFramework()
{
	Destory();
}

void GameFramework::Start()
{
	this->GameStart = true;
	if (this->container != nullptr)
	{
		delete this->container;
	}
	this->container = new ObjectContainer(this);
	this->GetCamera().Teleport(this->GetPlayer().transform.Position - Vec2DF{ 500,550 });
}

void GameFramework::End()
{
	this->GameStart = false;
	//delete this->container;
}

void GameFramework::Create()
{
	SoundSystem::OnInitalize();
	CollisionResult::reserve(50);
	this->Load();
	//this->container = new ObjectContainer(this);
	this->uiObjects.emplace_back(std::make_unique<UIDied>(this));
	this->uiObjects.emplace_back(std::make_unique<UITitle>(this));
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
	for (auto& ui : this->uiObjects)
	{
		ui->Update(deltaTime);
	}
	if (GameStart)
	{
		this->container->player->Update(deltaTime);
		/*for (auto& ptr : container->Monsters)
		{
			ptr->Update(deltaTime);
		}*/
		this->container->Monsters[2]->Update(deltaTime);
		for (size_t i = 0; i < container->Effects.size(); i++)
		{
			container->Effects[i]->Update(deltaTime);
		}
		//UI
		this->container->playerHpBar->Update(deltaTime);
		this->container->enemyHpBar->Update(deltaTime);

		//this->GetCamera().Teleport(this->GetPlayer().transform.Position - Vec2DF{ 500,500 });
		this->GetCamera().Lerp(this->GetPlayer().transform.Position - Vec2DF{ 500,550 },3 * deltaTime);
	}
}

void GameFramework::Draw(PaintInfo info)
{
	if (this->container != nullptr)
	{
		info.DrawCollision = isDrawCollision;
		this->GetCamera().BackDraw(info);
		this->container->player->Draw(info);
		for (auto& ptr : container->Monsters)
		{
			ptr->Draw(info);
		}
		for (auto& ptr : container->Effects)
		{
			ptr->Draw(info);
		}
		//UI
		this->GetCamera().Draw(info);
		this->container->playerHpBar->Draw(info);
		this->container->enemyHpBar->Draw(info);
	}
	for (auto& ui : this->uiObjects)
	{
		ui->Draw(info);
	}
}

bool GameFramework::CheckCollision(GameStateObject& obj)
{
	if (this->container != nullptr)
	{
		//return this->container->player->CheckCollision(*this->container->sandBag);
		return this->container->player->CheckCollision(obj);
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

void GameFramework::PlayerHPBar(float destPercent)
{
	this->container->playerHpBar->ChangeDest(destPercent);
}

void GameFramework::EnemyHPBar(float destPercent, void* enemyPtr, const std::string& markTag)
{
	this->container->enemyHpBar->ChangeDest(destPercent, enemyPtr, markTag);
}

void GameFramework::OnGameover()
{
	static_cast<UIDied*>(this->uiObjects[0].get())->OnDied();
}


void GameFramework::MouseInput(Vec2DU MousePos, UINT iMessage)
{
}

Player& GameFramework::GetPlayer() const
{
	return (Player&)(*this->container->player.get());
}
