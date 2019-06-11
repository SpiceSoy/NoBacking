#include "pch.h"
#include "Archer.h"
#include "Collision.h"
#include "GameFramework.h"
#include "Player.h"
#include <atlimage.h>

Archer::Archer(GameFramework* framework, const std::string& tag)
	:GameStateObject(framework, tag)
{
	this->playerAnime.Set("archer");
	ImageMargin = Vec2DF{ 65,105 };

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
			if (abs((framework->GetPlayer().transform.Position - object.transform.Position).x) < 100)
			{
				int r = rand() % 50;
				if (r == 0) {
					object.playerState.ChangeState(CharacterNormalState::MOTION5);
				}
				else {
					object.playerAnime.ChangeState(CharacterNormalState::MOTION1);
					auto moveVec = ((framework->GetPlayer().transform.Position - object.transform.Position).x < 0) ? (Vec2DF::Left()) : (Vec2DF::Right());
					object.transform.Translate(moveVec * -330.0f * deltaTime);
				}
			}
			else if (abs((framework->GetPlayer().transform.Position - object.transform.Position).x) < 300)
			{
				object.playerAnime.ChangeState(CharacterNormalState::MOTION1);
				auto moveVec = ((framework->GetPlayer().transform.Position - object.transform.Position).x < 0) ? (Vec2DF::Left()) : (Vec2DF::Right());
				object.transform.Translate(moveVec * -200.0f * deltaTime);
			}
			else if (abs((framework->GetPlayer().transform.Position - object.transform.Position).x) > 300 && abs((framework->GetPlayer().transform.Position - object.transform.Position).x) < 700) {
				object.playerState.ChangeState(CharacterNormalState::MOTION4);
			}
			else {
				object.playerAnime.ChangeState(CharacterNormalState::IDLE);
			}
			framework->CheckCollision(object);
		},
			[](GameStateObject & object, CharacterNormalState state) -> bool
		{
			return true;
		},
			[this, framework](GameStateObject & object, GameStateObject & other, const CollisionResult::ResultVector & result)->bool
		{
			for (auto& res : result)
			{
				if (res.second == "weapon" && res.first != "bound")
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
						object.playerState.ChangeState(CharacterNormalState::MOTION2);
					}
				}
			}
			return false;
		}
		);
		this->playerState.SetStateFunctionSet
		(
			CharacterNormalState::MOTION2, // 피격
			[](GameStateObject & object) -> void
		{
			object.playerAnime.ChangeState(CharacterNormalState::MOTION2);
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
			CharacterNormalState::MOTION3, // 다운
			[](GameStateObject & object) -> void
		{
			object.playerAnime.ChangeState(CharacterNormalState::MOTION3);
		},
			[this](GameStateObject & object, float deltaTime) -> void
		{
			if (object.playerAnime.isEnd())
			{
				this->Deactive();
			}
		},
			[](GameStateObject & object, CharacterNormalState state) -> bool
		{
			return true;
		}
		);
		this->playerState.SetStateFunctionSet
		(
			CharacterNormalState::MOTION4, // 원거리공격
			[](GameStateObject & object) -> void
		{
			object.playerAnime.ChangeState(CharacterNormalState::MOTION4);
		},
			[framework](GameStateObject & object, float deltaTime) -> void
		{
			static bool cnt = false;
			if (object.playerAnime.GetCurrentFrame() == 8)
			{
				if (!cnt)
				{
					framework->OnEffect("arrow", object.transform.Position + Vec2DF::Up() * 50);
				}
				cnt = true;
			}
			else
			{
				cnt = false;
			}
			if (object.playerAnime.isEnd())
			{
				object.playerState.ChangeState(CharacterNormalState::IDLE);
			}
			framework->CheckCollision(object);
		},
			[framework](GameStateObject & object, CharacterNormalState state) -> bool
		{
			//framework->GetPlayer().ResetDamageCounter();
			return true;
		},
			[this, framework](GameStateObject & object, GameStateObject & other, const CollisionResult::ResultVector & result)->bool
		{
			for (auto& res : result)
			{
				if (res.second == "weapon" && this->isCanDamaged && res.first != "bound")
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
						object.playerState.ChangeState(CharacterNormalState::MOTION2);
					}
				}
				if (res.first == "weapon" && res.second == "body")
				{
					//other.Damaged(0);
				}
			}
			return false;
		}
		);
		this->playerState.SetStateFunctionSet
		(
			CharacterNormalState::MOTION5, // 근거리 공격
			[](GameStateObject & object) -> void
		{
			object.playerAnime.ChangeState(CharacterNormalState::MOTION5);
		},
			[framework](GameStateObject & object, float deltaTime) -> void
		{
			framework->CheckCollision(object);
			if (object.playerAnime.isEnd())
			{
				object.playerState.ChangeState(CharacterNormalState::IDLE);
			}
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
				if (res.second == "weapon" && this->isCanDamaged && res.first != "bound")
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
						object.playerState.ChangeState(CharacterNormalState::MOTION2);
					}
				}
				if (res.first == "weapon" && res.second == "body")
				{
					other.Damaged(15);
				}
			}
			return false;
		}
		);
	}
#pragma endregion

	this->playerState.ChangeState(CharacterNormalState::IDLE);
	this->hp = 100;
	this->transform.Translate(Vec2DF::Down() * 600, false, 1);
	this->transform.Translate(Vec2DF::Right() * (900 + 1380 * 2), false, 1);
}

void Archer::Update(float deltaTime)
{
	if (isActive && (this->transform.Position - this->framework->GetPlayer().transform.Position).GetScaleSq() < (1380 * 1380))
	{
		this->playerAnime.Update(deltaTime);
		this->playerState.Update(deltaTime);
		this->transform.Update(deltaTime);
	}
}

void Archer::Draw(PaintInfo info)
{
	if (isActive)
	{
		this->playerAnime.GetCurrentImage().img->Draw(info.hdc, framework->GetCameraTransform(this->transform.Position - this->ImageMargin));
		this->playerAnime.GetCurrentCollisionData().Draw(info, framework->GetCameraTransform(this->transform.Position));
	}
}

void Archer::Damaged(int hp, bool off)
{
	GameStateObject::Damaged(hp, off);
	this->framework->EnemyHPBar(this->hp / this->maxHP, this, "mark-ach");
}
