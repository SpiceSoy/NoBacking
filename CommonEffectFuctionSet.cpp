#include "pch.h"
#include "CommonEffectFuctionSet.h"
#include "GameFramework.h"
#include "GameObject.h"

StateFunction CommonEffectFunctionSet::GetOnceAnimeSet()
{
	return std::move(StateFunction(
		[](GameStateObject & object) -> void
		{
			object.playerAnime.ChangeState(CharacterNormalState::IDLE,true);
		},
		[](GameStateObject & object, float deltaTime) -> void
		{
			if (object.playerAnime.isEnd())
			{
				object.Deactive();
			}
		},
			[](GameStateObject & object, CharacterNormalState state) -> bool
		{
			return true;
		},
		[](GameStateObject & object, GameStateObject & other, const CollisionResult::ResultVector & result)->bool
		{
			return false;
		}
	));
}

StateFunction CommonEffectFunctionSet::GetMoveingEffectSet(const Vec2DF& moveVector , StateFunction::CollisionFuncType colFunc)
{
	return std::move(StateFunction(
		[](GameStateObject & object) -> void
		{
			object.playerAnime.ChangeState(CharacterNormalState::IDLE);
		},
		[moveVector](GameStateObject & object, float deltaTime) -> void
		{
			object.transform.Translate(moveVector * deltaTime);
		},
			[](GameStateObject & object, CharacterNormalState state) -> bool
		{
			return true;
		},
			[colFunc](GameStateObject & object, GameStateObject & other, const CollisionResult::ResultVector & result)->bool
		{
			return colFunc(object,other, result);
		}
		));
}
