#pragma once
#include <vector>
#include <memory>
class Camera;
class PlayerHPBar;
class GameStateObject;
class GameFramework;
struct ObjectContainer
{
	ObjectContainer(GameFramework* framework);
	~ObjectContainer();
	std::unique_ptr<GameStateObject> player;
	std::unique_ptr<GameStateObject> sandBag;
	std::vector<std::unique_ptr<GameStateObject>> Monsters;
	std::vector<std::unique_ptr<GameStateObject>> Effects;
	//UI
	std::unique_ptr<Camera> camera;
	std::unique_ptr<PlayerHPBar> playerHpBar;

};