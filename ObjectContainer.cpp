#include "pch.h"
#include "ObjectContainer.h"
#include "Player.h"
#include "SandBag.h"

ObjectContainer::ObjectContainer(GameFramework* framework)
{
	this->player = new Player(framework, "Player");
	this->sandBag = new SandBag(framework, "SandBag");
}

ObjectContainer::~ObjectContainer()
{
	delete this->player;
}