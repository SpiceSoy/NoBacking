#include "pch.h"
#include "Effect.h"

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
		POINT pt = this->transform.Position;
		RECT rt = RectF(this->transform.Position, this->playerAnime.GetCurrentImage().img->GetWidth(), this->playerAnime.GetCurrentImage().img->GetHeight());
		this->playerAnime.GetCurrentImage().img->BitBlt(info.hdc, pt, SRCPAINT);
		this->playerAnime.GetCurrentCollisionData().Draw(info, this->transform.Position + ImageMargin);
	}
}

void Effect::EffectOn(const std::string& tag, const Vec2DF& Position, bool isXor)
{
	if (!isActive)
	{
		this->isXor = isXor;
		this->transform.Position = Position;
		this->playerAnime.Set(EffectSet[tag].ImageTag, EffectSet[tag].MotionTag, EffectSet[tag].CollisionTag);
		this->playerState.SetStateFunction(CharacterNormalState::IDLE, EffectSet[tag].func);
		this->playerState.ChangeState(CharacterNormalState::IDLE);
		this->Active();
	}
}
