#include "pch.h"
#include "ObjectContainer.h"
#include "Player.h"
#include "SandBag.h"
#include "Effect.h"
#include "Camera.h"
#include "Guarder.h"
#include "Archer.h"
#include "Giant.h"
#include "Lancer.h"
#include "PlayerHPBar.h"
#include "UIObject.h"
#include "UITItle.h"

ObjectContainer::ObjectContainer(GameFramework* framework)
{
	this->camera = std::make_unique<Camera>();
	this->player = std::make_unique<Player>(framework, "Player");
	{
		//몬스터 추가
		this->Monsters.emplace_back(std::make_unique<SandBag>(framework, "SandBag"));
		this->Monsters.emplace_back(std::make_unique<Guarder>(framework, "Guarder"));
		this->Monsters.emplace_back(std::make_unique<Archer>(framework, "Archer"));
		this->Monsters.emplace_back(std::make_unique<Lancer>(framework, "Lancer"));
		this->Monsters.emplace_back(std::make_unique<Giant>(framework, "Giant"));
	}
	for (size_t i = 0; i < 20; i++)
	{
		this->Effects.emplace_back(std::make_unique<Effect>(framework, "Effects"));
	}
	this->playerHpBar = std::make_unique<PlayerHPBar>();
	this->enemyHpBar = std::make_unique<EnemyHPBar>();

}

ObjectContainer::~ObjectContainer()
{
}