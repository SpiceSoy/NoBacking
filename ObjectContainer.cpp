#include "pch.h"
#include "ObjectContainer.h"
#include "Player.h"

ObjectContainer::ObjectContainer(GameFramework* framework)
{
	this->player = new Player(framework,"Player");
}

ObjectContainer::~ObjectContainer()
{
	delete this->player;
}