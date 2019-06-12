#pragma once
#include "GameObject.h"
#include "Animation.h"
#include "State.h"
#include <atlimage.h>


class Player : public GameStateObject
{
public:
	Player(GameFramework* framework, const std::string& tag);
	float delayCounter = 0.0f;
	int Costume = 0;
	float ground = 600;
	float maxHP = 100;
	float skillCool = 30.0f;
	float curskillCool = 0.0f;
	bool isPerfect = false;
	virtual void Update(float deltaTime) override;
	virtual void Draw(PaintInfo info) override;
	virtual void Reset() {};
	virtual void Damaged(int hp, bool off = false) override;
};