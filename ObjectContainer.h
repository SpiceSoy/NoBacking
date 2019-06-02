#pragma once
class GameStateObject;
class GameFramework;
struct ObjectContainer
{
	ObjectContainer(GameFramework* framework);
	~ObjectContainer();
	GameStateObject* player;
	GameStateObject* sandBag;
};