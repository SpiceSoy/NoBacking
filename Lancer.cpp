#include "pch.h"
#include "Lancer.h"
#include "Collision.h"
#include "GameFramework.h"
#include "Player.h"
#include <atlimage.h>

Lancer::Lancer(GameFramework* framework, const std::string& tag)
	:GameStateObject(framework, tag)
{
	this->playerAnime.Set("lancer");
	ImageMargin = Vec2DF{ 290,250 };

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
			if (abs((framework->GetPlayer().transform.Position - object.transform.Position).x > 0) || abs((framework->GetPlayer().transform.Position - object.transform.Position).x) < 150) { // 바운드 처리되면 삭제
				object.playerAnime.ChangeState(CharacterNormalState::MOTION1); // 이동
				auto moveVec = (Vec2DF::Right());
				object.transform.Translate(moveVec * 450.0f * deltaTime);
			}
			else if (abs((framework->GetPlayer().transform.Position - object.transform.Position).x) > 150 && abs((framework->GetPlayer().transform.Position - object.transform.Position).x) < 300) {
				if (this->hit > 3) {
					this->hit = 0;
					object.playerState.ChangeState(CharacterNormalState::MOTION6);
				}
				else {
					int r = rand() % 2;
					if (r == 0) {
						object.playerState.ChangeState(CharacterNormalState::MOTION4);
					}
					else if (r == 1) {
						object.playerState.ChangeState(CharacterNormalState::MOTION5);
					}
				}
			}
			else if (abs((framework->GetPlayer().transform.Position - object.transform.Position).x) < 600 && abs((framework->GetPlayer().transform.Position - object.transform.Position).x) > 300)
			{
					object.playerAnime.ChangeState(CharacterNormalState::MOTION1);
					auto moveVec = ((framework->GetPlayer().transform.Position - object.transform.Position).x < 0) ? (Vec2DF::Left()) : (Vec2DF::Right());
					object.transform.Translate(moveVec * 100.0f * deltaTime);
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
				if (res.second == "weapon" && res.first != "bound")
				{
					this->Damaged(5);
					framework->OnEffect("effect1", this->transform.Position + Vec2DF::Up() * 50);
					SoundSystem::PlaySound("hit-cut");
					if (hp == 0)
					{
						object.playerState.ChangeState(CharacterNormalState::MOTION3); // 다운
					}
					else {
						object.playerState.ChangeState(CharacterNormalState::MOTION2); // 피격
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
			if (object.playerAnime.isEnd())
			{
				object.playerState.ChangeState(CharacterNormalState::IDLE);
			}
			framework->CheckCollision(object);
		},
			[framework](GameStateObject & object, CharacterNormalState state) -> bool
		{
			framework->GetPlayer().ResetDamageCounter();
			object.ResetDamageCounter();
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
					else {
						object.playerState.ChangeState(CharacterNormalState::MOTION2); // 피격
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
			CharacterNormalState::MOTION5,
			[](GameStateObject & object) -> void
		{
			object.playerAnime.ChangeState(CharacterNormalState::MOTION5);
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
			object.ResetDamageCounter();
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
					else {
						object.playerState.ChangeState(CharacterNormalState::MOTION2); // 피격
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
			object.playerAnime.ChangeState(CharacterNormalState::MOTION2);
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
			object.ResetDamageCounter();
			return true;
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
			if (object.playerAnime.isEnd())
			{
				object.playerState.ChangeState(CharacterNormalState::IDLE);
			}
			framework->GetPlayer().ResetDamageCounter();
			framework->CheckCollision(object);
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
				if (res.second == "weapon" && this->isCanDamaged && res.first != "bound")
				{
					this->Damaged(5);
					framework->OnEffect("effect1", this->transform.Position + Vec2DF::Up() * 50);
					SoundSystem::PlaySound("hit-cut");
					if (hp == 0)
					{
						object.playerState.ChangeState(CharacterNormalState::MOTION3);
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
		this->playerState.SetStateFunctionSet
		(
			CharacterNormalState::MOTION2,
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
	}
#pragma endregion
	this->playerState.ChangeState(CharacterNormalState::IDLE);
	this->hp = 100;
	this->transform.Translate(Vec2DF::Down() * 600, false, 1);
	this->transform.Translate(Vec2DF::Right() * (900 + 1380 * 3), false, 1);
}

void Lancer::Update(float deltaTime)
{
	if (isActive & (this->transform.Position - this->framework->GetPlayer().transform.Position).GetScaleSq() < (1380 * 1380))
	{
		this->playerAnime.Update(deltaTime);
		this->playerState.Update(deltaTime);
		this->transform.Update(deltaTime);
	}
}

void Lancer::Draw(PaintInfo info)
{
	if (isActive)
	{
		this->playerAnime.GetCurrentImage().img->Draw(info.hdc, framework->GetCameraTransform(this->transform.Position - this->ImageMargin));
		this->playerAnime.GetCurrentCollisionData().Draw(info, framework->GetCameraTransform(this->transform.Position));
	}
}

void Lancer::Damaged(int hp, bool off)
{
	auto thisState = this->playerState.GetCurrentState();
	GameStateObject::Damaged(hp, off);
	this->hit++;
	this->framework->EnemyHPBar(this->hp / this->maxHP, this, "mark-def");
}
