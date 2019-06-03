#include "pch.h"
#include "Player.h"
#include "Collision.h"
#include "GameFramework.h"
#include <atlimage.h>
Player::Player(GameFramework* framework, const std::string& tag)
	:GameStateObject(framework, tag)
{
	const std::wstring imgFileDir = L"Resources/character/c1/";
	const std::string colFileDir = "Resources/character/col/";
	ImageMargin = Vec2DF{ 128,184 };
#pragma region AnimeDef
	//애니메이션 정의 시작
	{
		this->playerAnime.ReSize(79);
		//기본
		this->playerAnime.AddImage(imgFileDir + L"6.png");
		this->playerAnime.AddImage(imgFileDir + L"7.png");
		this->playerAnime.AddImage(imgFileDir + L"8.png");
		this->playerAnime.AddImage(imgFileDir + L"9.png");
		this->playerAnime.AddImage(imgFileDir + L"10.png");
		this->playerAnime.AddImage(imgFileDir + L"11.png");
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

		this->playerAnime.AddImage(imgFileDir + L"21.png");
		this->playerAnime.AddImage(imgFileDir + L"20.png");
		this->playerAnime.AddImage(imgFileDir + L"19.png");
		this->playerAnime.AddImage(imgFileDir + L"18.png");
		this->playerAnime.AddImage(imgFileDir + L"17.png");
		this->playerAnime.AddImage(imgFileDir + L"16.png");
		this->playerAnime.AddImage(imgFileDir + L"15.png");
		this->playerAnime.AddImage(imgFileDir + L"14.png");
		this->playerAnime.AddImage(imgFileDir + L"13.png");
		this->playerAnime.AddImage(imgFileDir + L"12.png");
		subAnim.next = CharacterNormalState::LOOP;
		subAnim.scale = 0.75;
		subAnim.subImageStartIndex = 6;
		subAnim.subImageSize = 10;
		this->playerAnime.AddMotion(CharacterNormalState::MOTION1, subAnim);
		//달리기
		this->playerAnime.AddImage(imgFileDir + L"22.png");
		this->playerAnime.AddImage(imgFileDir + L"23.png");
		this->playerAnime.AddImage(imgFileDir + L"24.png");
		this->playerAnime.AddImage(imgFileDir + L"25.png");
		this->playerAnime.AddImage(imgFileDir + L"26.png");
		this->playerAnime.AddImage(imgFileDir + L"27.png");
		this->playerAnime.AddImage(imgFileDir + L"28.png");
		this->playerAnime.AddImage(imgFileDir + L"29.png");
		subAnim.next = CharacterNormalState::LOOP;
		subAnim.scale = 0.75;
		subAnim.subImageStartIndex = 16;
		subAnim.subImageSize = 8;
		this->playerAnime.AddMotion(CharacterNormalState::MOTION2, subAnim);
		//가드
		this->playerAnime.AddImage(imgFileDir + L"84.png");
		this->playerAnime.AddImage(imgFileDir + L"85.png");
		this->playerAnime.AddImage(imgFileDir + L"86.png");
		this->playerAnime.AddImage(imgFileDir + L"87.png");
		this->playerAnime.AddImage(imgFileDir + L"88.png");
		this->playerAnime.AddImage(imgFileDir + L"89.png");
		this->playerAnime.AddImage(imgFileDir + L"90.png");
		subAnim.next = CharacterNormalState::None;
		subAnim.subImageStartIndex = 24;
		subAnim.subImageSize = 7;
		this->playerAnime.AddMotion(CharacterNormalState::MOTION3, subAnim);
		//찌르기
		this->playerAnime.AddImage(imgFileDir + L"60.png");
		this->playerAnime.AddImage(imgFileDir + L"61.png");
		this->playerAnime.AddImage(imgFileDir + L"62.png");
		this->playerAnime.AddImage(imgFileDir + L"63.png");
		this->playerAnime.AddImage(imgFileDir + L"64.png");
		this->playerAnime.AddImage(imgFileDir + L"65.png");
		subAnim.next = CharacterNormalState::None;
		subAnim.subImageStartIndex = 31;
		subAnim.scale = 1.15;
		subAnim.subImageSize = 6;
		this->playerAnime.AddMotion(CharacterNormalState::MOTION4, subAnim);
		//점프
		this->playerAnime.AddImage(imgFileDir + L"30.png");
		this->playerAnime.AddImage(imgFileDir + L"31.png");
		this->playerAnime.AddImage(imgFileDir + L"32.png");
		subAnim.next = CharacterNormalState::None;
		subAnim.subImageStartIndex = 37;
		subAnim.scale = 1.0;
		subAnim.subImageSize = 3;
		this->playerAnime.AddMotion(CharacterNormalState::MOTION5, subAnim);
		this->playerAnime.AddImage(imgFileDir + L"33.png");
		subAnim.next = CharacterNormalState::None;
		subAnim.subImageStartIndex = 40;
		subAnim.scale = 1.0;
		subAnim.subImageSize = 1;
		this->playerAnime.AddMotion(CharacterNormalState::MOTION6, subAnim);
		this->playerAnime.AddImage(imgFileDir + L"34.png");
		this->playerAnime.AddImage(imgFileDir + L"35.png");
		subAnim.next = CharacterNormalState::None;
		subAnim.subImageStartIndex = 41;
		subAnim.scale = 2.0;
		subAnim.subImageSize = 2;
		this->playerAnime.AddMotion(CharacterNormalState::MOTION7, subAnim);
		//점프 공격
		this->playerAnime.AddImage(imgFileDir + L"43.png");
		this->playerAnime.AddImage(imgFileDir + L"44.png");
		this->playerAnime.AddImage(imgFileDir + L"45.png");
		this->playerAnime.AddImage(imgFileDir + L"46.png");
		this->playerAnime.AddImage(imgFileDir + L"47.png");
		this->playerAnime.AddImage(imgFileDir + L"48.png");
		this->playerAnime.AddImage(imgFileDir + L"49.png");
		this->playerAnime.AddImage(imgFileDir + L"50.png");
		subAnim.next = CharacterNormalState::None;
		subAnim.subImageStartIndex = 43;
		subAnim.scale = 1.0;
		subAnim.subImageSize = 8;
		this->playerAnime.AddMotion(CharacterNormalState::MOTION8, subAnim);
		//베기
		this->playerAnime.AddImage(imgFileDir + L"51.png");
		this->playerAnime.AddImage(imgFileDir + L"52.png");
		this->playerAnime.AddImage(imgFileDir + L"53.png");
		this->playerAnime.AddImage(imgFileDir + L"54.png");
		this->playerAnime.AddImage(imgFileDir + L"55.png");
		this->playerAnime.AddImage(imgFileDir + L"56.png");
		this->playerAnime.AddImage(imgFileDir + L"57.png");
		this->playerAnime.AddImage(imgFileDir + L"58.png");
		this->playerAnime.AddImage(imgFileDir + L"59.png");
		subAnim.next = CharacterNormalState::None;
		subAnim.subImageStartIndex = 51;
		subAnim.scale = 1.0;
		subAnim.subImageSize = 9;
		this->playerAnime.AddMotion(CharacterNormalState::MOTION9, subAnim);

		//점공2
		this->playerAnime.AddImage(imgFileDir + L"36.png");
		this->playerAnime.AddImage(imgFileDir + L"37.png");
		this->playerAnime.AddImage(imgFileDir + L"38.png");
		this->playerAnime.AddImage(imgFileDir + L"39.png");
		this->playerAnime.AddImage(imgFileDir + L"40.png");
		this->playerAnime.AddImage(imgFileDir + L"41.png");
		this->playerAnime.AddImage(imgFileDir + L"42.png");
		this->playerAnime.AddImage(imgFileDir + L"43.png");
		this->playerAnime.AddImage(imgFileDir + L"44.png");
		this->playerAnime.AddImage(imgFileDir + L"45.png");
		this->playerAnime.AddImage(imgFileDir + L"46.png");
		subAnim.next = CharacterNormalState::None;
		subAnim.subImageStartIndex = 60;
		subAnim.scale = 1.0;
		subAnim.subImageSize = 11;
		this->playerAnime.AddMotion(CharacterNormalState::MOTION10, subAnim);

		//가드 이동
		this->playerAnime.AddImage(imgFileDir + L"91.png");
		this->playerAnime.AddImage(imgFileDir + L"92.png");
		this->playerAnime.AddImage(imgFileDir + L"93.png");
		this->playerAnime.AddImage(imgFileDir + L"94.png");
		this->playerAnime.AddImage(imgFileDir + L"95.png");
		this->playerAnime.AddImage(imgFileDir + L"96.png");
		this->playerAnime.AddImage(imgFileDir + L"97.png");
		this->playerAnime.AddImage(imgFileDir + L"98.png");
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
				[](GameStateObject& object) -> void
				{
					auto& player = static_cast<Player&>(object);
					player.playerAnime.ChangeState(CharacterNormalState::IDLE);
				},
				[](GameStateObject& object, float deltaTime) -> void
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
						player.transform.Translate(Vec2DF::Left()* 150.0f* deltaTime, false);
					}
					else if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
					{
						player.playerAnime.ChangeState(CharacterNormalState::MOTION2);
						player.transform.Translate(Vec2DF::Right()* 350.0f* deltaTime, false);
					}
					else
					{
						player.playerAnime.ChangeState(CharacterNormalState::IDLE);
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
				[](GameStateObject& object) -> void
				{
					auto& player = static_cast<Player&>(object);
					player.playerAnime.ChangeState(static_cast<CharacterNormalState>(PlayerState::SLASH), true);
					player.delayCounter = 0.0f;
				},
				[framework](GameStateObject& object, float deltaTime) -> void
				{
					auto& player = static_cast<Player&>(object);
					player.delayCounter += deltaTime;
					framework->CheckCollision(object);
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
						else if (GetAsyncKeyState(VK_DOWN) & 0x8000)
						{
							player.playerState.ChangeState(static_cast<CharacterNormalState>(PlayerState::GUARDUP));
						}
					}
					if (player.playerAnime.isEnd(static_cast<CharacterNormalState>(PlayerState::SLASH)))
					{
						player.playerState.ChangeState(static_cast<CharacterNormalState>(PlayerState::IDLE));
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
				[](GameStateObject& object) -> void
				{
					auto& player = static_cast<Player&>(object);
					player.playerAnime.ChangeState(static_cast<CharacterNormalState>(PlayerState::STING), true);
					player.delayCounter = 0.0f;
				},
				[framework](GameStateObject& object, float deltaTime) -> void
				{
					auto& player = static_cast<Player&>(object);
					player.delayCounter += deltaTime;
					framework->CheckCollision(object);
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
						else if (GetAsyncKeyState(VK_DOWN) & 0x8000)
						{
							player.playerState.ChangeState(static_cast<CharacterNormalState>(PlayerState::GUARDUP));
						}
					}
					if (player.playerAnime.isEnd(static_cast<CharacterNormalState>(PlayerState::STING)))
					{
						player.playerState.ChangeState(static_cast<CharacterNormalState>(PlayerState::IDLE));
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
					player.playerAnime.ChangeState(static_cast<CharacterNormalState>(PlayerState::GUARDUP), true);
				},
				[](GameStateObject& object, float deltaTime) -> void
				{
					auto& player = static_cast<Player&>(object);
					if (player.playerAnime.isEnd(static_cast<CharacterNormalState>(PlayerState::GUARDUP)))
					{
						player.playerState.ChangeState(static_cast<CharacterNormalState>(PlayerState::GUARDON));
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
					player.playerAnime.ChangeState(static_cast<CharacterNormalState>(PlayerState::JUMPUP), true);
				},
				[](GameStateObject& object, float deltaTime) -> void
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
					player.playerAnime.ChangeState(static_cast<CharacterNormalState>(PlayerState::JUMPDOWN), true);
				},
				[](GameStateObject& object, float deltaTime) -> void
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
					player.playerAnime.ChangeState(static_cast<CharacterNormalState>(PlayerState::LANDING), true);
				},
				[](GameStateObject& object, float deltaTime) -> void
				{
					auto& player = static_cast<Player&>(object);
					if (player.playerAnime.isEnd(static_cast<CharacterNormalState>(PlayerState::LANDING)))
					{
						player.transform.SetY(500);
						player.playerState.ChangeState(static_cast<CharacterNormalState>(PlayerState::IDLE));
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
				[](GameStateObject& object) -> void
				{
					auto& player = static_cast<Player&>(object);
					player.playerAnime.ChangeState(static_cast<CharacterNormalState>(PlayerState::JUMPATTACK1), true);
					player.delayCounter = 0.0f;
				},
				[](GameStateObject& object, float deltaTime) -> void
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
				[](GameStateObject& object) -> void
				{
					auto& player = static_cast<Player&>(object);
					player.playerAnime.ChangeState(static_cast<CharacterNormalState>(PlayerState::JUMPATTACK2), true);
					player.delayCounter = 0.0f;
				},
				[](GameStateObject& object, float deltaTime) -> void
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
					player.playerAnime.ChangeState(static_cast<CharacterNormalState>(PlayerState::GUARDON), true);
				},
				[](GameStateObject& object, float deltaTime) -> void
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
					player.playerAnime.ChangeState(static_cast<CharacterNormalState>(PlayerState::GUARDMOVE), true);
				},
				[](GameStateObject& object, float deltaTime) -> void
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
					[](GameStateObject& object, CharacterNormalState state) -> bool
				{
					return true;
				}
				);
		}

	}
	//State 정의 끝
