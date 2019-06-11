#pragma once
#include "Vec2D.h"
#include "IFrameworkObject.h"
#include "Transform.h"
#include "PaintInfo.h"
class UIObject : public IFrameworkObject
{
public:
	bool isActive = true;
	UITransform transform;
	Vec2DF ImageMargin;
	UIObject(GameFramework* framework) : IFrameworkObject(framework), transform(*this, framework) {};
	UIObject(const UIObject& other) = delete;
	virtual ~UIObject() = default;
	virtual void Update(float deltaTime) = 0;
	virtual void Draw(PaintInfo info) = 0;
	virtual void Active() { this->isActive = true; };
	virtual void Deactive() { this->isActive = false; };
	virtual bool GetActiveState() const { return this->isActive; }
	virtual void Reset() {};
	virtual void GetMouseInput(Vec2DU MousePos, UINT iMessage) {};
	bool GetisActive() const { return isActive; }
};