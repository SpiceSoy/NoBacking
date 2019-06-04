#include "pch.h"
#include "SandBag.h"
#include "Collision.h"
#include "GameFramework.h"
#include "Player.h"
#include <atlimage.h>

SandBag::SandBag(GameFramework* framework, const std::string& tag)
	:GameStateObject(framework, tag)
{
	this->playerAnime.Set("sandbag");
	ImageMargin = Vec2DF{ 200,235 };

#pragma region StateDef
	{
		this->playerState.SetStateFunctionSet
		(
			CharacterNormalState::IDLE,
			[](GameStateObject & object) -> void
			{
				object.playerAnime.ChangeState(CharacterNormalState::IDLE);
			},
			[framework](GameStateObject& object, float deltaTime) -> void
			{
				if (abs((framework->GetPlayer().transform.Position - object.transform.Position).x) < 120)
				{
					object.playerState.ChangeState(CharacterNormalState::MOTION2);
				}
				if (GetAsyncKeyState('J') & 0x8000)
				{
					object.playerState.ChangeState(CharacterNormalState::MOTION1);
				}
				else if (GetAsyncKeyState('K') & 0x8000)
				{
					object.playerState.ChangeState(CharacterNormalState::MOTION2);
				}
				else if (GetAsyncKeyState('L') & 0x8000)
				{
					object.playerState.ChangeState(CharacterNormalState::MOTION3);
				}
			},
			[](GameStateObject& object, CharacterNormalState state) -> bool
			{
				return true;
			}, 
			[this, framework](GameStateObject& object, GameStateObject& other, const CollisionResult::ResultVector& result)->bool
			{
				for (auto& res : result)
				{
					if (res.second == "weapon")
					{
						this->hp--;
						framework->OnEffect("effect1", this->transform.Position);
						if (hp == 0)
						{
							object.playerState.ChangeState(CharacterNormalState::MOTION3);
						}
						else 
						{
							object.playerState.ChangeState(CharacterNormalState::MOTION1);
						}
					}
				}
				return false;
			}
		);
		this->playerState.SetStateFunctionSet
		(
			CharacterNormalState::MOTION1,
			[](GameStateObject& object) -> void
			{
				object.playerAnime.ChangeState(CharacterNormalState::MOTION1);
			},
			[](GameStateObject& object, float deltaTime) -> void
			{
				if (object.playerAnime.isEnd())
				{
					object.playerState.ChangeState(CharacterNormalState::IDLE);
				}
			},
				[](GameStateObject& object, CharacterNormalState state) -> bool
			{
				return true;
			}
		);
		this->playerState.SetStateFunctionSet
		(
			CharacterNormalState::MOTION2,
			[](GameStateObject& object) -> void
			{
				object.playerAnime.ChangeState(CharacterNormalState::MOTION2);
			},
			[framework](GameStateObject& object, float deltaTime) -> void
			{
				if (object.playerAnime.isEnd())
				{
					object.playerState.ChangeState(CharacterNormalState::IDLE);
				}
				framework->CheckCollision(object);
			},
				[framework](GameStateObject& object, CharacterNormalState state) -> bool
			{
				framework->GetPlayer().ResetDamageCounter();
				return true;
			},
				[this, framework](GameStateObject & object, GameStateObject & other, const CollisionResult::ResultVector & result)->bool
			{
				for (auto& res : result)
				{
					if (res.second == "weapon")
					{
						this->hp--;
						framework->OnEffect("effect1", this->transform.Position);
						if (hp == 0)
						{
							object.playerState.ChangeState(CharacterNormalState::MOTION3);
						}
						else
						{
							object.playerState.ChangeState(CharacterNormalState::MOTION1);
						}
					}
					if (res.first == "attack1" && res.second == "body")
					{
						other.Damaged(0);
					}
				}
				return false;
			}
		);
		this->playerState.SetStateFunctionSet
		(
			CharacterNormalState::MOTION3,
			[](GameStateObject& object) -> void
			{
				object.playerAnime.ChangeState(CharacterNormalState::MOTION3);
			},
			[this](GameStateObject& object, float deltaTime) -> void
			{
				if (object.playerAnime.isEnd())
				{
					this->Deactive();
					//object.playerState.ChangeState(CharacterNormalState::IDLE);
				}
			},
				[](GameStateObject& object, CharacterNormalState state) -> bool
			{
				return true;
			}
		);
	}
#pragma endregion

	this->playerState.ChangeState(CharacterNormalState::IDLE);
	this->transform.Translate(Vec2DF::Down() * 500,false, 1);
	this->transform.Translate(Vec2DF::Right() * 400,false, 1);
}

void SandBag::Update(float deltaTime)
{
	if (isActive)
	{
		this->playerAnime.Update(deltaTime);
		this->playerState.Update(deltaTime);
		this->transform.Update(deltaTime);
	}
}

void SandBag::Draw(PaintInfo info)
{
	if (isActive)
	{
		this->playerAnime.GetCurrentImage().img->Draw(info.hdc, this->transform.Position.x, this->transform.Position.y);
		this->playerAnime.GetCurrentCollisionData().Draw(info, this->transform.Position + ImageMargin);
	}
}
