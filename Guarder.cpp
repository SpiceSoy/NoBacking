#include "pch.h"
#include "Guarder.h"
#include "Collision.h"
#include "GameFramework.h"
#include "Player.h"
#include <atlimage.h>

Guarder::Guarder(GameFramework* framework, const std::string& tag)
	:GameStateObject(framework, tag)
{
	this->playerAnime.Set("guarder");
	ImageMargin = Vec2DF{ 158,147 };

#pragma region StateDef
	{
		this->playerState.SetStateFunctionSet
		(
			CharacterNormalState::IDLE,
			[](GameStateObject & object) -> void
			{
				object.playerAnime.ChangeState(CharacterNormalState::IDLE);
			},
			[framework](GameStateObject & object, float deltaTime) -> void
			{
				if (abs((framework->GetPlayer().transform.Position - object.transform.Position).x) < 120)
				{
					object.playerState.ChangeState(CharacterNormalState::MOTION2);
				}
				else if (abs((framework->GetPlayer().transform.Position - object.transform.Position).x) < 700)
				{
					object.playerAnime.ChangeState(CharacterNormalState::MOTION1);
					auto moveVec = ((framework->GetPlayer().transform.Position - object.transform.Position).x < 0) ? (Vec2DF::Left()) : (Vec2DF::Right());
					object.transform.Translate(moveVec * 100.0f * deltaTime);
					//object.playerState.ChangeState(CharacterNormalState::MOTION2);
				}
			},
				[](GameStateObject & object, CharacterNormalState state) -> bool
			{
				return true;
			},
				[this, framework](GameStateObject & object, GameStateObject & other, const CollisionResult::ResultVector & result)->bool
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
							object.playerState.ChangeState(CharacterNormalState::MOTION4);
						}
					}
				}
				return false;
			}
			);
		this->playerState.SetStateFunctionSet
		(
			CharacterNormalState::MOTION4,
			[](GameStateObject & object) -> void
			{
				object.playerAnime.ChangeState(CharacterNormalState::MOTION4);
				object.ResetDamageCounter();
			},
			[](GameStateObject & object, float deltaTime) -> void
			{
				if (object.playerAnime.isEnd())
				{
					object.playerState.ChangeState(CharacterNormalState::IDLE);
				}
			},
				[](GameStateObject & object, CharacterNormalState state) -> bool
			{
				return true;
			}
			);
		this->playerState.SetStateFunctionSet
		(
			CharacterNormalState::MOTION2,
			[](GameStateObject & object) -> void
			{
				object.playerAnime.ChangeState(CharacterNormalState::MOTION2);
			},
			[framework](GameStateObject & object, float deltaTime) -> void
			{
				if (!(object.playerAnime.GetCurrentFrame() >= 1 && object.playerAnime.GetCurrentFrame() <= 3))
				{
					framework->GetPlayer().ResetDamageCounter();
				}
				if (object.playerAnime.isEnd())
				{
					object.playerState.ChangeState(CharacterNormalState::IDLE);
				}
				framework->CheckCollision(object);
			},
				[framework](GameStateObject & object, CharacterNormalState state) -> bool
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
							object.playerState.ChangeState(CharacterNormalState::MOTION4);
						}
					}
					if (res.first == "weapon" && res.second == "body")
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
			[](GameStateObject & object) -> void
			{
				object.playerAnime.ChangeState(CharacterNormalState::MOTION3);
			},
			[this](GameStateObject & object, float deltaTime) -> void
			{
				if (object.playerAnime.isEnd())
				{
					this->Deactive();
					//object.playerState.ChangeState(CharacterNormalState::IDLE);
				}
			},
				[](GameStateObject & object, CharacterNormalState state) -> bool
			{
				return true;
			}
			);
	}
#pragma endregion

	this->playerState.ChangeState(CharacterNormalState::IDLE);
	this->hp = 100;
	this->transform.Translate(Vec2DF::Down() * 600, false, 1);
	this->transform.Translate(Vec2DF::Right() * 1200, false, 1);
}

void Guarder::Update(float deltaTime)
{
	if (isActive)
	{
		this->playerAnime.Update(deltaTime);
		this->playerState.Update(deltaTime);
		this->transform.Update(deltaTime);
	}
}

void Guarder::Draw(PaintInfo info)
{
	if (isActive)
	{
		this->playerAnime.GetCurrentImage().img->Draw(info.hdc, framework->GetCameraTransform(this->transform.Position - this->ImageMargin));
		this->playerAnime.GetCurrentCollisionData().Draw(info, framework->GetCameraTransform(this->transform.Position));
	}
}