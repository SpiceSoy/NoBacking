#include "pch.h"
#include "SandBag.h"
#include "Collision.h"
#include <atlimage.h>

SandBag::SandBag(GameFramework* framework, const std::string& tag)
	:GameStateObject(framework, tag)
{
	this->playerAnime.Set("sandbag");
	ImageMargin = Vec2DF{ 200,235 };
#pragma region AnimeDef
	//일반 모션
	subAnimation subAnim;
	subAnim.next = CharacterNormalState::LOOP;
	subAnim.scale = 0.85;
	subAnim.subImageStartIndex = 0;
	subAnim.subImageSize = 18;
	this->playerAnime.AddMotion(CharacterNormalState::IDLE, subAnim);
	//피격 1
	subAnim.next = CharacterNormalState::None;
	subAnim.scale = 0.85;
	subAnim.subImageStartIndex = 18;
	subAnim.subImageSize = 14;
	this->playerAnime.AddMotion(CharacterNormalState::MOTION1, subAnim);
	//피격 2
	subAnim.next = CharacterNormalState::None;
	subAnim.scale = 0.85;
	subAnim.subImageStartIndex = 32;
	subAnim.subImageSize = 14;
	this->playerAnime.AddMotion(CharacterNormalState::MOTION2, subAnim);
	//사망
	subAnim.next = CharacterNormalState::None;
	subAnim.scale = 0.85;
	subAnim.subImageStartIndex = 46;
	subAnim.subImageSize = 11;
	this->playerAnime.AddMotion(CharacterNormalState::MOTION3, subAnim);

#pragma endregion

#pragma region StateDef
	{
		this->playerState.SetStateFunctionSet
		(
			CharacterNormalState::IDLE,
			[](GameStateObject & object) -> void
			{
				object.playerAnime.ChangeState(CharacterNormalState::IDLE);
			},
			[](GameStateObject& object, float deltaTime) -> void
			{
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
			[this](GameStateObject& object, GameStateObject& other, const CollisionResult::ResultVector& result)->bool
			{
				for (auto& res : result)
				{
					if (res.second == "weapon")
					{
						this->hp--;
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
			CharacterNormalState::MOTION3,
			[](GameStateObject& object) -> void
			{
				object.playerAnime.ChangeState(CharacterNormalState::MOTION3);
			},
			[](GameStateObject& object, float deltaTime) -> void
			{
				if (object.playerAnime.isEnd())
				{
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
	this->transform.Translate(Vec2DF::Down() * 450,false, 1);
	this->transform.Translate(Vec2DF::Right() * 500,false, 1);
}

void SandBag::Update(float deltaTime)
{
	this->transform.Update(deltaTime);
	this->playerAnime.Update(deltaTime);
	this->playerState.Update(deltaTime);
}

void SandBag::Draw(PaintInfo info)
{
	this->playerAnime.GetCurrentImage().img->Draw(info.hdc, this->transform.Position.x, this->transform.Position.y);
	this->playerAnime.GetCurrentCollisionData().Draw(info, this->transform.Position + ImageMargin);
}
