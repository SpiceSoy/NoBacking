#pragma once
#include "UIObject.h"
class UIDied : public UIObject
{
	float alpha = 1.0f;
	bool On = false;
	bool isOffed = false;
	bool isClear = false;
	float delayCounter = 0.0f;
public:
	UIDied(GameFramework* framework) :UIObject(framework) {};
	virtual void Update(float deltaTime) override;
	virtual void Draw(PaintInfo info) override;
	void OnDied() { On = true; alpha = 0.0f; isClear = false; delayCounter = 0.0f; }
	void OnClear() { On = true; alpha = 0.0f; isClear = true;  delayCounter = 0.0f; }
};