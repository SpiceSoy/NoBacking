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

class EnemyHPBar
{
	void* enemyPtr = nullptr;
	float currnetPercent = 1.0;
	float destPercent = 1.0;
	bool reset = true;
	bool On = false;
	std::string markTag = "";
public:
	void ChangeDest(float destPercent,void* enemyPtr, const std::string& markTag) 
	{
		this->destPercent = destPercent; 
		if (this->enemyPtr != enemyPtr)
		{
			this->enemyPtr = enemyPtr;
			this->On = true;
			this->currnetPercent = 1.0f;
			this->reset = true;
			this->markTag = markTag;
		}
	}
	void Update(float deltaTime);
	void Draw(PaintInfo info);
};