#pragma endregion

#pragma region CollisionSet

	this->playerAnime.AddCollision(colFileDir + "6.txt");
	this->playerAnime.AddCollision(colFileDir + "7.txt");
	this->playerAnime.AddCollision(colFileDir + "8.txt");
	this->playerAnime.AddCollision(colFileDir + "9.txt");
	this->playerAnime.AddCollision(colFileDir + "10.txt");
	this->playerAnime.AddCollision(colFileDir + "11.txt");

	this->playerAnime.AddCollision(colFileDir + "21.txt");
	this->playerAnime.AddCollision(colFileDir + "20.txt");
	this->playerAnime.AddCollision(colFileDir + "19.txt");
	this->playerAnime.AddCollision(colFileDir + "18.txt");
	this->playerAnime.AddCollision(colFileDir + "17.txt");
	this->playerAnime.AddCollision(colFileDir + "16.txt");
	this->playerAnime.AddCollision(colFileDir + "15.txt");
	this->playerAnime.AddCollision(colFileDir + "14.txt");
	this->playerAnime.AddCollision(colFileDir + "13.txt");
	this->playerAnime.AddCollision(colFileDir + "12.txt");
	//달리기
	this->playerAnime.AddCollision(colFileDir + "22.txt");
	this->playerAnime.AddCollision(colFileDir + "23.txt");
	this->playerAnime.AddCollision(colFileDir + "24.txt");
	this->playerAnime.AddCollision(colFileDir + "25.txt");
	this->playerAnime.AddCollision(colFileDir + "26.txt");
	this->playerAnime.AddCollision(colFileDir + "27.txt");
	this->playerAnime.AddCollision(colFileDir + "28.txt");
	this->playerAnime.AddCollision(colFileDir + "29.txt");
	//가드
	this->playerAnime.AddCollision(colFileDir + "84.txt");
	this->playerAnime.AddCollision(colFileDir + "85.txt");
	this->playerAnime.AddCollision(colFileDir + "86.txt");
	this->playerAnime.AddCollision(colFileDir + "87.txt");
	this->playerAnime.AddCollision(colFileDir + "88.txt");
	this->playerAnime.AddCollision(colFileDir + "89.txt");
	this->playerAnime.AddCollision(colFileDir + "90.txt");
	//찌르기
	this->playerAnime.AddCollision(colFileDir + "60.txt");
	this->playerAnime.AddCollision(colFileDir + "61.txt");
	this->playerAnime.AddCollision(colFileDir + "62.txt");
	this->playerAnime.AddCollision(colFileDir + "63.txt");
	this->playerAnime.AddCollision(colFileDir + "64.txt");
	this->playerAnime.AddCollision(colFileDir + "65.txt");
	//점프
	this->playerAnime.AddCollision(colFileDir + "30.txt");
	this->playerAnime.AddCollision(colFileDir + "31.txt");
	this->playerAnime.AddCollision(colFileDir + "32.txt");
	this->playerAnime.AddCollision(colFileDir + "33.txt");
	this->playerAnime.AddCollision(colFileDir + "34.txt");
	this->playerAnime.AddCollision(colFileDir + "35.txt");
	//점프 공격
	this->playerAnime.AddCollision(colFileDir + "43.txt");
	this->playerAnime.AddCollision(colFileDir + "44.txt");
	this->playerAnime.AddCollision(colFileDir + "45.txt");
	this->playerAnime.AddCollision(colFileDir + "46.txt");
	this->playerAnime.AddCollision(colFileDir + "47.txt");
	this->playerAnime.AddCollision(colFileDir + "48.txt");
	this->playerAnime.AddCollision(colFileDir + "49.txt");
	this->playerAnime.AddCollision(colFileDir + "50.txt");
	//베기
	this->playerAnime.AddCollision(colFileDir + "51.txt");
	this->playerAnime.AddCollision(colFileDir + "52.txt");
	this->playerAnime.AddCollision(colFileDir + "53.txt");
	this->playerAnime.AddCollision(colFileDir + "54.txt");
	this->playerAnime.AddCollision(colFileDir + "55.txt");
	this->playerAnime.AddCollision(colFileDir + "56.txt");
	this->playerAnime.AddCollision(colFileDir + "57.txt");
	this->playerAnime.AddCollision(colFileDir + "58.txt");
	this->playerAnime.AddCollision(colFileDir + "59.txt");
	//점공2
	this->playerAnime.AddCollision(colFileDir + "36.txt");
	this->playerAnime.AddCollision(colFileDir + "37.txt");
	this->playerAnime.AddCollision(colFileDir + "38.txt");
	this->playerAnime.AddCollision(colFileDir + "39.txt");
	this->playerAnime.AddCollision(colFileDir + "40.txt");
	this->playerAnime.AddCollision(colFileDir + "41.txt");
	this->playerAnime.AddCollision(colFileDir + "42.txt");
	this->playerAnime.AddCollision(colFileDir + "43.txt");
	this->playerAnime.AddCollision(colFileDir + "44.txt");
	this->playerAnime.AddCollision(colFileDir + "45.txt");
	this->playerAnime.AddCollision(colFileDir + "46.txt");
	//가드 이동
	this->playerAnime.AddCollision(colFileDir + "91.txt");
	this->playerAnime.AddCollision(colFileDir + "92.txt");
	this->playerAnime.AddCollision(colFileDir + "93.txt");
	this->playerAnime.AddCollision(colFileDir + "94.txt");
	this->playerAnime.AddCollision(colFileDir + "95.txt");
	this->playerAnime.AddCollision(colFileDir + "96.txt");
	this->playerAnime.AddCollision(colFileDir + "97.txt");
	this->playerAnime.AddCollision(colFileDir + "98.txt");

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
	this->playerAnime.GetCurrentImage().img.Draw(info.hdc, this->transform.Position.x, this->transform.Position.y);
	this->playerAnime.GetCurrentCollisionData().Draw(info, this->transform.Position + ImageMargin);
}
