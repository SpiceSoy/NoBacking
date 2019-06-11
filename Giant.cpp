#include "pch.h"
#include "Giant.h"
#include "Collision.h"
#include "GameFramework.h"
#include "Player.h"
#include <atlimage.h>

Giant::Giant(GameFramework* framework, const std::string& tag)
	:GameStateObject(framework, tag)
{
	this->playerAnime.Set("giant");
	ImageMargin = Vec2DF{ 280,375 };

#pragma region StateDef
	{
		this->playerState.SetStateFunctionSet
		(
			CharacterNormalState::IDLE,
			[](GameStateObject & object) -> void
		{
			object.playerAnime.ChangeState(CharacterNormalState::IDLE);
		},
			[this, framework](GameStateObject & object, float deltaTime) -> void
		{

			framework->CheckCollision(object);
			if (abs((framework->GetPlayer().transform.Position - object.transform.Position).x) < 200) {
				int r = rand() % 70;
				if (this->hit > 3) {
					if (r == 0) {
						this->hit = 0;
						object.playerState.ChangeState(CharacterNormalState::MOTION6);
					}
					else if (r == 1) {
						this->hit = 0;
						object.playerState.ChangeState(CharacterNormalState::MOTION5);
					}
				}
				else {
					if (r == 0) {
						object.playerState.ChangeState(CharacterNormalState::MOTION3); // 공격1
					}
					else if(r == 1){
						object.playerState.ChangeState(CharacterNormalState::MOTION4); //  공격2
					}
				}
			}
			else if (abs((framework->GetPlayer().transform.Position - object.transform.Position).x) < 600 && abs((framework->GetPlayer().transform.Position - object.transform.Position).x) > 200)
			{
				if (this->hit > 3) {
					int r = rand() % 2;
					if (r == 0) {
						this->hit = 0;
						object.playerState.ChangeState(CharacterNormalState::MOTION6);
					}
					else if (r == 1) {
						this->hit = 0;
						object.playerState.ChangeState(CharacterNormalState::MOTION5);
					}
				}
				else {
					object.playerAnime.ChangeState(CharacterNormalState::MOTION1);
					auto moveVec = ((framework->GetPlayer().transform.Position - object.transform.Position).x < 0) ? (Vec2DF::Left()) : (Vec2DF::Right());
					object.transform.Translate(moveVec * 100.0f * deltaTime);
				}
			}
			else {
				object.playerAnime.ChangeState(CharacterNormalState::IDLE);
			}
		},
			[](GameStateObject & object, CharacterNormalState state) -> bool
		{
			object.ResetDamageCounter();
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
						object.playerState.ChangeState(CharacterNormalState::MOTION2); // 다운
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
		},
			[framework](GameStateObject & object, float deltaTime) -> void
		{
			static bool cnt = false;
			if (object.playerAnime.GetCurrentFrame() == 4)
			{
				if (!cnt)
				{
					framework->OnEffect("giant_smash", object.transform.Position + Vec2DF::Up() * 50);
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
			framework->GetPlayer().ResetDamageCounter();
			return true;
		},
			[this, framework](GameStateObject & object, GameStateObject & other, const CollisionResult::ResultVector & result)->bool
		{
			for (auto& res : result)
			{
				if (res.second == "weapon" && this->isCanDamaged)
				{
					this->Damaged(10);
					framework->OnEffect("effect1", this->transform.Position + Vec2DF::Up() * 50);
					SoundSystem::PlaySound("hit-cut");
					if (hp == 0)
					{
						object.playerState.ChangeState(CharacterNormalState::MOTION2);
					}
				}
				if (res.first == "weapon" && res.second == "body")
				{
					other.Damaged(10);
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
			[framework](GameStateObject & object, float deltaTime) -> void
		{
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
						object.playerState.ChangeState(CharacterNormalState::MOTION2);
					}
				}
				if (res.first == "weapon" && res.second == "body")
				{
					other.Damaged(10);
				}
			}
			return false;
		}
		);
		this->playerState.SetStateFunctionSet
		(
			CharacterNormalState::MOTION2,
			[](GameStateObject & object) -> void
		{
			object.playerAnime.ChangeState(CharacterNormalState::MOTION2);
		},
			[this,framework](GameStateObject & object, float deltaTime) -> void
		{
			if (object.playerAnime.isEnd())
			{
				this->Deactive();
				framework->OnGameClear();
			}
		},
			[](GameStateObject & object, CharacterNormalState state) -> bool
		{
			object.ResetDamageCounter();
			return true;
		}
		);
		this->playerState.SetStateFunctionSet
		(
			CharacterNormalState::MOTION5,
			[](GameStateObject & object) -> void
		{
			object.playerAnime.ChangeState(CharacterNormalState::MOTION5);
		},
			[framework](GameStateObject & object, float deltaTime) -> void
		{
			static bool cnt = false;
			if (object.playerAnime.GetCurrentFrame() == 0)
			{
				if (!cnt)
				{
					SoundSystem::PlaySound("atk-charge");
					framework->OnEffect("giant_energy", object.transform.Position + Vec2DF::Up() * 50);
				}
				cnt = true;
			}
			else if (object.playerAnime.GetCurrentFrame() == 4) {
				if (!cnt)
				{
					SoundSystem::PlaySound("atk-boom");
					framework->OnEffect("giant_lava", object.transform.Position + Vec2DF::Up() * 50);
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
						object.playerState.ChangeState(CharacterNormalState::MOTION5);
					}
				}
				if (res.first == "weapon" && res.second == "body")
				{
					other.Damaged(49);
					other.transform.KnockBack(Vec2DF::Left() * 8);
				}
			}
			return false;
		}
		);
		this->playerState.SetStateFunctionSet
		(
			CharacterNormalState::MOTION6,
			[](GameStateObject & object) -> void
		{
			object.playerAnime.ChangeState(CharacterNormalState::MOTION6);
		},
			[framework](GameStateObject & object, float deltaTime) -> void
		{
			static bool cnt = false;
			if (object.playerAnime.GetCurrentFrame() == 0)
			{
				if (!cnt)
				{
					SoundSystem::PlaySound("atk-charge");
					framework->OnEffect("giant_energy", object.transform.Position + Vec2DF::Up() * 50);
				}
				cnt = true;
			}
			else if (object.playerAnime.GetCurrentFrame() == 7) {
				if (!cnt)
				{
					SoundSystem::PlaySound("atk-boom");
					framework->OnEffect("giant_wave", object.transform.Position + Vec2DF::Up() * 50);
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
						object.playerState.ChangeState(CharacterNormalState::MOTION5);
					}
				}
				if (res.first == "weapon" && res.second == "body")
				{
					other.Damaged(49);
					other.transform.KnockBack(Vec2DF::Left() * 8);
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
	this->transform.Translate(Vec2DF::Right() * (900 + 1380*4.3f), false, 1);
}

void Giant::Update(float deltaTime)
{
	if (isActive && (this->transform.Position - this->framework->GetPlayer().transform.Position).GetScaleSq() < (1380 * 1380))
	{
		this->playerAnime.Update(deltaTime);
		this->playerState.Update(deltaTime);
		this->transform.Update(deltaTime);
	}
}

void Giant::Draw(PaintInfo info)
{
	if (isActive)
	{
		this->playerAnime.GetCurrentImage().img->Draw(info.hdc, framework->GetCameraTransform(this->transform.Position - this->ImageMargin));
		this->playerAnime.GetCurrentCollisionData().Draw(info, framework->GetCameraTransform(this->transform.Position));
	}
}

void Giant::Damaged(int hp, bool off)
{
	auto thisState = this->playerState.GetCurrentState();
	this->hit++;
	GameStateObject::Damaged(hp, off);
	this->framework->EnemyHPBar(this->hp / this->maxHP, this, "mark-giant");
}
