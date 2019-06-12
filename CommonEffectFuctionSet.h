#pragma once
#include "State.h"
namespace CommonEffectFunctionSet
{
	StateFunction GetOnceAnimeSet();
	StateFunction GetSkillSet(GameFramework* framework);
	StateFunction GetMoveingEffectSet(const Vec2DF& moveVector, StateFunction::CollisionFuncType colFunc = nullptr, GameFramework * framework = nullptr);

};