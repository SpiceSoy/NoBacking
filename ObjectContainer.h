#pragma once
class GameObject;
class GameFramework;
struct ObjectContainer
{
	ObjectContainer(GameFramework* framework);
	~ObjectContainer();
	GameObject* player;
};