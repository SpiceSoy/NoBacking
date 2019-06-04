#include "pch.h"
#include "Player.h"
#include "Collision.h"
#include "GameFramework.h"
#include <atlimage.h>
Player::Player(GameFramework* framework, const std::string& tag)
	:GameStateObject(framework, tag)
{
	this->playerAnime.Set("character1", "character", "character");
	ImageMargin = Vec2DF{ 128,184 };

	auto hittedFunc = [this, framework](GameStateObject & object, GameStateObject & other, const CollisionResult::ResultVector & result)->bool
	{
		for (auto& res : result)
		{
			if (res.first == "body" && res.second == "attack1" && this->isCanDamaged)
			{
				framework->OnEffect("effect1", this->transform.Position);
				SoundSystem::PlaySound("hit-bite");
				if (hp == 0)
				{
					this->transform.KnockBack((Vec2DF::Left() * 0.1f) + (Vec2DF::Up() * 0.5f));
					object.playerState.ChangeState(CharacterNormalState::MOTION14);
				}
				else
				{
					this->transform.KnockBack(Vec2DF::Left() * 1);
					object.playerState.ChangeState(CharacterNormalState::MOTION13);
				}
			}
		}
		return false;
	};
	auto jumphittedFunc = [this, framework](GameStateObject & object, GameStateObject & other, const CollisionResult::ResultVector & result)->bool
	{
		for (auto& res : result)
		{
			if (res.first == "body" && res.second == "attack1"&& this->isCanDamaged)
			{
				SoundSystem::PlaySound("hit-bite");
				framework->OnEffect("effect1", this->transform.Position);
				//this->transform.KnockBack((Vec2DF::Left() * 2) + (Vec2DF::Up() * 0.5f));
				this->transform.KnockBack((Vec2DF::Left() * 1.5f) + (Vec2DF::Up() * 1.5f));
				object.playerState.ChangeState(CharacterNormalState::MOTION14);
			}
		}
		return false;
	};
	auto guardFunc = [this, framework](GameStateObject & object, GameStateObject & other, const CollisionResult::ResultVector & result)->bool
	{
		for (auto& res : result)
		{
			if (res.second == "attack1" && this->isCanDamaged)
			{
					SoundSystem::PlaySound("hit-steel");
					framework->OnEffect("effect1", this->transform.Position);
					this->delayCounter = 0;
					this->transform.KnockBack(Vec2DF::Left() * 1);
			}
		}
		return false;
	};

#pragma region StateDef
	{
		//IDLE
		{
			this->playerState.SetStateFunctionSet(
				CharacterNormalState::IDLE,
				[](GameStateObject & object) -> void
				{
					auto& player = static_cast<Player&>(object);
					object.playerAnime.ChangeState(CharacterNormalState::IDLE);
				},
				[framework, &Costume = (this->Costume)](GameStateObject & object, float deltaTime) -> void
				{
					auto& player = static_cast<Player&>(object);
					if (GetAsyncKeyState(VK_DOWN) & 0x8000)
					{
						object.playerState.ChangeState(static_cast<CharacterNormalState>(PlayerState::GUARDUP));
					}
					else if (GetAsyncKeyState(VK_SPACE) & 0x8000)
					{
						object.transform.Jump(500);
						object.playerState.ChangeState(static_cast<CharacterNormalState>(PlayerState::JUMPUP));
					}
					else if (GetAsyncKeyState('T') & 0x0001)
					{
						switch (Costume % 3)
						{
						case 0:object.playerAnime.Set("character1", "character", "character"); break;
						case 1:object.playerAnime.Set("character2", "character", "character"); break;
						case 2:object.playerAnime.Set("character3", "character", "character"); break;
						}
						Costume++;
					}
					else if (GetAsyncKeyState('Y') & 0x0001)
					{
						framework->ToggleDebugCollision();
					}
					else if (GetAsyncKeyState('Z') & 0x8000)
					{
						object.playerState.ChangeState(static_cast<CharacterNormalState>(PlayerState::SLASH));
					}
					else if (GetAsyncKeyState('X') & 0x8000)
					{
						object.playerState.ChangeState(static_cast<CharacterNormalState>(PlayerState::STING));
					}
					else if (GetAsyncKeyState(VK_LEFT) & 0x8000)
					{
						object.playerAnime.ChangeState(CharacterNormalState::MOTION1);
						object.transform.Translate(Vec2DF::Left() * 150.0f * deltaTime, false);
					}
					else if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
					{
						object.playerAnime.ChangeState(CharacterNormalState::MOTION2);
						object.transform.Translate(Vec2DF::Right() * 350.0f * deltaTime, false);
					}
					else
					{
						object.playerAnime.ChangeState(CharacterNormalState::IDLE);
					}
				},
					[](GameStateObject & object, CharacterNormalState state) -> bool
				{
					return true;
				},
					hittedFunc
				);
		}
		//베기
		{
			this->playerState.SetStateFunctionSet(
				static_cast<CharacterNormalState>(PlayerState::SLASH),
				[this](GameStateObject & object) -> void
				{
					auto& player = static_cast<Player&>(object);
					object.playerAnime.ChangeState(static_cast<CharacterNormalState>(PlayerState::SLASH), true);
					this->delayCounter = 0.0f;
				},
				[framework, this](GameStateObject & object, float deltaTime) -> void
				{
					auto& player = static_cast<Player&>(object);
					framework->CheckCollision(object);
					static bool snd = true;
					if (this->playerAnime.GetCurrentFrame() == 2 && snd)
					{
						SoundSystem::PlaySound("atk-slash");
						snd = false;
					}
					if (this->playerAnime.GetCurrentFrame() > 2)
					{
						snd = true;
					}
					if (this->delayCounter > object.playerAnime.GetTotalTime(static_cast<CharacterNormalState>(PlayerState::SLASH)) * 0.7)
					{
						if (GetAsyncKeyState('Z') & 0x8000)
						{
							object.playerState.ChangeState(static_cast<CharacterNormalState>(PlayerState::SLASH));
						}
						else if (GetAsyncKeyState('X') & 0x8000)
						{
							object.playerState.ChangeState(static_cast<CharacterNormalState>(PlayerState::STING));
						}
						else if (GetAsyncKeyState(VK_DOWN) & 0x8000)
						{
							object.playerState.ChangeState(static_cast<CharacterNormalState>(PlayerState::GUARDUP));
						}
					}
					if (object.playerAnime.isEnd(static_cast<CharacterNormalState>(PlayerState::SLASH)))
					{
						object.playerState.ChangeState(static_cast<CharacterNormalState>(PlayerState::IDLE));
					}
				},
					[](GameStateObject & object, CharacterNormalState state) -> bool
				{
					return true;
				},
				hittedFunc
				);
		}
		//찌르기
		{
			this->playerState.SetStateFunctionSet(
				static_cast<CharacterNormalState>(PlayerState::STING),
				[this](GameStateObject & object) -> void
				{
					auto& player = static_cast<Player&>(object);
					object.playerAnime.ChangeState(static_cast<CharacterNormalState>(PlayerState::STING), true);
					this->delayCounter = 0.0f;
				},
				[framework, this](GameStateObject & object, float deltaTime) -> void
				{
					auto& player = static_cast<Player&>(object);
					framework->CheckCollision(object);
					static bool snd = true;
					if (this->playerAnime.GetCurrentFrame() == 2 && snd)
					{
						SoundSystem::PlaySound("atk-slash");
						snd = false;
					}
					if (this->playerAnime.GetCurrentFrame() > 2)
					{
						snd = true;
					}
					if (this->delayCounter > object.playerAnime.GetTotalTime(static_cast<CharacterNormalState>(PlayerState::STING)) * 0.7)
					{
						if (GetAsyncKeyState('X') & 0x8000)
						{
							object.playerState.ChangeState(static_cast<CharacterNormalState>(PlayerState::STING));
						}
						else if (GetAsyncKeyState('Z') & 0x8000)
						{
							object.playerState.ChangeState(static_cast<CharacterNormalState>(PlayerState::SLASH));
						}
						else if (GetAsyncKeyState(VK_DOWN) & 0x8000)
						{
							object.playerState.ChangeState(static_cast<CharacterNormalState>(PlayerState::GUARDUP));
						}
					}
					if (object.playerAnime.isEnd(static_cast<CharacterNormalState>(PlayerState::STING)))
					{
						object.playerState.ChangeState(static_cast<CharacterNormalState>(PlayerState::IDLE));
					}
				},
					[](GameStateObject & object, CharacterNormalState state) -> bool
				{
					return true;
				},
					hittedFunc
				);
		}
		//가드
		{
			this->playerState.SetStateFunctionSet(
				static_cast<CharacterNormalState>(PlayerState::GUARDUP),
				[](GameStateObject & object) -> void
				{
					auto& player = static_cast<Player&>(object);
					object.playerAnime.ChangeState(static_cast<CharacterNormalState>(PlayerState::GUARDUP), true);
				},
				[](GameStateObject & object, float deltaTime) -> void
				{
					auto& player = static_cast<Player&>(object);
					if (object.playerAnime.isEnd(static_cast<CharacterNormalState>(PlayerState::GUARDUP)))
					{
						object.playerState.ChangeState(static_cast<CharacterNormalState>(PlayerState::GUARDON));
					}
				},
					[](GameStateObject & object, CharacterNormalState state) -> bool
				{
					return true;
				},
					guardFunc
				);
		}
		//점프업
		{
			this->playerState.SetStateFunctionSet(
				static_cast<CharacterNormalState>(PlayerState::JUMPUP),
				[](GameStateObject & object) -> void
				{
					auto& player = static_cast<Player&>(object);
					object.playerAnime.ChangeState(static_cast<CharacterNormalState>(PlayerState::JUMPUP), true);
				},
				[](GameStateObject & object, float deltaTime) -> void
				{
					auto& player = static_cast<Player&>(object);
					if (GetAsyncKeyState(VK_LEFT))
					{
						object.transform.Translate(Vec2DF::Left() * 150.0f * deltaTime);
					}
					else if (GetAsyncKeyState(VK_RIGHT))
					{
						object.transform.Translate(Vec2DF::Right() * 350.0f * deltaTime);
					}
					if (((GetAsyncKeyState('Z') & 0x8000) || (GetAsyncKeyState('X') & 0x8000)))
					{
						object.playerState.ChangeState(static_cast<CharacterNormalState>(PlayerState::JUMPATTACK1));
					}
					if (object.transform.GetJumpPower() < 0)
					{
						object.playerState.ChangeState(static_cast<CharacterNormalState>(PlayerState::JUMPDOWN));
					}
				},
					[](GameStateObject & object, CharacterNormalState state) -> bool
				{
					return true;
				},
					jumphittedFunc
				);
		}
		//점프다운
		{
			this->playerState.SetStateFunctionSet(
				static_cast<CharacterNormalState>(PlayerState::JUMPDOWN),
				[](GameStateObject & object) -> void
				{
					auto& player = static_cast<Player&>(object);
					object.playerAnime.ChangeState(static_cast<CharacterNormalState>(PlayerState::JUMPDOWN), true);
				},
				[](GameStateObject & object, float deltaTime) -> void
				{
					auto& player = static_cast<Player&>(object);
					if (GetAsyncKeyState(VK_LEFT))
					{
						object.transform.Translate(Vec2DF::Left() * 150.0f * deltaTime);
					}
					else if (GetAsyncKeyState(VK_RIGHT))
					{
						object.transform.Translate(Vec2DF::Right() * 350.0f * deltaTime);
					}
					if (((GetAsyncKeyState('X')) || (GetAsyncKeyState('Z'))))
					{
						object.playerState.ChangeState(static_cast<CharacterNormalState>(PlayerState::JUMPATTACK1));
					}
					if (!object.transform.GetJumpState())
					{
						object.playerState.ChangeState(static_cast<CharacterNormalState>(PlayerState::LANDING));
					}
				},
					[](GameStateObject & object, CharacterNormalState state) -> bool
				{
					return true;
				},
					jumphittedFunc
				);
		}
		//착지
		{
			this->playerState.SetStateFunctionSet(
				static_cast<CharacterNormalState>(PlayerState::LANDING),
				[](GameStateObject & object) -> void
				{
					auto& player = static_cast<Player&>(object);
					object.playerAnime.ChangeState(static_cast<CharacterNormalState>(PlayerState::LANDING), true);
				},
				[](GameStateObject & object, float deltaTime) -> void
				{
					auto& player = static_cast<Player&>(object);
					if (object.playerAnime.isEnd(static_cast<CharacterNormalState>(PlayerState::LANDING)))
					{
						object.transform.SetY(500);
						object.playerState.ChangeState(static_cast<CharacterNormalState>(PlayerState::IDLE));
					}
				},
					[](GameStateObject & object, CharacterNormalState state) -> bool
				{
					return true;
				},
					hittedFunc
				);
		}
		//점프공격 1
		{
			this->playerState.SetStateFunctionSet(
				static_cast<CharacterNormalState>(PlayerState::JUMPATTACK1),
				[this](GameStateObject & object) -> void
				{
					auto& player = static_cast<Player&>(object);
					object.playerAnime.ChangeState(static_cast<CharacterNormalState>(PlayerState::JUMPATTACK1), true);
					this->delayCounter = 0.0f;
				},
				[this](GameStateObject & object, float deltaTime) -> void
				{
					auto& player = static_cast<Player&>(object);
					static bool snd = true;
					if (this->playerAnime.GetCurrentFrame() == 2 && snd)
					{
						SoundSystem::PlaySound("atk-slash");
						snd = false;
					}
					if (this->playerAnime.GetCurrentFrame() > 2)
					{
						snd = true;
					}
					if (GetAsyncKeyState(VK_LEFT))
					{
						object.transform.Translate(Vec2DF::Left() * 150.0f * deltaTime);
					}
					else if (GetAsyncKeyState(VK_RIGHT))
					{
						object.transform.Translate(Vec2DF::Right() * 350.0f * deltaTime);
					}
					if (this->delayCounter > object.playerAnime.GetTotalTime(static_cast<CharacterNormalState>(PlayerState::JUMPATTACK1)) * 0.75 && ((GetAsyncKeyState('X') & 0x8000) || (GetAsyncKeyState('Z') & 0x8000)))
					{
						object.playerState.ChangeState(static_cast<CharacterNormalState>(PlayerState::JUMPATTACK2));
					}
					if (object.playerAnime.isEnd(static_cast<CharacterNormalState>(PlayerState::JUMPATTACK1)))
					{
						object.playerState.ChangeState(static_cast<CharacterNormalState>(PlayerState::JUMPUP));
					}
					if (!object.transform.GetJumpState())
					{
						object.transform.SetY(500);
						object.playerState.ChangeState(static_cast<CharacterNormalState>(PlayerState::IDLE));
					}
				},
					[](GameStateObject & object, CharacterNormalState state) -> bool
				{
					return true;
				},
					jumphittedFunc
				);
		}
		//점프공격 2
		{
			this->playerState.SetStateFunctionSet(
				static_cast<CharacterNormalState>(PlayerState::JUMPATTACK2),
				[this](GameStateObject & object) -> void
				{
					auto& player = static_cast<Player&>(object);
					object.playerAnime.ChangeState(static_cast<CharacterNormalState>(PlayerState::JUMPATTACK2), true);
					this->delayCounter = 0.0f;
				},
				[this](GameStateObject & object, float deltaTime) -> void
				{
					auto& player = static_cast<Player&>(object);
					static bool snd = true;
					if (this->playerAnime.GetCurrentFrame() == 2 && snd)
					{
						SoundSystem::PlaySound("atk-slash");
						snd = false;
					}
					if (this->playerAnime.GetCurrentFrame() > 2)
					{
						snd = true;
					}
					if (GetAsyncKeyState(VK_LEFT))
					{
						object.transform.Translate(Vec2DF::Left() * 150.0f * deltaTime);
					}
					else if (GetAsyncKeyState(VK_RIGHT))
					{
						object.transform.Translate(Vec2DF::Right() * 350.0f * deltaTime);
					}
					if (this->delayCounter > object.playerAnime.GetTotalTime(static_cast<CharacterNormalState>(PlayerState::JUMPATTACK2)) * 0.7 && ((GetAsyncKeyState('Z') & 0x8000) || (GetAsyncKeyState('X') & 0x8000)))
					{
						object.playerState.ChangeState(static_cast<CharacterNormalState>(PlayerState::JUMPATTACK1));
					}
					if (!object.transform.GetJumpState())
					{
						object.transform.SetY(500);
						object.playerState.ChangeState(static_cast<CharacterNormalState>(PlayerState::IDLE));
					}
				},
					[](GameStateObject & object, CharacterNormalState state) -> bool
				{
					return true;
				},
					jumphittedFunc
				);
		}

		//가드 온
		{
			this->playerState.SetStateFunctionSet(
				static_cast<CharacterNormalState>(PlayerState::GUARDON),
				[](GameStateObject & object) -> void
				{
					auto& player = static_cast<Player&>(object);
					object.playerAnime.ChangeState(static_cast<CharacterNormalState>(PlayerState::GUARDON), true);
				},
				[](GameStateObject & object, float deltaTime) -> void
				{
					auto& player = static_cast<Player&>(object);
					if (GetAsyncKeyState(VK_LEFT) || GetAsyncKeyState(VK_RIGHT))
					{
						object.playerState.ChangeState(static_cast<CharacterNormalState>(PlayerState::GUARDMOVE));
					}
					else if (!GetAsyncKeyState(VK_DOWN))
					{
						object.playerState.ChangeState(static_cast<CharacterNormalState>(PlayerState::IDLE));
					}
				},
					[](GameStateObject & object, CharacterNormalState state) -> bool
				{
					return true;
				},
					guardFunc
				);
		}

		//가드 이동
		{
			this->playerState.SetStateFunctionSet(
				static_cast<CharacterNormalState>(PlayerState::GUARDMOVE),
				[](GameStateObject & object) -> void
				{
					auto& player = static_cast<Player&>(object);
					object.playerAnime.ChangeState(static_cast<CharacterNormalState>(PlayerState::GUARDMOVE), true);
				},
				[](GameStateObject & object, float deltaTime) -> void
				{
					auto& player = static_cast<Player&>(object);
					if (!GetAsyncKeyState(VK_DOWN))
					{
						object.playerState.ChangeState(static_cast<CharacterNormalState>(PlayerState::IDLE));
					}
					else if (GetAsyncKeyState(VK_LEFT))
					{
						object.transform.Translate(Vec2DF::Left() * 150.0f * deltaTime);
					}
					else if (GetAsyncKeyState(VK_RIGHT))
					{
						object.transform.Translate(Vec2DF::Right() * 150.0f * deltaTime);
					}
					else
					{
						object.playerState.ChangeState(static_cast<CharacterNormalState>(PlayerState::GUARDON));
					}
				},
					[](GameStateObject & object, CharacterNormalState state) -> bool
				{
					return true;
				},
					guardFunc
				);
		}
		//피격
		{
			this->playerState.SetStateFunctionSet(
				CharacterNormalState::MOTION13,
				[](GameStateObject & object) -> void
				{
					auto& player = static_cast<Player&>(object);
					object.playerAnime.ChangeState(CharacterNormalState::MOTION13, true);
				},
				[](GameStateObject & object, float deltaTime) -> void
				{
					auto& player = static_cast<Player&>(object);
					if (object.playerAnime.isEnd(CharacterNormalState::MOTION13))
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
		//다운
		{
			this->playerState.SetStateFunctionSet(
				CharacterNormalState::MOTION14,
				[](GameStateObject & object) -> void
				{
					auto& player = static_cast<Player&>(object);
					object.playerAnime.ChangeState(CharacterNormalState::MOTION14, true);
				},
				[this](GameStateObject & object, float deltaTime) -> void
				{
					auto& player = static_cast<Player&>(object);
					if (object.playerAnime.isEnd(CharacterNormalState::MOTION14) && !object.transform.GetJumpState())
					{
						object.transform.SetY(500);
						if (this->hp == 0)
						{
							object.Deactive();
						}
						else 
						{
							object.playerState.ChangeState(CharacterNormalState::IDLE);
						}
					}
				},
					[](GameStateObject & object, CharacterNormalState state) -> bool
				{
					return true;
				}
				);
		}

	}
#pragma endregion
	this->playerState.ChangeState(static_cast<CharacterNormalState>(PlayerState::IDLE));
	this->transform.Translate(Vec2DF::Down() * 500, false, 1);
}

void Player::Update(float deltaTime)
{
	if (isActive)
	{
		this->delayCounter += deltaTime;
		this->transform.Update(deltaTime);
		this->playerAnime.Update(deltaTime);
		this->playerState.Update(deltaTime);
	}
}

void Player::Draw(PaintInfo info)
{
	if (isActive)
	{
		this->playerAnime.GetCurrentImage().img->Draw(info.hdc, this->transform.Position.x, this->transform.Position.y);
		this->playerAnime.GetCurrentCollisionData().Draw(info, this->transform.Position + ImageMargin);
	}
}
