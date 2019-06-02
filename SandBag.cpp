#include "pch.h"
#include "SandBag.h"
#include "Collision.h"
#include <atlimage.h>

SandBag::SandBag(GameFramework* framework, const std::string& tag)
	:GameStateObject(framework, tag)
{
	const std::wstring imgFileDir = L"Resources/sand/img/";
	const std::string colFileDir = "Resources/sand/col/";
	ImageMargin = Vec2DF{ 200,235 };
#pragma region AnimeDef
	this->playerAnime.ReSize(57);
	//아마 일반모션
	this->playerAnime.AddImage(imgFileDir + L"0.png");
	this->playerAnime.AddImage(imgFileDir + L"1.png");
	this->playerAnime.AddImage(imgFileDir + L"2.png");
	this->playerAnime.AddImage(imgFileDir + L"3.png");
	this->playerAnime.AddImage(imgFileDir + L"4.png");
	this->playerAnime.AddImage(imgFileDir + L"5.png");
	this->playerAnime.AddImage(imgFileDir + L"6.png");
	this->playerAnime.AddImage(imgFileDir + L"7.png");
	this->playerAnime.AddImage(imgFileDir + L"8.png");
	this->playerAnime.AddImage(imgFileDir + L"9.png");
	this->playerAnime.AddImage(imgFileDir + L"10.png");
	this->playerAnime.AddImage(imgFileDir + L"11.png");
	this->playerAnime.AddImage(imgFileDir + L"12.png");
	this->playerAnime.AddImage(imgFileDir + L"13.png");
	this->playerAnime.AddImage(imgFileDir + L"14.png");
	this->playerAnime.AddImage(imgFileDir + L"15.png");
	this->playerAnime.AddImage(imgFileDir + L"16.png");
	this->playerAnime.AddImage(imgFileDir + L"17.png");
	subAnimation subAnim;
	subAnim.next = CharacterNormalState::LOOP;
	subAnim.scale = 0.85;
	subAnim.subImageStartIndex = 0;
	subAnim.subImageSize = 18;
	//좌에서 우로 처맞
	this->playerAnime.AddMotion(CharacterNormalState::IDLE, subAnim);
	this->playerAnime.AddImage(imgFileDir + L"18.png");
	this->playerAnime.AddImage(imgFileDir + L"19.png");
	this->playerAnime.AddImage(imgFileDir + L"20.png");
	this->playerAnime.AddImage(imgFileDir + L"21.png");
	this->playerAnime.AddImage(imgFileDir + L"22.png");
	this->playerAnime.AddImage(imgFileDir + L"23.png");
	this->playerAnime.AddImage(imgFileDir + L"24.png");
	this->playerAnime.AddImage(imgFileDir + L"25.png");
	this->playerAnime.AddImage(imgFileDir + L"26.png");
	this->playerAnime.AddImage(imgFileDir + L"27.png");
	this->playerAnime.AddImage(imgFileDir + L"28.png");
	this->playerAnime.AddImage(imgFileDir + L"29.png");
	this->playerAnime.AddImage(imgFileDir + L"30.png");
	this->playerAnime.AddImage(imgFileDir + L"31.png");
	subAnim.next = CharacterNormalState::None;
	subAnim.scale = 0.85;
	subAnim.subImageStartIndex = 18;
	subAnim.subImageSize = 14;
	this->playerAnime.AddMotion(CharacterNormalState::MOTION1, subAnim);
	//우에서 좌로 쳐맞
	this->playerAnime.AddImage(imgFileDir + L"32.png");
	this->playerAnime.AddImage(imgFileDir + L"33.png");
	this->playerAnime.AddImage(imgFileDir + L"34.png");
	this->playerAnime.AddImage(imgFileDir + L"35.png");
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
	subAnim.next = CharacterNormalState::None;
	subAnim.scale = 0.85;
	subAnim.subImageStartIndex = 32;
	subAnim.subImageSize = 14;
	this->playerAnime.AddMotion(CharacterNormalState::MOTION2, subAnim);

	this->playerAnime.AddImage(imgFileDir + L"46.png");
	this->playerAnime.AddImage(imgFileDir + L"47.png");
	this->playerAnime.AddImage(imgFileDir + L"48.png");
	this->playerAnime.AddImage(imgFileDir + L"49.png");
	this->playerAnime.AddImage(imgFileDir + L"50.png");
	this->playerAnime.AddImage(imgFileDir + L"51.png");
	this->playerAnime.AddImage(imgFileDir + L"52.png");
	this->playerAnime.AddImage(imgFileDir + L"53.png");
	this->playerAnime.AddImage(imgFileDir + L"54.png");
	this->playerAnime.AddImage(imgFileDir + L"55.png");
	this->playerAnime.AddImage(imgFileDir + L"56.png");
	subAnim.next = CharacterNormalState::None;
	subAnim.scale = 0.85;
	subAnim.subImageStartIndex = 46;
	subAnim.subImageSize = 11;
	this->playerAnime.AddMotion(CharacterNormalState::MOTION3, subAnim);

#pragma endregion
#pragma region StateDef
	{
		this->playerState.SetStateFunctionSet
		(
			CharacterNormalState::IDLE,
			[](GameStateObject & object) -> void
			{
				auto& player = static_cast<SandBag&>(object);
				player.playerAnime.ChangeState(CharacterNormalState::IDLE);
			},
			[](GameStateObject& object, float deltaTime) -> void
			{
				auto& player = static_cast<SandBag&>(object);
				if (GetAsyncKeyState('J') & 0x8000)
				{
					player.playerState.ChangeState(CharacterNormalState::MOTION1);
				}
				else if (GetAsyncKeyState('K') & 0x8000)
				{
					player.playerState.ChangeState(CharacterNormalState::MOTION2);
				}
				else if (GetAsyncKeyState('L') & 0x8000)
				{
					player.playerState.ChangeState(CharacterNormalState::MOTION3);
				}
			},
			[](GameStateObject& object, CharacterNormalState state) -> bool
			{
				return true;
			}, 
			[](GameStateObject& object, GameStateObject& other, const CollisionResult::ResultVector& result)->bool
			{
				for (auto& res : result)
				{
					if (res.second == "weapon")
					{
						object.playerState.ChangeState(CharacterNormalState::MOTION1);
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
				auto& player = static_cast<SandBag&>(object);
				player.playerAnime.ChangeState(CharacterNormalState::MOTION1);
			},
			[](GameStateObject& object, float deltaTime) -> void
			{
				auto& player = static_cast<SandBag&>(object);
				if (player.playerAnime.isEnd())
				{
					player.playerState.ChangeState(CharacterNormalState::IDLE);
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
				auto& player = static_cast<SandBag&>(object);
				player.playerAnime.ChangeState(CharacterNormalState::MOTION2);
			},
			[](GameStateObject& object, float deltaTime) -> void
			{
				auto& player = static_cast<SandBag&>(object);
				if (player.playerAnime.isEnd())
				{
					player.playerState.ChangeState(CharacterNormalState::IDLE);
				}
			},
				[](GameStateObject& object, CharacterNormalState state) -> bool
			{
				return true;
			}
		);
		this->playerState.SetStateFunctionSet
		(
			CharacterNormalState::MOTION3,
			[](GameStateObject& object) -> void
			{
				auto& player = static_cast<SandBag&>(object);
				player.playerAnime.ChangeState(CharacterNormalState::MOTION3);
			},
			[](GameStateObject& object, float deltaTime) -> void
			{
				auto& player = static_cast<SandBag&>(object);
				if (player.playerAnime.isEnd())
				{
					player.playerState.ChangeState(CharacterNormalState::IDLE);
				}
			},
				[](GameStateObject& object, CharacterNormalState state) -> bool
			{
				return true;
			}
		);
	}
#pragma endregion
#pragma region CollisionSet
	this->playerAnime.AddCollision(colFileDir + "0.txt");
	this->playerAnime.AddCollision(colFileDir + "1.txt");
	this->playerAnime.AddCollision(colFileDir + "2.txt");
	this->playerAnime.AddCollision(colFileDir + "3.txt");
	this->playerAnime.AddCollision(colFileDir + "4.txt");
	this->playerAnime.AddCollision(colFileDir + "5.txt");
	this->playerAnime.AddCollision(colFileDir + "6.txt");
	this->playerAnime.AddCollision(colFileDir + "7.txt");
	this->playerAnime.AddCollision(colFileDir + "8.txt");
	this->playerAnime.AddCollision(colFileDir + "9.txt");
	this->playerAnime.AddCollision(colFileDir + "10.txt");
	this->playerAnime.AddCollision(colFileDir + "11.txt");
	this->playerAnime.AddCollision(colFileDir + "12.txt");
	this->playerAnime.AddCollision(colFileDir + "13.txt");
	this->playerAnime.AddCollision(colFileDir + "14.txt");
	this->playerAnime.AddCollision(colFileDir + "15.txt");
	this->playerAnime.AddCollision(colFileDir + "16.txt");
	this->playerAnime.AddCollision(colFileDir + "17.txt");
	this->playerAnime.AddCollision(colFileDir + "18.txt");
	this->playerAnime.AddCollision(colFileDir + "19.txt");
	this->playerAnime.AddCollision(colFileDir + "20.txt");
	this->playerAnime.AddCollision(colFileDir + "21.txt");
	this->playerAnime.AddCollision(colFileDir + "22.txt");
	this->playerAnime.AddCollision(colFileDir + "23.txt");
	this->playerAnime.AddCollision(colFileDir + "24.txt");
	this->playerAnime.AddCollision(colFileDir + "25.txt");
	this->playerAnime.AddCollision(colFileDir + "26.txt");
	this->playerAnime.AddCollision(colFileDir + "27.txt");
	this->playerAnime.AddCollision(colFileDir + "28.txt");
	this->playerAnime.AddCollision(colFileDir + "29.txt");
	this->playerAnime.AddCollision(colFileDir + "30.txt");
	this->playerAnime.AddCollision(colFileDir + "31.txt");
	this->playerAnime.AddCollision(colFileDir + "32.txt");
	this->playerAnime.AddCollision(colFileDir + "33.txt");
	this->playerAnime.AddCollision(colFileDir + "34.txt");
	this->playerAnime.AddCollision(colFileDir + "35.txt");
	this->playerAnime.AddCollision(colFileDir + "36.txt");
	this->playerAnime.AddCollision(colFileDir + "37.txt");
	this->playerAnime.AddCollision(colFileDir + "38.txt");
	this->playerAnime.AddCollision(colFileDir + "39.txt");
	this->playerAnime.AddCollision(colFileDir + "41.txt");
	this->playerAnime.AddCollision(colFileDir + "42.txt");
	this->playerAnime.AddCollision(colFileDir + "43.txt");
	this->playerAnime.AddCollision(colFileDir + "44.txt");
	this->playerAnime.AddCollision(colFileDir + "45.txt");
	this->playerAnime.AddCollision(colFileDir + "46.txt");
	this->playerAnime.AddCollision(colFileDir + "47.txt");
	this->playerAnime.AddCollision(colFileDir + "48.txt");
	this->playerAnime.AddCollision(colFileDir + "49.txt");
	this->playerAnime.AddCollision(colFileDir + "50.txt");
	this->playerAnime.AddCollision(colFileDir + "51.txt");
	this->playerAnime.AddCollision(colFileDir + "52.txt");
	this->playerAnime.AddCollision(colFileDir + "53.txt");
	this->playerAnime.AddCollision(colFileDir + "54.txt");
	this->playerAnime.AddCollision(colFileDir + "55.txt");
	this->playerAnime.AddCollision(colFileDir + "56.txt");
	this->playerAnime.AddCollision(colFileDir + "57.txt");
#pragma endregion


	this->playerState.ChangeState(CharacterNormalState::IDLE);
	this->transform.Translate(Vec2DF::Down() * 450,false, 1);
	this->transform.Translate(Vec2DF::Right() * 500,false, 1);
}

void SandBag::Update(float deltaTime)
{
	this->transform.Update(deltaTime);
	this->playerAnime.Update(deltaTime);
	this->playerState.Update(deltaTime);
}

void SandBag::Draw(PaintInfo info)
{
	this->playerAnime.GetCurrentImage().img.Draw(info.hdc, this->transform.Position.x, this->transform.Position.y);
	this->playerAnime.GetCurrentCollisionData().Draw(info, this->transform.Position + ImageMargin);
}
