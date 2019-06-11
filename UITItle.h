#pragma once
#include "UIObject.h"

class UITitle : public UIObject
{
	float alpha = 1.0f;
	int curSelect = 1;
	bool HelpOn = false;
public:
	UITitle(GameFramework* framework) :UIObject(framework) {};
	virtual void Update(float deltaTime) override;
	virtual void Draw(PaintInfo info) override;
	virtual void GetMouseInput(Vec2DU MousePos, UINT iMessage);
};