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
				if (abs((framework->GetPlayer().transform.Position - object.transform.Position).x) < 220)
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
						this->Damaged(5);
						framework->OnEffect("effect1", this->transform.Position + Vec2DF::Up() * 50);
						SoundSystem::PlaySound("hit-cut");
						if (hp == 0)
						{
							object.playerState.ChangeState(CharacterNormalState::MOTION3);
						}
						else 
						{
							object.playerState.ChangeState(CharacterNormalState::MOTION1);
						}
					}
					if ( res.second == "skill0")
					{
						framework->OnEffect("flashslash2", this->transform.Position + Vec2DF::Up() * 50);
					}
					if (res.second == "skill1")
					{
						SoundSystem::PlaySound("hit-cut");
						object.Damaged(1,true);
						object.ResetDamageCounter();
						if (hp == 0)
						{
							object.playerState.ChangeState(CharacterNormalState::MOTION3);
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
				object.ResetDamageCounter();
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
				//if (!(object.playerAnime.GetCurrentFrame() >= 1 && object.playerAnime.GetCurrentFrame() <= 3))
				//{
				//	framework->GetPlayer().ResetDamageCounter();
				//}
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
					if (res.second == "weapon" && this->isCanDamaged)
					{
						this->Damaged(5);
						framework->OnEffect("effect1", this->transform.Position + Vec2DF::Up() * 50);
						SoundSystem::PlaySound("hit-cut");
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
						other.Damaged(3);
					}
					if ( res.second == "skill0")
					{
						framework->OnEffect("flashslash2", this->transform.Position + Vec2DF::Up() * 50);
					}
					if ( res.second == "skill1")
					{
						SoundSystem::PlaySound("hit-cut");
						object.Damaged(1, true);
						object.ResetDamageCounter();
						if (hp == 0)
						{
							object.playerState.ChangeState(CharacterNormalState::MOTION3);
						}
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
	this->hp = 100;
	this->transform.Translate(Vec2DF::Down() * 600,false, 1);
	this->transform.Translate(Vec2DF::Right() * 900,false, 1);
}

void SandBag::Update(float deltaTime)
{
	if (isActive && (this->transform.Position - this->framework->GetPlayer().transform.Position).GetScaleSq() < (1380 * 1380))
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
		this->playerAnime.GetCurrentImage().img->Draw(info.hdc, framework->GetCameraTransform(this->transform.Position - this->ImageMargin));
		this->playerAnime.GetCurrentCollisionData().Draw(info, framework->GetCameraTransform(this->transform.Position));
	}
}

void SandBag::Damaged(int hp, bool off)
{
	GameStateObject::Damaged(hp, off);
	this->framework->EnemyHPBar(this->hp / this->maxHP, this, "mark-pist");
}

