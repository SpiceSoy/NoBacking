#pragma once
#include "State.h"
namespace CommonEffectFunctionSet
{
	StateFunction GetOnceAnimeSet();
	StateFunction GetMoveingEffectSet(const Vec2DF& moveVector, StateFunction::CollisionFuncType colFunc = nullptr);

};