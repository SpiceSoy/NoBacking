#pragma once
#include <string>
#include "IFrameworkObject.h"
#include "PaintInfo.h"
#include "Transform.h"
#include "Animation.h"
#include "State.h"

using Tag = std::string;


class GameFramework;

class GameStateObject : public IFrameworkObject
{
private:
protected:
	bool isDestroy = false;
	bool isActive = true;
	int hp = 5;
	bool isCanDamaged = true;
public:
	const Tag tag;
	Transform transform;
	Vec2DF ImageMargin;
	Animation playerAnime;
	State playerState;
	GameStateObject(GameFramework* framework, const std::string& tag) : IFrameworkObject(framework), tag(tag), transform(*this, framework), playerState(this) {};
	GameStateObject(const GameStateObject& other) = delete;
	virtual ~GameStateObject() = default;
	virtual void Update(float deltaTime) = 0;
	virtual void Draw(PaintInfo info) = 0;
	virtual void Destory() { this->isDestroy = true; };
	virtual void Active() { this->isActive = true; };
	virtual void Deactive() { this->isActive = false; };
	virtual bool GetActiveState() const { return this->isActive; }
	virtual void Reset() {};
	//true == StopMove, false == Moving
	virtual bool isCollision(GameStateObject& other);
	virtual bool CheckCollision(GameStateObject& other);
	virtual void Damaged(int hp, bool off = false);
	virtual void ResetDamageCounter();
	bool GetisActive() const { return isActive; }
	bool GetisDestory() const { return isDestroy; }
};