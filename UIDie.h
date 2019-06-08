#pragma once
#include "UIObject.h"
class UIDied : public UIObject
{
	float alpha = 1.0f;
	bool On = false;
	bool isOffed = false;
	float delayCounter = 0.0f;
public:
	UIDied(GameFramework* framework) :UIObject(framework) {};
	virtual void Update(float deltaTime) override;
	virtual void Draw(PaintInfo info) override;
	void OnDied() { On = true; alpha = 0.0f;  delayCounter = 0.0f; }
};