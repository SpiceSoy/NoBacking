#pragma once
#include "UIObject.h"

class UITitle : public UIObject
{
	float alpha = 1.0f;
	int curSelect = 1;
public:
	UITitle(GameFramework* framework) :UIObject(framework) {};
	virtual void Update(float deltaTime) override;
	virtual void Draw(PaintInfo info) override;
};