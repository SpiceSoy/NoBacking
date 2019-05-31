#include "pch.h"
#include "Player.h"
#include "Collision.h"
#include <atlimage.h>
Player::Player(GameFramework* framework, const std::string& tag)
	:GameObject(framework, tag), playerState(this)
{
	const std::wstring fileDir = L"Resources/c1/";
#pragma region AnimeDef
	//애니메이션 정의 시작
	{
		this->playerAnime.ReSize(79);
		//기본
		this->playerAnime.AddImage(fileDir + L"6.png");
		this->playerAnime.AddImage(fileDir + L"7.png");
		this->playerAnime.AddImage(fileDir + L"8.png");
		this->playerAnime.AddImage(fileDir + L"9.png");
		this->playerAnime.AddImage(fileDir + L"10.png");
		this->playerAnime.AddImage(fileDir + L"11.png");
		subAnimation subAnim;
		subAnim.next = CharacterNormalState::LOOP;
		subAnim.scale = 0.85;
		subAnim.subImageStartIndex = 0;
		subAnim.subImageSize = 6;
		this->playerAnime.AddMotion(CharacterNormalState::IDLE, subAnim);
		//걷기
		//this->playerAnime.AddImage(fileDir + L"12.png");
		//this->playerAnime.AddImage(fileDir + L"13.png");
		//this->playerAnime.AddImage(fileDir + L"14.png");
		//this->playerAnime.AddImage(fileDir + L"15.png");
		//this->playerAnime.AddImage(fileDir + L"16.png");
		//this->playerAnime.AddImage(fileDir + L"17.png");
		//this->playerAnime.AddImage(fileDir + L"18.png");
		//this->playerAnime.AddImage(fileDir + L"19.png");
		//this->playerAnime.AddImage(fileDir + L"20.png");
		//this->playerAnime.AddImage(fileDir + L"21.png");

		this->playerAnime.AddImage(fileDir + L"21.png");
		this->playerAnime.AddImage(fileDir + L"20.png");
		this->playerAnime.AddImage(fileDir + L"19.png");
		this->playerAnime.AddImage(fileDir + L"18.png");
		this->playerAnime.AddImage(fileDir + L"17.png");
		this->playerAnime.AddImage(fileDir + L"16.png");
		this->playerAnime.AddImage(fileDir + L"15.png");
		this->playerAnime.AddImage(fileDir + L"14.png");
		this->playerAnime.AddImage(fileDir + L"13.png");
		this->playerAnime.AddImage(fileDir + L"12.png");
		subAnim.next = CharacterNormalState::LOOP;
		subAnim.scale = 0.75;
		subAnim.subImageStartIndex = 6;
		subAnim.subImageSize = 10;
		this->playerAnime.AddMotion(CharacterNormalState::MOTION1, subAnim);
		//달리기
		this->playerAnime.AddImage(fileDir + L"22.png");
		this->playerAnime.AddImage(fileDir + L"23.png");
		this->playerAnime.AddImage(fileDir + L"24.png");
		this->playerAnime.AddImage(fileDir + L"25.png");
		this->playerAnime.AddImage(fileDir + L"26.png");
		this->playerAnime.AddImage(fileDir + L"27.png");
		this->playerAnime.AddImage(fileDir + L"28.png");
		this->playerAnime.AddImage(fileDir + L"29.png");
		subAnim.next = CharacterNormalState::LOOP;
		subAnim.scale = 0.75;
		subAnim.subImageStartIndex = 16;
		subAnim.subImageSize = 8;
		this->playerAnime.AddMotion(CharacterNormalState::MOTION2, subAnim);
		//가드
		this->playerAnime.AddImage(fileDir + L"84.png");
		this->playerAnime.AddImage(fileDir + L"85.png");
		this->playerAnime.AddImage(fileDir + L"86.png");
		this->playerAnime.AddImage(fileDir + L"87.png");
		this->playerAnime.AddImage(fileDir + L"88.png");
		this->playerAnime.AddImage(fileDir + L"89.png");
		this->playerAnime.AddImage(fileDir + L"90.png");
		subAnim.next = CharacterNormalState::None;
		subAnim.subImageStartIndex = 24;
		subAnim.subImageSize = 7;
		this->playerAnime.AddMotion(CharacterNormalState::MOTION3, subAnim);
		//찌르기
		this->playerAnime.AddImage(fileDir + L"60.png");
		this->playerAnime.AddImage(fileDir + L"61.png");
		this->playerAnime.AddImage(fileDir + L"62.png");
		this->playerAnime.AddImage(fileDir + L"63.png");
		this->playerAnime.AddImage(fileDir + L"64.png");
		this->playerAnime.AddImage(fileDir + L"65.png");
		subAnim.next = CharacterNormalState::None;
		subAnim.subImageStartIndex = 31;
		subAnim.scale = 1.15;
		subAnim.subImageSize = 6;
		this->playerAnime.AddMotion(CharacterNormalState::MOTION4, subAnim);
		//점프
		this->playerAnime.AddImage(fileDir + L"30.png");
		this->playerAnime.AddImage(fileDir + L"31.png");
		this->playerAnime.AddImage(fileDir + L"32.png");
		subAnim.next = CharacterNormalState::None;
		subAnim.subImageStartIndex = 37;
		subAnim.scale = 1.0;
		subAnim.subImageSize = 3;
		this->playerAnime.AddMotion(CharacterNormalState::MOTION5, subAnim);
		this->playerAnime.AddImage(fileDir + L"33.png");
		subAnim.next = CharacterNormalState::None;
		subAnim.subImageStartIndex = 40;
		subAnim.scale = 1.0;
		subAnim.subImageSize = 1;
		this->playerAnime.AddMotion(CharacterNormalState::MOTION6, subAnim);
		this->playerAnime.AddImage(fileDir + L"34.png");
		this->playerAnime.AddImage(fileDir + L"35.png");
		subAnim.next = CharacterNormalState::None;
		subAnim.subImageStartIndex = 41;
		subAnim.scale = 2.0;
		subAnim.subImageSize = 2;
		this->playerAnime.AddMotion(CharacterNormalState::MOTION7, subAnim);
		//점프 공격
		this->playerAnime.AddImage(fileDir + L"43.png");
		this->playerAnime.AddImage(fileDir + L"44.png");
		this->playerAnime.AddImage(fileDir + L"45.png");
		this->playerAnime.AddImage(fileDir + L"46.png");
		this->playerAnime.AddImage(fileDir + L"47.png");
		this->playerAnime.AddImage(fileDir + L"48.png");
		this->playerAnime.AddImage(fileDir + L"49.png");
		this->playerAnime.AddImage(fileDir + L"50.png");
		subAnim.next = CharacterNormalState::None;
		subAnim.subImageStartIndex = 43;
		subAnim.scale = 1.0;
		subAnim.subImageSize = 8;
		this->playerAnime.AddMotion(CharacterNormalState::MOTION8, subAnim);
		//베기
		this->playerAnime.AddImage(fileDir + L"51.png");
		this->playerAnime.AddImage(fileDir + L"52.png");
		this->playerAnime.AddImage(fileDir + L"53.png");
		this->playerAnime.AddImage(fileDir + L"54.png");
		this->playerAnime.AddImage(fileDir + L"55.png");
		this->playerAnime.AddImage(fileDir + L"56.png");
		this->playerAnime.AddImage(fileDir + L"57.png");
		this->playerAnime.AddImage(fileDir + L"58.png");
		this->playerAnime.AddImage(fileDir + L"59.png");
		subAnim.next = CharacterNormalState::None;
		subAnim.subImageStartIndex = 51;
		subAnim.scale = 1.0;
		subAnim.subImageSize = 9;
		this->playerAnime.AddMotion(CharacterNormalState::MOTION9, subAnim);

		//점공2
		this->playerAnime.AddImage(fileDir + L"36.png");
		this->playerAnime.AddImage(fileDir + L"37.png");
		this->playerAnime.AddImage(fileDir + L"38.png");
		this->playerAnime.AddImage(fileDir + L"39.png");
		this->playerAnime.AddImage(fileDir + L"40.png");
		this->playerAnime.AddImage(fileDir + L"41.png");
		this->playerAnime.AddImage(fileDir + L"42.png");
		this->playerAnime.AddImage(fileDir + L"43.png");
		this->playerAnime.AddImage(fileDir + L"44.png");
		this->playerAnime.AddImage(fileDir + L"45.png");
		this->playerAnime.AddImage(fileDir + L"46.png");
		subAnim.next = CharacterNormalState::None;
		subAnim.subImageStartIndex = 60;
		subAnim.scale = 1.0;
		subAnim.subImageSize = 11;
		this->playerAnime.AddMotion(CharacterNormalState::MOTION10, subAnim);

		//가드 이동
		this->playerAnime.AddImage(fileDir + L"91.png");
		this->playerAnime.AddImage(fileDir + L"92.png");
		this->playerAnime.AddImage(fileDir + L"93.png");
		this->playerAnime.AddImage(fileDir + L"94.png");
		this->playerAnime.AddImage(fileDir + L"95.png");
		this->playerAnime.AddImage(fileDir + L"96.png");
		this->playerAnime.AddImage(fileDir + L"97.png");
		this->playerAnime.AddImage(fileDir + L"98.png");
		subAnim.next = CharacterNormalState::LOOP;
		subAnim.subImageStartIndex = 71;
		subAnim.scale = 0.45;
		subAnim.subImageSize = 8;
		this->playerAnime.AddMotion(CharacterNormalState::MOTION11, subAnim);
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
				[](GameObject & object) -> void
				{
					auto& player = static_cast<Player&>(object);
					player.playerAnime.ChangeState(CharacterNormalState::IDLE);
				},
				[](GameObject & object, float deltaTime) -> void
				{
					auto& player = static_cast<Player&>(object);
					if (GetAsyncKeyState(VK_DOWN) & 0x8000)
					{
						player.playerState.ChangeState(static_cast<CharacterNormalState>(PlayerState::GUARDUP));
					}
					else if (GetAsyncKeyState(VK_SPACE) & 0x8000)
					{
						player.transform.Jump(500);
						player.playerState.ChangeState(static_cast<CharacterNormalState>(PlayerState::JUMPUP));
					}
					else if (GetAsyncKeyState('Z') & 0x8000)
					{
						player.playerState.ChangeState(static_cast<CharacterNormalState>(PlayerState::SLASH));
					}
					else if (GetAsyncKeyState('X') & 0x8000)
					{
						player.playerState.ChangeState(static_cast<CharacterNormalState>(PlayerState::STING));
					}
					else if (GetAsyncKeyState(VK_LEFT) & 0x8000)
					{
						player.playerAnime.ChangeState(CharacterNormalState::MOTION1);
						player.transform.Translate(Vec2DF::Left() * 150.0f * deltaTime);
					}
					else if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
					{
						player.playerAnime.ChangeState(CharacterNormalState::MOTION2);
						player.transform.Translate(Vec2DF::Right() * 350.0f * deltaTime);
					}
					else
					{
						player.playerAnime.ChangeState(CharacterNormalState::IDLE);
					}
				},
					[](GameObject & object, CharacterNormalState state) -> bool
				{
					return true;
				}
				);
		}
		//베기
		{
			this->playerState.SetStateFunctionSet(
				static_cast<CharacterNormalState>(PlayerState::SLASH),
				[](GameObject & object) -> void
				{
					auto& player = static_cast<Player&>(object);
					player.playerAnime.ChangeState(static_cast<CharacterNormalState>(PlayerState::SLASH), true);
					player.delayCounter = 0.0f;
				},
				[](GameObject & object, float deltaTime) -> void
				{
					auto& player = static_cast<Player&>(object);
					player.delayCounter += deltaTime;
					if (player.delayCounter > player.playerAnime.GetTotalTime(static_cast<CharacterNormalState>(PlayerState::SLASH)) * 0.7)
					{
						if (GetAsyncKeyState('Z') & 0x8000)
						{
							player.playerState.ChangeState(static_cast<CharacterNormalState>(PlayerState::SLASH));
						}
						else if (GetAsyncKeyState('X') & 0x8000)
						{
							player.playerState.ChangeState(static_cast<CharacterNormalState>(PlayerState::STING));
						}
					}
					if (player.playerAnime.isEnd(static_cast<CharacterNormalState>(PlayerState::SLASH)))
					{
						player.playerState.ChangeState(static_cast<CharacterNormalState>(PlayerState::IDLE));
					}
				},
					[](GameObject & object, CharacterNormalState state) -> bool
				{
					return true;
				}
				);
		}
		//찌르기
		{
			this->playerState.SetStateFunctionSet(
				static_cast<CharacterNormalState>(PlayerState::STING),
				[](GameObject & object) -> void
				{
					auto& player = static_cast<Player&>(object);
					player.playerAnime.ChangeState(static_cast<CharacterNormalState>(PlayerState::STING), true);
					player.delayCounter = 0.0f;
				},
				[](GameObject & object, float deltaTime) -> void
				{
					auto& player = static_cast<Player&>(object);
					player.delayCounter += deltaTime;
					if (player.delayCounter > player.playerAnime.GetTotalTime(static_cast<CharacterNormalState>(PlayerState::STING)) * 0.7)
					{
						if (GetAsyncKeyState('X') & 0x8000)
						{
							player.playerState.ChangeState(static_cast<CharacterNormalState>(PlayerState::STING));
						}
						else if (GetAsyncKeyState('Z') & 0x8000)
						{
							player.playerState.ChangeState(static_cast<CharacterNormalState>(PlayerState::SLASH));
						}
					}
					if (player.playerAnime.isEnd(static_cast<CharacterNormalState>(PlayerState::STING)))
					{
						player.playerState.ChangeState(static_cast<CharacterNormalState>(PlayerState::IDLE));
					}
				},
					[](GameObject & object, CharacterNormalState state) -> bool
				{
					return true;
				}
				);
		}
		//가드
		{
			this->playerState.SetStateFunctionSet(
				static_cast<CharacterNormalState>(PlayerState::GUARDUP),
				[](GameObject & object) -> void
				{
					auto& player = static_cast<Player&>(object);
					player.playerAnime.ChangeState(static_cast<CharacterNormalState>(PlayerState::GUARDUP), true);
				},
				[](GameObject & object, float deltaTime) -> void
				{
					auto& player = static_cast<Player&>(object);
					if (player.playerAnime.isEnd(static_cast<CharacterNormalState>(PlayerState::GUARDUP)))
					{
						player.playerState.ChangeState(static_cast<CharacterNormalState>(PlayerState::GUARDON));
					}
				},
					[](GameObject & object, CharacterNormalState state) -> bool
				{
					return true;
				}
				);
		}
		//점프업
		{
			this->playerState.SetStateFunctionSet(
				static_cast<CharacterNormalState>(PlayerState::JUMPUP),
				[](GameObject & object) -> void
				{
					auto& player = static_cast<Player&>(object);
					player.playerAnime.ChangeState(static_cast<CharacterNormalState>(PlayerState::JUMPUP), true);
				},
				[](GameObject & object, float deltaTime) -> void
				{
					auto& player = static_cast<Player&>(object);
					if (GetAsyncKeyState(VK_LEFT))
					{
						player.transform.Translate(Vec2DF::Left() * 150.0f * deltaTime);
					}
					else if (GetAsyncKeyState(VK_RIGHT))
					{
						player.transform.Translate(Vec2DF::Right() * 350.0f * deltaTime);
					}
					if (((GetAsyncKeyState('Z') & 0x8000) || (GetAsyncKeyState('X') & 0x8000)))
					{
						player.playerState.ChangeState(static_cast<CharacterNormalState>(PlayerState::JUMPATTACK1));
					}
					if (player.transform.GetJumpPower() < 0)
					{
						player.playerState.ChangeState(static_cast<CharacterNormalState>(PlayerState::JUMPDOWN));
					}
				},
					[](GameObject & object, CharacterNormalState state) -> bool
				{
					return true;
				}
				);
		}
		//점프다운
		{
			this->playerState.SetStateFunctionSet(
				static_cast<CharacterNormalState>(PlayerState::JUMPDOWN),
				[](GameObject & object) -> void
				{
					auto& player = static_cast<Player&>(object);
					player.playerAnime.ChangeState(static_cast<CharacterNormalState>(PlayerState::JUMPDOWN), true);
				},
				[](GameObject & object, float deltaTime) -> void
				{
					auto& player = static_cast<Player&>(object);
					if (GetAsyncKeyState(VK_LEFT))
					{
						player.transform.Translate(Vec2DF::Left() * 150.0f * deltaTime);
					}
					else if (GetAsyncKeyState(VK_RIGHT))
					{
						player.transform.Translate(Vec2DF::Right() * 350.0f * deltaTime);
					}
					if (((GetAsyncKeyState('X') ) || (GetAsyncKeyState('Z'))))
					{
						player.playerState.ChangeState(static_cast<CharacterNormalState>(PlayerState::JUMPATTACK1));
					}
					if (!player.transform.GetJumpState())
					{
						player.playerState.ChangeState(static_cast<CharacterNormalState>(PlayerState::LANDING));
					}
				},
					[](GameObject & object, CharacterNormalState state) -> bool
				{
					return true;
				}
				);
		}
		//착지
		{
			this->playerState.SetStateFunctionSet(
				static_cast<CharacterNormalState>(PlayerState::LANDING),
				[](GameObject & object) -> void
				{
					auto& player = static_cast<Player&>(object);
					player.playerAnime.ChangeState(static_cast<CharacterNormalState>(PlayerState::LANDING), true);
				},
				[](GameObject & object, float deltaTime) -> void
				{
					auto& player = static_cast<Player&>(object);
					if (player.playerAnime.isEnd(static_cast<CharacterNormalState>(PlayerState::LANDING)))
					{
						player.playerState.ChangeState(static_cast<CharacterNormalState>(PlayerState::IDLE));
					}
				},
					[](GameObject & object, CharacterNormalState state) -> bool
				{
					return true;
				}
				);
		}
		//점프공격 1
		{
			this->playerState.SetStateFunctionSet(
				static_cast<CharacterNormalState>(PlayerState::JUMPATTACK1),
				[](GameObject & object) -> void
				{
					auto& player = static_cast<Player&>(object);
					player.playerAnime.ChangeState(static_cast<CharacterNormalState>(PlayerState::JUMPATTACK1), true);
					player.delayCounter = 0.0f;
				},
				[](GameObject & object, float deltaTime) -> void
				{
					auto& player = static_cast<Player&>(object);
					player.delayCounter += deltaTime;
					if (GetAsyncKeyState(VK_LEFT))
					{
						player.transform.Translate(Vec2DF::Left() * 150.0f * deltaTime);
					}
					else if (GetAsyncKeyState(VK_RIGHT))
					{
						player.transform.Translate(Vec2DF::Right() * 350.0f * deltaTime);
					}
					if (player.delayCounter > player.playerAnime.GetTotalTime(static_cast<CharacterNormalState>(PlayerState::JUMPATTACK1)) * 0.75 && ((GetAsyncKeyState('X') & 0x8000) || (GetAsyncKeyState('Z') & 0x8000)))
					{
						player.playerState.ChangeState(static_cast<CharacterNormalState>(PlayerState::JUMPATTACK2));
					}
					if (player.playerAnime.isEnd(static_cast<CharacterNormalState>(PlayerState::JUMPATTACK1)))
					{
						player.playerState.ChangeState(static_cast<CharacterNormalState>(PlayerState::JUMPUP));
					}
					if (!player.transform.GetJumpState())
					{
						player.playerState.ChangeState(static_cast<CharacterNormalState>(PlayerState::IDLE));
					}
				},
					[](GameObject & object, CharacterNormalState state) -> bool
				{
					return true;
				}
				);
		}
		//점프공격 2
		{
			this->playerState.SetStateFunctionSet(
				static_cast<CharacterNormalState>(PlayerState::JUMPATTACK2),
				[](GameObject & object) -> void
				{
					auto& player = static_cast<Player&>(object);
					player.playerAnime.ChangeState(static_cast<CharacterNormalState>(PlayerState::JUMPATTACK2), true);
					player.delayCounter = 0.0f;
				},
				[](GameObject & object, float deltaTime) -> void
				{
					auto& player = static_cast<Player&>(object);
					player.delayCounter += deltaTime;
					if (GetAsyncKeyState(VK_LEFT))
					{
						player.transform.Translate(Vec2DF::Left() * 150.0f * deltaTime);
					}
					else if (GetAsyncKeyState(VK_RIGHT))
					{
						player.transform.Translate(Vec2DF::Right() * 350.0f * deltaTime);
					}
					if (player.delayCounter > player.playerAnime.GetTotalTime(static_cast<CharacterNormalState>(PlayerState::JUMPATTACK2)) * 0.7 && ((GetAsyncKeyState('Z') & 0x8000) || (GetAsyncKeyState('X') & 0x8000)))
					{
						player.playerState.ChangeState(static_cast<CharacterNormalState>(PlayerState::JUMPATTACK1));
					}
					if (!player.transform.GetJumpState())
					{
						player.playerState.ChangeState(static_cast<CharacterNormalState>(PlayerState::IDLE));
					}
				},
					[](GameObject & object, CharacterNormalState state) -> bool
				{
					return true;
				}
				);
		}

		//가드 온
		{
			this->playerState.SetStateFunctionSet(
				static_cast<CharacterNormalState>(PlayerState::GUARDON),
				[](GameObject & object) -> void
				{
					auto& player = static_cast<Player&>(object);
					player.playerAnime.ChangeState(static_cast<CharacterNormalState>(PlayerState::GUARDON), true);
				},
				[](GameObject & object, float deltaTime) -> void
				{
					auto& player = static_cast<Player&>(object);
					if (GetAsyncKeyState(VK_LEFT) || GetAsyncKeyState(VK_RIGHT))
					{
						player.playerState.ChangeState(static_cast<CharacterNormalState>(PlayerState::GUARDMOVE));
					}
					else if(!GetAsyncKeyState(VK_DOWN))
					{
						player.playerState.ChangeState(static_cast<CharacterNormalState>(PlayerState::IDLE));
					}
				},
					[](GameObject & object, CharacterNormalState state) -> bool
				{
					return true;
				}
				);
		}

		//가드 이동
		{
			this->playerState.SetStateFunctionSet(
				static_cast<CharacterNormalState>(PlayerState::GUARDMOVE),
				[](GameObject & object) -> void
				{
					auto& player = static_cast<Player&>(object);
					player.playerAnime.ChangeState(static_cast<CharacterNormalState>(PlayerState::GUARDMOVE), true);
				},
				[](GameObject & object, float deltaTime) -> void
				{
					auto& player = static_cast<Player&>(object);
					if (!GetAsyncKeyState(VK_DOWN))
					{
					player.playerState.ChangeState(static_cast<CharacterNormalState>(PlayerState::IDLE));
					}
					else if (GetAsyncKeyState(VK_LEFT))
					{
						player.transform.Translate(Vec2DF::Left() * 150.0f * deltaTime);
					}
					else if (GetAsyncKeyState(VK_RIGHT))
					{
						player.transform.Translate(Vec2DF::Right() * 150.0f * deltaTime);
					}
					else 
					{
						player.playerState.ChangeState(static_cast<CharacterNormalState>(PlayerState::GUARDON));
					}
				},
					[](GameObject & object, CharacterNormalState state) -> bool
				{
					return true;
				}
				);
		}

	}
	//State 정의 끝
