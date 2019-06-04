#include "pch.h"
#include "Player.h"
#include "Collision.h"
#include "GameFramework.h"
#include <atlimage.h>
Player::Player(GameFramework* framework, const std::string& tag)
	:GameStateObject(framework, tag)
{
	this->playerAnime.Set("character1", "character");

	ImageMargin = Vec2DF{ 128,184 };
#pragma region AnimeDef
	//애니메이션 모션 정의 시작
	{
		//기본
		subAnimation subAnim;
		subAnim.next = CharacterNormalState::LOOP;
		subAnim.scale = 0.85;
		subAnim.subImageStartIndex = 0;
		subAnim.subImageSize = 6;
		this->playerAnime.AddMotion(CharacterNormalState::IDLE, subAnim);
		//걷기
		subAnim.next = CharacterNormalState::LOOP;
		subAnim.scale = 0.75;
		subAnim.subImageStartIndex = 6;
		subAnim.subImageSize = 10;
		this->playerAnime.AddMotion(CharacterNormalState::MOTION1, subAnim);
		//달리기
		subAnim.next = CharacterNormalState::LOOP;
		subAnim.scale = 0.75;
		subAnim.subImageStartIndex = 16;
		subAnim.subImageSize = 8;
		this->playerAnime.AddMotion(CharacterNormalState::MOTION2, subAnim);
		//가드
		subAnim.next = CharacterNormalState::None;
		subAnim.subImageStartIndex = 24;
		subAnim.subImageSize = 7;
		this->playerAnime.AddMotion(CharacterNormalState::MOTION3, subAnim);
		//찌르기
		subAnim.next = CharacterNormalState::None;
		subAnim.subImageStartIndex = 31;
		subAnim.scale = 1.15;
		subAnim.subImageSize = 6;
		this->playerAnime.AddMotion(CharacterNormalState::MOTION4, subAnim);
		//점프
		subAnim.next = CharacterNormalState::None;
		subAnim.subImageStartIndex = 37;
		subAnim.scale = 1.0;
		subAnim.subImageSize = 3;
		this->playerAnime.AddMotion(CharacterNormalState::MOTION5, subAnim);
		//점프 중간
		subAnim.next = CharacterNormalState::None;
		subAnim.subImageStartIndex = 40;
		subAnim.scale = 1.0;
		subAnim.subImageSize = 1;
		this->playerAnime.AddMotion(CharacterNormalState::MOTION6, subAnim);
		//착지
		subAnim.next = CharacterNormalState::None;
		subAnim.subImageStartIndex = 41;
		subAnim.scale = 2.0;
		subAnim.subImageSize = 2;
		this->playerAnime.AddMotion(CharacterNormalState::MOTION7, subAnim);
		//점프 공격
		subAnim.next = CharacterNormalState::None;
		subAnim.subImageStartIndex = 43;
		subAnim.scale = 1.0;
		subAnim.subImageSize = 8;
		this->playerAnime.AddMotion(CharacterNormalState::MOTION8, subAnim);
		//베기
		subAnim.next = CharacterNormalState::None;
		subAnim.subImageStartIndex = 51;
		subAnim.scale = 1.0;
		subAnim.subImageSize = 9;
		this->playerAnime.AddMotion(CharacterNormalState::MOTION9, subAnim);
		//점공2
		subAnim.next = CharacterNormalState::None;
		subAnim.subImageStartIndex = 60;
		subAnim.scale = 1.0;
		subAnim.subImageSize = 11;
		this->playerAnime.AddMotion(CharacterNormalState::MOTION10, subAnim);
		//가드 이동
		subAnim.next = CharacterNormalState::LOOP;
		subAnim.subImageStartIndex = 71;
		subAnim.scale = 0.45;
		subAnim.subImageSize = 8;
		this->playerAnime.AddMotion(CharacterNormalState::MOTION11, subAnim);
		//가드 중
		subAnim.next = CharacterNormalState::LOOP;
		subAnim.subImageStartIndex = 30;
		subAnim.scale = 1.0;
		subAnim.subImageSize = 1;
		this->playerAnime.AddMotion(CharacterNormalState::MOTION12, subAnim);

	}
#pragma endregion

#pragma region StateDef
	//State 정의 시작
	{
	//IDLE
		{
			this->playerState.SetStateFunctionSet(
				CharacterNormalState::IDLE,
				[](GameStateObject& object) -> void
				{
					auto& player = static_cast<Player&>(object);
					object.playerAnime.ChangeState(CharacterNormalState::IDLE);
				},
				[framework, &Costume = (this->Costume)](GameStateObject& object, float deltaTime) -> void
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
						switch(Costume % 3)
						{
							case 0:object.playerAnime.Set("character1", "character"); break;
							case 1:object.playerAnime.Set("character2", "character"); break;
							case 2:object.playerAnime.Set("character3", "character"); break;
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
						object.transform.Translate(Vec2DF::Left()* 150.0f* deltaTime, false);
					}
					else if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
					{
						object.playerAnime.ChangeState(CharacterNormalState::MOTION2);
						object.transform.Translate(Vec2DF::Right()* 350.0f* deltaTime, false);
					}
					else
					{
						object.playerAnime.ChangeState(CharacterNormalState::IDLE);
					}
				},
					[](GameStateObject& object, CharacterNormalState state) -> bool
				{
					return true;
				}
				);
		}
		//베기
		{
			this->playerState.SetStateFunctionSet(
				static_cast<CharacterNormalState>(PlayerState::SLASH),
				[this](GameStateObject& object) -> void
				{
					auto& player = static_cast<Player&>(object);
					object.playerAnime.ChangeState(static_cast<CharacterNormalState>(PlayerState::SLASH), true);
					this->delayCounter = 0.0f;
				},
				[framework, this](GameStateObject& object, float deltaTime) -> void
				{
					auto& player = static_cast<Player&>(object);
					this->delayCounter += deltaTime;
					framework->CheckCollision(object);
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
					[](GameStateObject& object, CharacterNormalState state) -> bool
				{
					return true;
				}
				);
		}
		//찌르기
		{
			this->playerState.SetStateFunctionSet(
				static_cast<CharacterNormalState>(PlayerState::STING),
				[this](GameStateObject& object) -> void
				{
					auto& player = static_cast<Player&>(object);
					object.playerAnime.ChangeState(static_cast<CharacterNormalState>(PlayerState::STING), true);
					this->delayCounter = 0.0f;
				},
				[framework, this](GameStateObject& object, float deltaTime) -> void
				{
					auto& player = static_cast<Player&>(object);
					this->delayCounter += deltaTime;
					framework->CheckCollision(object);
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
					[](GameStateObject& object, CharacterNormalState state) -> bool
				{
					return true;
				}
				);
		}
		//가드
		{
			this->playerState.SetStateFunctionSet(
				static_cast<CharacterNormalState>(PlayerState::GUARDUP),
				[](GameStateObject& object) -> void
				{
					auto& player = static_cast<Player&>(object);
					object.playerAnime.ChangeState(static_cast<CharacterNormalState>(PlayerState::GUARDUP), true);
				},
				[](GameStateObject& object, float deltaTime) -> void
				{
					auto& player = static_cast<Player&>(object);
					if (object.playerAnime.isEnd(static_cast<CharacterNormalState>(PlayerState::GUARDUP)))
					{
						object.playerState.ChangeState(static_cast<CharacterNormalState>(PlayerState::GUARDON));
					}
				},
					[](GameStateObject& object, CharacterNormalState state) -> bool
				{
					return true;
				}
				);
		}
		//점프업
		{
			this->playerState.SetStateFunctionSet(
				static_cast<CharacterNormalState>(PlayerState::JUMPUP),
				[](GameStateObject& object) -> void
				{
					auto& player = static_cast<Player&>(object);
					object.playerAnime.ChangeState(static_cast<CharacterNormalState>(PlayerState::JUMPUP), true);
				},
				[](GameStateObject& object, float deltaTime) -> void
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
					[](GameStateObject& object, CharacterNormalState state) -> bool
				{
					return true;
				}
				);
		}
		//점프다운
		{
			this->playerState.SetStateFunctionSet(
				static_cast<CharacterNormalState>(PlayerState::JUMPDOWN),
				[](GameStateObject& object) -> void
				{
					auto& player = static_cast<Player&>(object);
					object.playerAnime.ChangeState(static_cast<CharacterNormalState>(PlayerState::JUMPDOWN), true);
				},
				[](GameStateObject& object, float deltaTime) -> void
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
					if (((GetAsyncKeyState('X') ) || (GetAsyncKeyState('Z'))))
					{
						object.playerState.ChangeState(static_cast<CharacterNormalState>(PlayerState::JUMPATTACK1));
					}
					if (!object.transform.GetJumpState())
					{
						object.playerState.ChangeState(static_cast<CharacterNormalState>(PlayerState::LANDING));
					}
				},
					[](GameStateObject& object, CharacterNormalState state) -> bool
				{
					return true;
				}
				);
		}
		//착지
		{
			this->playerState.SetStateFunctionSet(
				static_cast<CharacterNormalState>(PlayerState::LANDING),
				[](GameStateObject& object) -> void
				{
					auto& player = static_cast<Player&>(object);
					object.playerAnime.ChangeState(static_cast<CharacterNormalState>(PlayerState::LANDING), true);
				},
				[](GameStateObject& object, float deltaTime) -> void
				{
					auto& player = static_cast<Player&>(object);
					if (object.playerAnime.isEnd(static_cast<CharacterNormalState>(PlayerState::LANDING)))
					{
						object.transform.SetY(500);
						object.playerState.ChangeState(static_cast<CharacterNormalState>(PlayerState::IDLE));
					}
				},
					[](GameStateObject& object, CharacterNormalState state) -> bool
				{
					return true;
				}
				);
		}
		//점프공격 1
		{
			this->playerState.SetStateFunctionSet(
				static_cast<CharacterNormalState>(PlayerState::JUMPATTACK1),
				[this](GameStateObject& object) -> void
				{
					auto& player = static_cast<Player&>(object);
					object.playerAnime.ChangeState(static_cast<CharacterNormalState>(PlayerState::JUMPATTACK1), true);
					this->delayCounter = 0.0f;
				},
				[this](GameStateObject& object, float deltaTime) -> void
				{
					auto& player = static_cast<Player&>(object);
					this->delayCounter += deltaTime;
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
						object.playerState.ChangeState(static_cast<CharacterNormalState>(PlayerState::IDLE));
					}
				},
					[](GameStateObject& object, CharacterNormalState state) -> bool
				{
					return true;
				}
				);
		}
		//점프공격 2
		{
			this->playerState.SetStateFunctionSet(
				static_cast<CharacterNormalState>(PlayerState::JUMPATTACK2),
				[this](GameStateObject& object) -> void
				{
					auto& player = static_cast<Player&>(object);
					object.playerAnime.ChangeState(static_cast<CharacterNormalState>(PlayerState::JUMPATTACK2), true);
					this->delayCounter = 0.0f;
				},
				[this](GameStateObject& object, float deltaTime) -> void
				{
					auto& player = static_cast<Player&>(object);
					this->delayCounter += deltaTime;
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
						object.playerState.ChangeState(static_cast<CharacterNormalState>(PlayerState::IDLE));
					}
				},
					[](GameStateObject& object, CharacterNormalState state) -> bool
				{
					return true;
				}
				);
		}

		//가드 온
		{
			this->playerState.SetStateFunctionSet(
				static_cast<CharacterNormalState>(PlayerState::GUARDON),
				[](GameStateObject& object) -> void
				{
					auto& player = static_cast<Player&>(object);
					object.playerAnime.ChangeState(static_cast<CharacterNormalState>(PlayerState::GUARDON), true);
				},
				[](GameStateObject& object, float deltaTime) -> void
				{
					auto& player = static_cast<Player&>(object);
					if (GetAsyncKeyState(VK_LEFT) || GetAsyncKeyState(VK_RIGHT))
					{
						object.playerState.ChangeState(static_cast<CharacterNormalState>(PlayerState::GUARDMOVE));
					}
					else if(!GetAsyncKeyState(VK_DOWN))
					{
						object.playerState.ChangeState(static_cast<CharacterNormalState>(PlayerState::IDLE));
					}
				},
					[](GameStateObject& object, CharacterNormalState state) -> bool
				{
					return true;
				}
				);
		}

		//가드 이동
		{
			this->playerState.SetStateFunctionSet(
				static_cast<CharacterNormalState>(PlayerState::GUARDMOVE),
				[](GameStateObject& object) -> void
				{
					auto& player = static_cast<Player&>(object);
					object.playerAnime.ChangeState(static_cast<CharacterNormalState>(PlayerState::GUARDMOVE), true);
				},
				[](GameStateObject& object, float deltaTime) -> void
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
					[](GameStateObject& object, CharacterNormalState state) -> bool
				{
					return true;
				}
				);
		}

	}
	//State 정의 끝
#pragma endregion


	this->playerState.ChangeState(static_cast<CharacterNormalState>(PlayerState::IDLE));
	this->transform.Translate(Vec2DF::Down() * 500,false, 1);

}

void Player::Update(float deltaTime)
{
	this->transform.Update(deltaTime);
	this->playerAnime.Update(deltaTime);
	this->playerState.Update(deltaTime);
}

void Player::Draw(PaintInfo info)
{
	this->playerAnime.GetCurrentImage().img->Draw(info.hdc, this->transform.Position.x, this->transform.Position.y);
	this->playerAnime.GetCurrentCollisionData().Draw(info, this->transform.Position + ImageMargin);
}
