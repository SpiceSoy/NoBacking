#pragma once
#include "GameObject.h"
#include "Animation.h"
#include <atlimage.h>


class Player : public GameObject
{
public:
	Player(GameFramework* framework, const std::string& tag);
	Animation playerAnime;
	virtual void Update(float deltaTime) override;
	virtual void Draw(PaintInfo info) override;
	virtual void Reset() {};
};