#pragma endregion

#pragma region CollisionSet

	//6.png
	CollisionCollection cc(Vec2DF{0,-40}, 400.0f);
	Collision body(CollisionTag::PlayerBody, Vec2DF{ 0,-40 },90.0f);
	Collision weapon(CollisionTag::PlayerAttack, Vec2DF{ 55,-70 }, 80.0f);
	body.AddCollision(SubCollisionData{ CollisionShapeType::Circle,Vec2DF{0,-70},Vec2DF{20.0f,0.0f} });
	cc.AddCollision((body));
	cc.AddCollision((weapon));
	this->playerAnime.AddCollision((cc));
	//7.png
	this->playerAnime.AddCollision((cc));
	//8.png
	this->playerAnime.AddCollision((cc));
	//9.png
	this->playerAnime.AddCollision((cc));
	//10.png
	this->playerAnime.AddCollision((cc));
	//11.png
	this->playerAnime.AddCollision((cc));

#pragma endregion


	this->playerState.ChangeState(static_cast<CharacterNormalState>(PlayerState::IDLE));
	this->transform.Translate(Vec2DF::Down() * 500, 1);

}

void Player::Update(float deltaTime)
{
	this->transform.Update(deltaTime);
	this->playerAnime.Update(deltaTime);
	this->playerState.Update(deltaTime);
}

void Player::Draw(PaintInfo info)
{
	auto rt = RECT{ 0,0,2200,2200 };
	FillRect(info.hdc, &rt, (HBRUSH)GetStockObject(WHITE_BRUSH));
	this->playerAnime.GetCurrentImage().img.Draw(info.hdc, this->transform.Position.x, this->transform.Position.y);
	this->playerAnime.GetCurrentCollisionData().Draw(info, this->transform.Position + ImageMargin);
}
