#pragma once
#include "GameObject.h"
#include "Animation.h"
#include "State.h"
#include <map>
#include <atlimage.h>



class subEffect
{
	std::string ImageTag;
	//모션벡터

};

class Effect : public GameStateObject
{
	using EffectTag = std::string;
	static std::map<std::string,subEffect>
public:
	SandBag(GameFramework* framework, const std::string& tag);
	float delayCounter = 0.0f;
	std::string CurrentEffect;
	virtual void Update(float deltaTime) override;
	virtual void Draw(PaintInfo info) override;
	virtual void Reset() {};
	virtual void EffectOn()
};