#include "pch.h"
#include "Effect.h"
#include "GameFramework.h"

std::map<std::string, subEffect> Effect::EffectSet = std::map<std::string, subEffect>();

void Effect::AddEffect(const std::string& tag, subEffect&& sub)
{
	Effect::EffectSet[tag] = std::move(sub);
}

Effect::Effect(GameFramework* framework, const std::string& tag)
	:GameStateObject(framework,tag)
{
	this->isActive = false;
}

void Effect::Update(float deltaTime)
{
	if (isActive)
	{
		this->transform.Update(deltaTime);
		this->playerAnime.Update(deltaTime);
		this->playerState.Update(deltaTime);
	}
}

void Effect::Draw(PaintInfo info)
{
	if (isActive)
	{
		if (isCopy) 
		{
			this->playerAnime.GetCurrentImage().img->Draw(info.hdc, framework->GetCameraTransform(this->transform.Position - this->ImageMargin));
		}
		else 
		{
			this->playerAnime.GetCurrentImage().img->BitBlt(info.hdc, framework->GetCameraTransform(this->transform.Position - this->ImageMargin), SRCPAINT);
		}
		this->playerAnime.GetCurrentCollisionData().Draw(info, framework->GetCameraTransform(this->transform.Position));
	}
}

void Effect::EffectOn(const std::string& tag, const Vec2DF& Position, bool isCopy)
{
	if (!isActive)
	{
		this->isCopy = isCopy;
		this->transform.Position = Position;
		this->ImageMargin = EffectSet[tag].ImageMargin;
		this->playerAnime.Set(EffectSet[tag].ImageTag, EffectSet[tag].MotionTag, EffectSet[tag].CollisionTag);
		this->playerState.SetStateFunction(CharacterNormalState::IDLE, EffectSet[tag].func);
		this->playerState.ChangeState(CharacterNormalState::IDLE);
		this->Active();
	}
}
