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

	auto hittedFunc = [this, framework,tag](GameStateObject & object, GameStateObject & other, const CollisionResult::ResultVector & result)->bool
	{
		if (other.tag != object.tag)
		{
			for (auto& res : result)
			{
				if (res.first == "body" && (res.second == "attack1" || res.second == "weapon") && this->isCanDamaged)
				{
					framework->OnEffect("effect1", this->transform.Position + Vec2DF::Up() * 50);
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
		}
		return false;
	};
	auto jumphittedFunc = [this, framework](GameStateObject & object, GameStateObject & other, const CollisionResult::ResultVector & result)->bool
	{
		if (other.tag != object.tag)
		{
		for (auto& res : result)
		{
			if (res.first == "body" && (res.second == "attack1" || res.second == "weapon") && this->isCanDamaged)
			{
				SoundSystem::PlaySound("hit-bite");
				framework->OnEffect("effect1", this->transform.Position + Vec2DF::Up() * 50);
				this->transform.KnockBack((Vec2DF::Left() * 5) + (Vec2DF::Up() * 3.5f));
				//this->transform.KnockBack((Vec2DF::Left() * 1.5f) + (Vec2DF::Up() * 1.5f));
				object.playerState.ChangeState(CharacterNormalState::MOTION14);
			}
		}
		}
		return false;
	};
	auto guardFunc = [this, framework](GameStateObject & object, GameStateObject & other, const CollisionResult::ResultVector & result)->bool
	{
		if (other.tag != object.tag)
		{
		for (auto& res : result)
		{
			if ((res.second == "attack1" || res.second == "weapon") && this->isCanDamaged)
			{
					SoundSystem::PlaySound("hit-steel");
					if (object.playerState.GetCurrentState() == static_cast<CharacterNormalState>(PlayerState::GUARDUP)&& object.playerAnime.GetCurrentFrame() <= 2)
					{
						framework->OnEffect("perfect", this->transform.Position + Vec2DF::Up() * 55 + Vec2DF::Right() * 30);
						framework->OnEffect("shield", this->transform.Position + Vec2DF::Up() * 55 + Vec2DF::Right() * 30);
					}
					else 
					{
						framework->OnEffect("shield", this->transform.Position + Vec2DF::Up() * 55 + Vec2DF::Right() * 30);
					}
					this->delayCounter = 0;
					this->transform.KnockBack(Vec2DF::Left() * 0.5f);
			}
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
						object.transform.Translate(Vec2DF::Left() * 350.0f * deltaTime, false);
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
					//framework->CheckCollision(object);
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
					//framework->CheckCollision(object);
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
					if (this->delayCounter > object.playerAnime.GetTotalTime(static_cast<CharacterNormalState>(PlayerState::STING)) * 0.9)
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
				[this](GameStateObject & object) -> void
				{
					auto& player = static_cast<Player&>(object);
					object.playerAnime.ChangeState(static_cast<CharacterNormalState>(PlayerState::GUARDUP), true);
					this->isPerfect = false;
				},
				[this](GameStateObject & object, float deltaTime) -> void
				{
					auto& player = static_cast<Player&>(object);
					if (object.playerAnime.GetCurrentFrame() <= 2 && !this->isCanDamaged)
					{
						this->isPerfect = true;
					}
					if (this->isPerfect && (GetAsyncKeyState('Z') & 0x8000))
					{
						object.playerState.ChangeState(CharacterNormalState::MOTION15);
					}
					if (this->isPerfect && (GetAsyncKeyState('X') & 0x8000))
					{
						object.playerState.ChangeState(static_cast<CharacterNormalState>(PlayerState::GUARDUP));
					}
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
						object.transform.SetY(600);
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
						object.transform.SetY(600);
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
						object.transform.SetY(600);
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
				[this](GameStateObject & object, float deltaTime) -> void
				{
					auto& player = static_cast<Player&>(object);
					if (this->isPerfect && (GetAsyncKeyState('X') & 0x8000))
					{
						object.playerState.ChangeState(static_cast<CharacterNormalState>(PlayerState::GUARDUP));
					}
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
						object.transform.SetY(600);
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
			//카운터
			{
				this->playerState.SetStateFunctionSet(
					CharacterNormalState::MOTION15,
					[this](GameStateObject & object) -> void
					{
						auto& player = static_cast<Player&>(object);
						object.playerAnime.ChangeState(CharacterNormalState::MOTION15, true);
						this->delayCounter = 0;
					},
					[this](GameStateObject & object, float deltaTime) -> void
					{
						auto& player = static_cast<Player&>(object);
						if (this->delayCounter > object.playerAnime.GetTotalTime(CharacterNormalState::MOTION15) * 0.6)
						{
							if ((GetAsyncKeyState('X') & 0x8000)|| (GetAsyncKeyState('Z') & 0x8000)|| (GetAsyncKeyState(VK_DOWN) & 0x8000))
							{
								object.playerState.ChangeState(static_cast<CharacterNormalState>(PlayerState::IDLE));
								//object.playerState.ChangeState(static_cast<CharacterNormalState>(PlayerState::STING));
							}
							//if (GetAsyncKeyState('X') & 0x8000)
							//{
							//	object.playerState.ChangeState(static_cast<CharacterNormalState>(PlayerState::IDLE));
							//	//object.playerState.ChangeState(static_cast<CharacterNormalState>(PlayerState::STING));
							//}
							//else if (GetAsyncKeyState('Z') & 0x8000)
							//{
							//	object.playerState.ChangeState(static_cast<CharacterNormalState>(PlayerState::IDLE));
							//	//object.playerState.ChangeState(static_cast<CharacterNormalState>(PlayerState::SLASH));
							//}
							if (object.playerAnime.isEnd())
							{
								object.playerState.ChangeState(static_cast<CharacterNormalState>(PlayerState::IDLE));
							}
						}
					},
						[](GameStateObject & object, CharacterNormalState state) -> bool
					{
						return true;
					},
						guardFunc
						);
			}
		}

	}
#pragma endregion
	this->playerState.ChangeState(static_cast<CharacterNormalState>(PlayerState::IDLE));
	this->transform.Translate(Vec2DF::Down() * 600, false, 1);
	this->transform.Translate(Vec2DF::Right() * 300, false, 1);
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
		this->playerAnime.GetCurrentImage().img->Draw(info.hdc, framework->GetCameraTransform(this->transform.Position - this->ImageMargin));
		this->playerAnime.GetCurrentCollisionData().Draw(info, framework->GetCameraTransform(this->transform.Position));
	}
}
