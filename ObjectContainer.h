#pragma once
#include <vector>
#include <memory>
class GameStateObject;
class GameFramework;
struct ObjectContainer
{
	ObjectContainer(GameFramework* framework);
	~ObjectContainer();
	std::unique_ptr<GameStateObject> player;
	std::unique_ptr<GameStateObject> sandBag;
	std::vector<std::unique_ptr<GameStateObject>> Effects;
};