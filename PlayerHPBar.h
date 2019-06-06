#pragma once
#include <atlimage.h>
#include "PaintInfo.h"
class PlayerHPBar
{
	float currnetPercent = 1.0;
	float destPercent = 1.0;
public:
	void ChangeDest(float destPercent) { this->destPercent = destPercent; }
	void Update(float deltaTime);
	void Draw(PaintInfo info);
};