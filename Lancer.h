#pragma once
#include "GameObject.h"
#include "Animation.h"
#include "State.h"
#include <atlimage.h>


class Lancer : public GameStateObject
{
	float maxHP = 100;
public:
	Lancer(GameFramework* framework, const std::string& tag);
	float delayCounter = 0.0f;
	virtual void Update(float deltaTime) override;
	virtual void Draw(PaintInfo info) override;
	virtual void Reset() {};
	virtual void Damaged(int hp, bool off = false) override;
};