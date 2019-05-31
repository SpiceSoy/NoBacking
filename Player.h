#pragma once
#include "GameObject.h"
#include "Animation.h"
#include "State.h"
#include <atlimage.h>


class Player : public GameObject
{
public:
	Player(GameFramework* framework, const std::string& tag);
	Animation playerAnime;
	State playerState;
	Vec2DF ImageMargin = Vec2DF{ 128,184 };
	float delayCounter = 0.0f;
	virtual void Update(float deltaTime) override;
	virtual void Draw(PaintInfo info) override;
	virtual void Reset() {};
};