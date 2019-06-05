#pragma once
#include "GameObject.h"
#include "Animation.h"
#include "State.h"
#include <map>
#include <atlimage.h>



struct subEffect
{
	std::string ImageTag;
	std::string MotionTag;
	std::string CollisionTag;
	Vec2DF ImageMargin = Vec2DF{ 0,0 };
	StateFunction func;
};

//단일 스테이트 오브젝트
class Effect : public GameStateObject
{
	using EffectTag = std::string;
	static std::map<std::string, subEffect> EffectSet;
	bool isCopy = false;
	Vec2DF ImageMargin = Vec2DF{0,0};
public:
	static void AddEffect(const std::string& tag, subEffect&& sub);
	Effect(GameFramework* framework, const std::string& tag);
	float delayCounter = 0.0f;
	std::string CurrentEffect;
	virtual void Update(float deltaTime) override;
	virtual void Draw(PaintInfo info) override;
	virtual void Reset() {};
	virtual void EffectOn(const std::string& tag, const Vec2DF& Position, bool isCopy = false);
};