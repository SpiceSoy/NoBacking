#include "pch.h"
#include "ObjectContainer.h"
#include "Player.h"
#include "SandBag.h"
#include "Effect.h"
#include "Camera.h"

ObjectContainer::ObjectContainer(GameFramework* framework)
{
	this->camera = std::make_unique<Camera>();
	this->player = std::make_unique<Player>(framework, "Player");
	this->sandBag = std::make_unique<SandBag>(framework, "SandBag");
	for (size_t i = 0; i < 20; i++)
	{
		this->Effects.emplace_back(std::make_unique<Effect>(framework, "Effects"));
	}
}

ObjectContainer::~ObjectContainer()
{
}