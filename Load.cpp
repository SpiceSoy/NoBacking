#include "pch.h"
#include "CommonEffectFuctionSet.h"
#include "GameFramework.h"
#include "ResourceManager.h"
#include "Effect.h"
#include "SoundSystem.h"
void GameFramework::Load()
{
#pragma region Player
	const std::wstring C1Dir = L"Resources/character/c1/";
	const std::wstring C2Dir = L"Resources/character/c2/";
	const std::wstring C3Dir = L"Resources/character/c3/";
	const std::string ChaColDir = "Resources/character/col/";
#pragma region C1
	{
		// 기본
		ResourceManager::AddImages("character1", C1Dir + L"6.png");
		ResourceManager::AddImages("character1", C1Dir + L"7.png");
		ResourceManager::AddImages("character1", C1Dir + L"8.png");
		ResourceManager::AddImages("character1", C1Dir + L"9.png");
		ResourceManager::AddImages("character1", C1Dir + L"10.png");
		ResourceManager::AddImages("character1", C1Dir + L"11.png");
		// 걷기 역순
		ResourceManager::AddImages("character1", C1Dir + L"21.png");
		ResourceManager::AddImages("character1", C1Dir + L"20.png");
		ResourceManager::AddImages("character1", C1Dir + L"19.png");
		ResourceManager::AddImages("character1", C1Dir + L"18.png");
		ResourceManager::AddImages("character1", C1Dir + L"17.png");
		ResourceManager::AddImages("character1", C1Dir + L"16.png");
		ResourceManager::AddImages("character1", C1Dir + L"15.png");
		ResourceManager::AddImages("character1", C1Dir + L"14.png");
		ResourceManager::AddImages("character1", C1Dir + L"13.png");
		ResourceManager::AddImages("character1", C1Dir + L"12.png");
		// 달리기
		ResourceManager::AddImages("character1", C1Dir + L"22.png");
		ResourceManager::AddImages("character1", C1Dir + L"23.png");
		ResourceManager::AddImages("character1", C1Dir + L"24.png");
		ResourceManager::AddImages("character1", C1Dir + L"25.png");
		ResourceManager::AddImages("character1", C1Dir + L"26.png");
		ResourceManager::AddImages("character1", C1Dir + L"27.png");
		ResourceManager::AddImages("character1", C1Dir + L"28.png");
		ResourceManager::AddImages("character1", C1Dir + L"29.png");
		// 가드
		ResourceManager::AddImages("character1", C1Dir + L"84.png");
		ResourceManager::AddImages("character1", C1Dir + L"85.png");
		ResourceManager::AddImages("character1", C1Dir + L"86.png");
		ResourceManager::AddImages("character1", C1Dir + L"87.png");
		ResourceManager::AddImages("character1", C1Dir + L"88.png");
		ResourceManager::AddImages("character1", C1Dir + L"89.png");
		ResourceManager::AddImages("character1", C1Dir + L"90.png");
		// 찌르기
		ResourceManager::AddImages("character1", C1Dir + L"60.png");
		ResourceManager::AddImages("character1", C1Dir + L"61.png");
		ResourceManager::AddImages("character1", C1Dir + L"62.png");
		ResourceManager::AddImages("character1", C1Dir + L"63.png");
		ResourceManager::AddImages("character1", C1Dir + L"64.png");
		ResourceManager::AddImages("character1", C1Dir + L"65.png");
		//점프
		ResourceManager::AddImages("character1", C1Dir + L"30.png");
		ResourceManager::AddImages("character1", C1Dir + L"31.png");
		ResourceManager::AddImages("character1", C1Dir + L"32.png");
		//점프 중간
		ResourceManager::AddImages("character1", C1Dir + L"33.png");
		//착지
		ResourceManager::AddImages("character1", C1Dir + L"34.png");
		ResourceManager::AddImages("character1", C1Dir + L"35.png");
		//점프공격
		ResourceManager::AddImages("character1", C1Dir + L"43.png");
		ResourceManager::AddImages("character1", C1Dir + L"44.png");
		ResourceManager::AddImages("character1", C1Dir + L"45.png");
		ResourceManager::AddImages("character1", C1Dir + L"46.png");
		ResourceManager::AddImages("character1", C1Dir + L"47.png");
		ResourceManager::AddImages("character1", C1Dir + L"48.png");
		ResourceManager::AddImages("character1", C1Dir + L"49.png");
		ResourceManager::AddImages("character1", C1Dir + L"50.png");
		//베기
		ResourceManager::AddImages("character1", C1Dir + L"51.png");
		ResourceManager::AddImages("character1", C1Dir + L"52.png");
		ResourceManager::AddImages("character1", C1Dir + L"53.png");
		ResourceManager::AddImages("character1", C1Dir + L"54.png");
		ResourceManager::AddImages("character1", C1Dir + L"55.png");
		ResourceManager::AddImages("character1", C1Dir + L"56.png");
		ResourceManager::AddImages("character1", C1Dir + L"57.png");
		ResourceManager::AddImages("character1", C1Dir + L"58.png");
		ResourceManager::AddImages("character1", C1Dir + L"59.png");
		//점공 2
		ResourceManager::AddImages("character1", C1Dir + L"36.png");
		ResourceManager::AddImages("character1", C1Dir + L"37.png");
		ResourceManager::AddImages("character1", C1Dir + L"38.png");
		ResourceManager::AddImages("character1", C1Dir + L"39.png");
		ResourceManager::AddImages("character1", C1Dir + L"40.png");
		ResourceManager::AddImages("character1", C1Dir + L"41.png");
		ResourceManager::AddImages("character1", C1Dir + L"42.png");
		ResourceManager::AddImages("character1", C1Dir + L"43.png");
		ResourceManager::AddImages("character1", C1Dir + L"44.png");
		ResourceManager::AddImages("character1", C1Dir + L"45.png");
		ResourceManager::AddImages("character1", C1Dir + L"46.png");
		//가드 이동
		ResourceManager::AddImages("character1", C1Dir + L"91.png");
		ResourceManager::AddImages("character1", C1Dir + L"92.png");
		ResourceManager::AddImages("character1", C1Dir + L"93.png");
		ResourceManager::AddImages("character1", C1Dir + L"94.png");
		ResourceManager::AddImages("character1", C1Dir + L"95.png");
		ResourceManager::AddImages("character1", C1Dir + L"96.png");
		ResourceManager::AddImages("character1", C1Dir + L"97.png");
		ResourceManager::AddImages("character1", C1Dir + L"98.png");
		//피격
		ResourceManager::AddImages("character1", C1Dir + L"140.png");
		ResourceManager::AddImages("character1", C1Dir + L"141.png");
		//다운
		ResourceManager::AddImages("character1", C1Dir + L"142.png");
		ResourceManager::AddImages("character1", C1Dir + L"143.png");
		ResourceManager::AddImages("character1", C1Dir + L"144.png");
		//카운터
		ResourceManager::AddImages("character1", C1Dir + L"118.png");
		ResourceManager::AddImages("character1", C1Dir + L"119.png");
		ResourceManager::AddImages("character1", C1Dir + L"120.png");
		ResourceManager::AddImages("character1", C1Dir + L"121.png");
		ResourceManager::AddImages("character1", C1Dir + L"122.png");
		ResourceManager::AddImages("character1", C1Dir + L"123.png");
		ResourceManager::AddImages("character1", C1Dir + L"124.png");
		ResourceManager::AddImages("character1", C1Dir + L"125.png");
		ResourceManager::AddImages("character1", C1Dir + L"126.png");
	}
#pragma endregion
#pragma region C2
	{
		// 기본
		ResourceManager::AddImages("character2", C2Dir + L"6.png");
		ResourceManager::AddImages("character2", C2Dir + L"7.png");
		ResourceManager::AddImages("character2", C2Dir + L"8.png");
		ResourceManager::AddImages("character2", C2Dir + L"9.png");
		ResourceManager::AddImages("character2", C2Dir + L"10.png");
		ResourceManager::AddImages("character2", C2Dir + L"11.png");
		// 걷기 역순
		ResourceManager::AddImages("character2", C2Dir + L"21.png");
		ResourceManager::AddImages("character2", C2Dir + L"20.png");
		ResourceManager::AddImages("character2", C2Dir + L"19.png");
		ResourceManager::AddImages("character2", C2Dir + L"18.png");
		ResourceManager::AddImages("character2", C2Dir + L"17.png");
		ResourceManager::AddImages("character2", C2Dir + L"16.png");
		ResourceManager::AddImages("character2", C2Dir + L"15.png");
		ResourceManager::AddImages("character2", C2Dir + L"14.png");
		ResourceManager::AddImages("character2", C2Dir + L"13.png");
		ResourceManager::AddImages("character2", C2Dir + L"12.png");
		// 달리기
		ResourceManager::AddImages("character2", C2Dir + L"22.png");
		ResourceManager::AddImages("character2", C2Dir + L"23.png");
		ResourceManager::AddImages("character2", C2Dir + L"24.png");
		ResourceManager::AddImages("character2", C2Dir + L"25.png");
		ResourceManager::AddImages("character2", C2Dir + L"26.png");
		ResourceManager::AddImages("character2", C2Dir + L"27.png");
		ResourceManager::AddImages("character2", C2Dir + L"28.png");
		ResourceManager::AddImages("character2", C2Dir + L"29.png");
		// 가드
		ResourceManager::AddImages("character2", C2Dir + L"84.png");
		ResourceManager::AddImages("character2", C2Dir + L"85.png");
		ResourceManager::AddImages("character2", C2Dir + L"86.png");
		ResourceManager::AddImages("character2", C2Dir + L"87.png");
		ResourceManager::AddImages("character2", C2Dir + L"88.png");
		ResourceManager::AddImages("character2", C2Dir + L"89.png");
		ResourceManager::AddImages("character2", C2Dir + L"90.png");
		// 찌르기
		ResourceManager::AddImages("character2", C2Dir + L"60.png");
		ResourceManager::AddImages("character2", C2Dir + L"61.png");
		ResourceManager::AddImages("character2", C2Dir + L"62.png");
		ResourceManager::AddImages("character2", C2Dir + L"63.png");
		ResourceManager::AddImages("character2", C2Dir + L"64.png");
		ResourceManager::AddImages("character2", C2Dir + L"65.png");
		//점프
		ResourceManager::AddImages("character2", C2Dir + L"30.png");
		ResourceManager::AddImages("character2", C2Dir + L"31.png");
		ResourceManager::AddImages("character2", C2Dir + L"32.png");
		//점프 중간
		ResourceManager::AddImages("character2", C2Dir + L"33.png");
		//착지
		ResourceManager::AddImages("character2", C2Dir + L"34.png");
		ResourceManager::AddImages("character2", C2Dir + L"35.png");
		//점프공격
		ResourceManager::AddImages("character2", C2Dir + L"43.png");
		ResourceManager::AddImages("character2", C2Dir + L"44.png");
		ResourceManager::AddImages("character2", C2Dir + L"45.png");
		ResourceManager::AddImages("character2", C2Dir + L"46.png");
		ResourceManager::AddImages("character2", C2Dir + L"47.png");
		ResourceManager::AddImages("character2", C2Dir + L"48.png");
		ResourceManager::AddImages("character2", C2Dir + L"49.png");
		ResourceManager::AddImages("character2", C2Dir + L"50.png");
		//베기
		ResourceManager::AddImages("character2", C2Dir + L"51.png");
		ResourceManager::AddImages("character2", C2Dir + L"52.png");
		ResourceManager::AddImages("character2", C2Dir + L"53.png");
		ResourceManager::AddImages("character2", C2Dir + L"54.png");
		ResourceManager::AddImages("character2", C2Dir + L"55.png");
		ResourceManager::AddImages("character2", C2Dir + L"56.png");
		ResourceManager::AddImages("character2", C2Dir + L"57.png");
		ResourceManager::AddImages("character2", C2Dir + L"58.png");
		ResourceManager::AddImages("character2", C2Dir + L"59.png");
		//점공 2
		ResourceManager::AddImages("character2", C2Dir + L"36.png");
		ResourceManager::AddImages("character2", C2Dir + L"37.png");
		ResourceManager::AddImages("character2", C2Dir + L"38.png");
		ResourceManager::AddImages("character2", C2Dir + L"39.png");
		ResourceManager::AddImages("character2", C2Dir + L"40.png");
		ResourceManager::AddImages("character2", C2Dir + L"41.png");
		ResourceManager::AddImages("character2", C2Dir + L"42.png");
		ResourceManager::AddImages("character2", C2Dir + L"43.png");
		ResourceManager::AddImages("character2", C2Dir + L"44.png");
		ResourceManager::AddImages("character2", C2Dir + L"45.png");
		ResourceManager::AddImages("character2", C2Dir + L"46.png");
		//가드 이동
		ResourceManager::AddImages("character2", C2Dir + L"91.png");
		ResourceManager::AddImages("character2", C2Dir + L"92.png");
		ResourceManager::AddImages("character2", C2Dir + L"93.png");
		ResourceManager::AddImages("character2", C2Dir + L"94.png");
		ResourceManager::AddImages("character2", C2Dir + L"95.png");
		ResourceManager::AddImages("character2", C2Dir + L"96.png");
		ResourceManager::AddImages("character2", C2Dir + L"97.png");
		ResourceManager::AddImages("character2", C2Dir + L"98.png");
		//피격
		ResourceManager::AddImages("character2", C2Dir + L"140.png");
		ResourceManager::AddImages("character2", C2Dir + L"141.png");
		//다운
		ResourceManager::AddImages("character2", C2Dir + L"142.png");
		ResourceManager::AddImages("character2", C2Dir + L"143.png");
		ResourceManager::AddImages("character2", C2Dir + L"144.png");
		//카운터
		ResourceManager::AddImages("character2", C2Dir + L"118.png");
		ResourceManager::AddImages("character2", C2Dir + L"119.png");
		ResourceManager::AddImages("character2", C2Dir + L"120.png");
		ResourceManager::AddImages("character2", C2Dir + L"121.png");
		ResourceManager::AddImages("character2", C2Dir + L"122.png");
		ResourceManager::AddImages("character2", C2Dir + L"123.png");
		ResourceManager::AddImages("character2", C2Dir + L"124.png");
		ResourceManager::AddImages("character2", C2Dir + L"125.png");
		ResourceManager::AddImages("character2", C2Dir + L"126.png");
	}
#pragma endregion
#pragma region C3
	{
		// 기본
		ResourceManager::AddImages("character3", C3Dir + L"6.png");
		ResourceManager::AddImages("character3", C3Dir + L"7.png");
		ResourceManager::AddImages("character3", C3Dir + L"8.png");
		ResourceManager::AddImages("character3", C3Dir + L"9.png");
		ResourceManager::AddImages("character3", C3Dir + L"10.png");
		ResourceManager::AddImages("character3", C3Dir + L"11.png");
		// 걷기 역순
		ResourceManager::AddImages("character3", C3Dir + L"21.png");
		ResourceManager::AddImages("character3", C3Dir + L"20.png");
		ResourceManager::AddImages("character3", C3Dir + L"19.png");
		ResourceManager::AddImages("character3", C3Dir + L"18.png");
		ResourceManager::AddImages("character3", C3Dir + L"17.png");
		ResourceManager::AddImages("character3", C3Dir + L"16.png");
		ResourceManager::AddImages("character3", C3Dir + L"15.png");
		ResourceManager::AddImages("character3", C3Dir + L"14.png");
		ResourceManager::AddImages("character3", C3Dir + L"13.png");
		ResourceManager::AddImages("character3", C3Dir + L"12.png");
		// 달리기
		ResourceManager::AddImages("character3", C3Dir + L"22.png");
		ResourceManager::AddImages("character3", C3Dir + L"23.png");
		ResourceManager::AddImages("character3", C3Dir + L"24.png");
		ResourceManager::AddImages("character3", C3Dir + L"25.png");
		ResourceManager::AddImages("character3", C3Dir + L"26.png");
		ResourceManager::AddImages("character3", C3Dir + L"27.png");
		ResourceManager::AddImages("character3", C3Dir + L"28.png");
		ResourceManager::AddImages("character3", C3Dir + L"29.png");
		// 가드
		ResourceManager::AddImages("character3", C3Dir + L"84.png");
		ResourceManager::AddImages("character3", C3Dir + L"85.png");
		ResourceManager::AddImages("character3", C3Dir + L"86.png");
		ResourceManager::AddImages("character3", C3Dir + L"87.png");
		ResourceManager::AddImages("character3", C3Dir + L"88.png");
		ResourceManager::AddImages("character3", C3Dir + L"89.png");
		ResourceManager::AddImages("character3", C3Dir + L"90.png");
		// 찌르기
		ResourceManager::AddImages("character3", C3Dir + L"60.png");
		ResourceManager::AddImages("character3", C3Dir + L"61.png");
		ResourceManager::AddImages("character3", C3Dir + L"62.png");
		ResourceManager::AddImages("character3", C3Dir + L"63.png");
		ResourceManager::AddImages("character3", C3Dir + L"64.png");
		ResourceManager::AddImages("character3", C3Dir + L"65.png");
		//점프
		ResourceManager::AddImages("character3", C3Dir + L"30.png");
		ResourceManager::AddImages("character3", C3Dir + L"31.png");
		ResourceManager::AddImages("character3", C3Dir + L"32.png");
		//점프 중간
		ResourceManager::AddImages("character3", C3Dir + L"33.png");
		//착지
		ResourceManager::AddImages("character3", C3Dir + L"34.png");
		ResourceManager::AddImages("character3", C3Dir + L"35.png");
		//점프공격
		ResourceManager::AddImages("character3", C3Dir + L"43.png");
		ResourceManager::AddImages("character3", C3Dir + L"44.png");
		ResourceManager::AddImages("character3", C3Dir + L"45.png");
		ResourceManager::AddImages("character3", C3Dir + L"46.png");
		ResourceManager::AddImages("character3", C3Dir + L"47.png");
		ResourceManager::AddImages("character3", C3Dir + L"48.png");
		ResourceManager::AddImages("character3", C3Dir + L"49.png");
		ResourceManager::AddImages("character3", C3Dir + L"50.png");
		//베기
		ResourceManager::AddImages("character3", C3Dir + L"51.png");
		ResourceManager::AddImages("character3", C3Dir + L"52.png");
		ResourceManager::AddImages("character3", C3Dir + L"53.png");
		ResourceManager::AddImages("character3", C3Dir + L"54.png");
		ResourceManager::AddImages("character3", C3Dir + L"55.png");
		ResourceManager::AddImages("character3", C3Dir + L"56.png");
		ResourceManager::AddImages("character3", C3Dir + L"57.png");
		ResourceManager::AddImages("character3", C3Dir + L"58.png");
		ResourceManager::AddImages("character3", C3Dir + L"59.png");
		//점공 2
		ResourceManager::AddImages("character3", C3Dir + L"36.png");
		ResourceManager::AddImages("character3", C3Dir + L"37.png");
		ResourceManager::AddImages("character3", C3Dir + L"38.png");
		ResourceManager::AddImages("character3", C3Dir + L"39.png");
		ResourceManager::AddImages("character3", C3Dir + L"40.png");
		ResourceManager::AddImages("character3", C3Dir + L"41.png");
		ResourceManager::AddImages("character3", C3Dir + L"42.png");
		ResourceManager::AddImages("character3", C3Dir + L"43.png");
		ResourceManager::AddImages("character3", C3Dir + L"44.png");
		ResourceManager::AddImages("character3", C3Dir + L"45.png");
		ResourceManager::AddImages("character3", C3Dir + L"46.png");
		//가드 이동
		ResourceManager::AddImages("character3", C3Dir + L"91.png");
		ResourceManager::AddImages("character3", C3Dir + L"92.png");
		ResourceManager::AddImages("character3", C3Dir + L"93.png");
		ResourceManager::AddImages("character3", C3Dir + L"94.png");
		ResourceManager::AddImages("character3", C3Dir + L"95.png");
		ResourceManager::AddImages("character3", C3Dir + L"96.png");
		ResourceManager::AddImages("character3", C3Dir + L"97.png");
		ResourceManager::AddImages("character3", C3Dir + L"98.png");
		//피격
		ResourceManager::AddImages("character3", C3Dir + L"140.png");
		ResourceManager::AddImages("character3", C3Dir + L"141.png");
		//다운
		ResourceManager::AddImages("character3", C3Dir + L"142.png");
		ResourceManager::AddImages("character3", C3Dir + L"143.png");
		ResourceManager::AddImages("character3", C3Dir + L"144.png");
		//카운터
		ResourceManager::AddImages("character3", C3Dir + L"118.png");
		ResourceManager::AddImages("character3", C3Dir + L"119.png");
		ResourceManager::AddImages("character3", C3Dir + L"120.png");
		ResourceManager::AddImages("character3", C3Dir + L"121.png");
		ResourceManager::AddImages("character3", C3Dir + L"122.png");
		ResourceManager::AddImages("character3", C3Dir + L"123.png");
		ResourceManager::AddImages("character3", C3Dir + L"124.png");
		ResourceManager::AddImages("character3", C3Dir + L"125.png");
		ResourceManager::AddImages("character3", C3Dir + L"126.png");

	}
#pragma endregion
#pragma region Motion
	{
		//기본
		MotionContainer motionContainer;
		subAnimation subAnim;
		subAnim.next = CharacterNormalState::LOOP;
		subAnim.scale = 0.85;
		subAnim.subImageStartIndex = 0;
		subAnim.subImageSize = 6;
		motionContainer[CharacterNormalState::IDLE] = subAnim;
		//걷기
		subAnim.next = CharacterNormalState::LOOP;
		subAnim.scale = 0.75;
		subAnim.subImageStartIndex = 6;
		subAnim.subImageSize = 10;
		motionContainer[CharacterNormalState::MOTION1] = subAnim;
		//달리기
		subAnim.next = CharacterNormalState::LOOP;
		subAnim.scale = 0.75;
		subAnim.subImageStartIndex = 16;
		subAnim.subImageSize = 8;
		motionContainer[CharacterNormalState::MOTION2] = subAnim;
		//가드
		subAnim.next = CharacterNormalState::None;
		subAnim.subImageStartIndex = 24;
		subAnim.subImageSize = 7;
		motionContainer[CharacterNormalState::MOTION3] = subAnim;
		//찌르기
		subAnim.next = CharacterNormalState::None;
		subAnim.subImageStartIndex = 31;
		subAnim.scale = 0.70;
		subAnim.subImageSize = 6;
		motionContainer[CharacterNormalState::MOTION4] = subAnim;
		//점프
		subAnim.next = CharacterNormalState::None;
		subAnim.subImageStartIndex = 37;
		subAnim.scale = 1.0;
		subAnim.subImageSize = 3;
		motionContainer[CharacterNormalState::MOTION5] = subAnim;
		//점프 중간
		subAnim.next = CharacterNormalState::None;
		subAnim.subImageStartIndex = 40;
		subAnim.scale = 1.0;
		subAnim.subImageSize = 1;
		motionContainer[CharacterNormalState::MOTION6] = subAnim;
		//착지
		subAnim.next = CharacterNormalState::None;
		subAnim.subImageStartIndex = 41;
		subAnim.scale = 2.0;
		subAnim.subImageSize = 2;
		motionContainer[CharacterNormalState::MOTION7] = subAnim;
		//점프 공격
		subAnim.next = CharacterNormalState::None;
		subAnim.subImageStartIndex = 43;
		subAnim.scale = 1.0;
		subAnim.subImageSize = 8;
		motionContainer[CharacterNormalState::MOTION8] = subAnim;
		//베기
		subAnim.next = CharacterNormalState::None;
		subAnim.subImageStartIndex = 51;
		subAnim.scale = 1.15;
		subAnim.subImageSize = 9;
		motionContainer[CharacterNormalState::MOTION9] = subAnim;
		//점공2
		subAnim.next = CharacterNormalState::None;
		subAnim.subImageStartIndex = 60;
		subAnim.scale = 1.0;
		subAnim.subImageSize = 11;
		motionContainer[CharacterNormalState::MOTION10] = subAnim;
		//가드 이동
		subAnim.next = CharacterNormalState::LOOP;
		subAnim.subImageStartIndex = 71;
		subAnim.scale = 0.45;
		subAnim.subImageSize = 8;
		motionContainer[CharacterNormalState::MOTION11] = subAnim;
		//가드 중
		subAnim.next = CharacterNormalState::LOOP;
		subAnim.subImageStartIndex = 30;
		subAnim.scale = 1.0;
		subAnim.subImageSize = 1;
		motionContainer[CharacterNormalState::MOTION12] = subAnim;
		//피격
		subAnim.next = CharacterNormalState::None;
		subAnim.subImageStartIndex = 79;
		subAnim.scale = 0.5;
		subAnim.subImageSize = 2;
		motionContainer[CharacterNormalState::MOTION13] = subAnim;
		//다운
		subAnim.next = CharacterNormalState::None;
		subAnim.subImageStartIndex = 81;
		subAnim.scale = 0.5;
		subAnim.subImageSize = 3;
		motionContainer[CharacterNormalState::MOTION14] = subAnim;
		//카운터
		subAnim.next = CharacterNormalState::None;
		subAnim.subImageStartIndex = 84;
		subAnim.scale = 1.0;
		subAnim.subImageSize = 9;
		motionContainer[CharacterNormalState::MOTION15] = subAnim;
		ResourceManager::AddMotion("character", std::move(motionContainer));
	}
#pragma endregion
#pragma region Collision
	{
		// 기본
		ResourceManager::AddCollision("character", ChaColDir + "6.txt");
		ResourceManager::AddCollision("character", ChaColDir + "7.txt");
		ResourceManager::AddCollision("character", ChaColDir + "8.txt");
		ResourceManager::AddCollision("character", ChaColDir + "9.txt");
		ResourceManager::AddCollision("character", ChaColDir + "10.txt");
		ResourceManager::AddCollision("character", ChaColDir + "11.txt");
		// 걷기 역순
		ResourceManager::AddCollision("character", ChaColDir + "21.txt");
		ResourceManager::AddCollision("character", ChaColDir + "20.txt");
		ResourceManager::AddCollision("character", ChaColDir + "19.txt");
		ResourceManager::AddCollision("character", ChaColDir + "18.txt");
		ResourceManager::AddCollision("character", ChaColDir + "17.txt");
		ResourceManager::AddCollision("character", ChaColDir + "16.txt");
		ResourceManager::AddCollision("character", ChaColDir + "15.txt");
		ResourceManager::AddCollision("character", ChaColDir + "14.txt");
		ResourceManager::AddCollision("character", ChaColDir + "13.txt");
		ResourceManager::AddCollision("character", ChaColDir + "12.txt");
		// 달리기
		ResourceManager::AddCollision("character", ChaColDir + "22.txt");
		ResourceManager::AddCollision("character", ChaColDir + "23.txt");
		ResourceManager::AddCollision("character", ChaColDir + "24.txt");
		ResourceManager::AddCollision("character", ChaColDir + "25.txt");
		ResourceManager::AddCollision("character", ChaColDir + "26.txt");
		ResourceManager::AddCollision("character", ChaColDir + "27.txt");
		ResourceManager::AddCollision("character", ChaColDir + "28.txt");
		ResourceManager::AddCollision("character", ChaColDir + "29.txt");
		// 가드
		ResourceManager::AddCollision("character", ChaColDir + "84.txt");
		ResourceManager::AddCollision("character", ChaColDir + "85.txt");
		ResourceManager::AddCollision("character", ChaColDir + "86.txt");
		ResourceManager::AddCollision("character", ChaColDir + "87.txt");
		ResourceManager::AddCollision("character", ChaColDir + "88.txt");
		ResourceManager::AddCollision("character", ChaColDir + "89.txt");
		ResourceManager::AddCollision("character", ChaColDir + "90.txt");
		// 찌르기
		ResourceManager::AddCollision("character", ChaColDir + "60.txt");
		ResourceManager::AddCollision("character", ChaColDir + "61.txt");
		ResourceManager::AddCollision("character", ChaColDir + "62.txt");
		ResourceManager::AddCollision("character", ChaColDir + "63.txt");
		ResourceManager::AddCollision("character", ChaColDir + "64.txt");
		ResourceManager::AddCollision("character", ChaColDir + "65.txt");
		//점프
		ResourceManager::AddCollision("character", ChaColDir + "30.txt");
		ResourceManager::AddCollision("character", ChaColDir + "31.txt");
		ResourceManager::AddCollision("character", ChaColDir + "32.txt");
		//점프 중간
		ResourceManager::AddCollision("character", ChaColDir + "33.txt");
		//착지
		ResourceManager::AddCollision("character", ChaColDir + "34.txt");
		ResourceManager::AddCollision("character", ChaColDir + "35.txt");
		//점프공격
		ResourceManager::AddCollision("character", ChaColDir + "43.txt");
		ResourceManager::AddCollision("character", ChaColDir + "44.txt");
		ResourceManager::AddCollision("character", ChaColDir + "45.txt");
		ResourceManager::AddCollision("character", ChaColDir + "46.txt");
		ResourceManager::AddCollision("character", ChaColDir + "47.txt");
		ResourceManager::AddCollision("character", ChaColDir + "48.txt");
		ResourceManager::AddCollision("character", ChaColDir + "49.txt");
		ResourceManager::AddCollision("character", ChaColDir + "50.txt");
		//베기
		ResourceManager::AddCollision("character", ChaColDir + "51.txt");
		ResourceManager::AddCollision("character", ChaColDir + "52.txt");
		ResourceManager::AddCollision("character", ChaColDir + "53.txt");
		ResourceManager::AddCollision("character", ChaColDir + "54.txt");
		ResourceManager::AddCollision("character", ChaColDir + "55.txt");
		ResourceManager::AddCollision("character", ChaColDir + "56.txt");
		ResourceManager::AddCollision("character", ChaColDir + "57.txt");
		ResourceManager::AddCollision("character", ChaColDir + "58.txt");
		ResourceManager::AddCollision("character", ChaColDir + "59.txt");
		//점공 2
		ResourceManager::AddCollision("character", ChaColDir + "36.txt");
		ResourceManager::AddCollision("character", ChaColDir + "37.txt");
		ResourceManager::AddCollision("character", ChaColDir + "38.txt");
		ResourceManager::AddCollision("character", ChaColDir + "39.txt");
		ResourceManager::AddCollision("character", ChaColDir + "40.txt");
		ResourceManager::AddCollision("character", ChaColDir + "41.txt");
		ResourceManager::AddCollision("character", ChaColDir + "42.txt");
		ResourceManager::AddCollision("character", ChaColDir + "43.txt");
		ResourceManager::AddCollision("character", ChaColDir + "44.txt");
		ResourceManager::AddCollision("character", ChaColDir + "45.txt");
		ResourceManager::AddCollision("character", ChaColDir + "46.txt");
		//가드 이동
		ResourceManager::AddCollision("character", ChaColDir + "91.txt");
		ResourceManager::AddCollision("character", ChaColDir + "92.txt");
		ResourceManager::AddCollision("character", ChaColDir + "93.txt");
		ResourceManager::AddCollision("character", ChaColDir + "94.txt");
		ResourceManager::AddCollision("character", ChaColDir + "95.txt");
		ResourceManager::AddCollision("character", ChaColDir + "96.txt");
		ResourceManager::AddCollision("character", ChaColDir + "97.txt");
		ResourceManager::AddCollision("character", ChaColDir + "98.txt");
		//피격
		ResourceManager::AddCollision("character", ChaColDir + "140.txt");
		ResourceManager::AddCollision("character", ChaColDir + "141.txt");
		//다운
		ResourceManager::AddCollision("character", ChaColDir + "142.txt");
		ResourceManager::AddCollision("character", ChaColDir + "143.txt");
		ResourceManager::AddCollision("character", ChaColDir + "144.txt");
		//카운터
		ResourceManager::AddCollision("character", ChaColDir + "118.txt");
		ResourceManager::AddCollision("character", ChaColDir + "119.txt");
		ResourceManager::AddCollision("character", ChaColDir + "120.txt");
		ResourceManager::AddCollision("character", ChaColDir + "121.txt");
		ResourceManager::AddCollision("character", ChaColDir + "122.txt");
		ResourceManager::AddCollision("character", ChaColDir + "123.txt");
		ResourceManager::AddCollision("character", ChaColDir + "124.txt");
		ResourceManager::AddCollision("character", ChaColDir + "125.txt");
		ResourceManager::AddCollision("character", ChaColDir + "126.txt");
	}
#pragma endregion

#pragma endregion

#pragma region SandBag
	const std::wstring sandDir = L"Resources/sand/img/";
	const std::string sandColDir = "Resources/sand/col/";
	//이미지 정의
	{
		//일반 모션
		ResourceManager::AddImages("sandbag", sandDir + L"0.png");
		ResourceManager::AddImages("sandbag", sandDir + L"1.png");
		ResourceManager::AddImages("sandbag", sandDir + L"2.png");
		ResourceManager::AddImages("sandbag", sandDir + L"3.png");
		ResourceManager::AddImages("sandbag", sandDir + L"4.png");
		ResourceManager::AddImages("sandbag", sandDir + L"5.png");
		ResourceManager::AddImages("sandbag", sandDir + L"6.png");
		ResourceManager::AddImages("sandbag", sandDir + L"7.png");
		ResourceManager::AddImages("sandbag", sandDir + L"8.png");
		ResourceManager::AddImages("sandbag", sandDir + L"9.png");
		ResourceManager::AddImages("sandbag", sandDir + L"10.png");
		ResourceManager::AddImages("sandbag", sandDir + L"11.png");
		ResourceManager::AddImages("sandbag", sandDir + L"12.png");
		ResourceManager::AddImages("sandbag", sandDir + L"13.png");
		ResourceManager::AddImages("sandbag", sandDir + L"14.png");
		ResourceManager::AddImages("sandbag", sandDir + L"15.png");
		ResourceManager::AddImages("sandbag", sandDir + L"16.png");
		ResourceManager::AddImages("sandbag", sandDir + L"17.png");
		//피격 1
		ResourceManager::AddImages("sandbag", sandDir + L"18.png");
		ResourceManager::AddImages("sandbag", sandDir + L"19.png");
		ResourceManager::AddImages("sandbag", sandDir + L"20.png");
		ResourceManager::AddImages("sandbag", sandDir + L"21.png");
		ResourceManager::AddImages("sandbag", sandDir + L"22.png");
		ResourceManager::AddImages("sandbag", sandDir + L"23.png");
		ResourceManager::AddImages("sandbag", sandDir + L"24.png");
		ResourceManager::AddImages("sandbag", sandDir + L"25.png");
		ResourceManager::AddImages("sandbag", sandDir + L"26.png");
		ResourceManager::AddImages("sandbag", sandDir + L"27.png");
		ResourceManager::AddImages("sandbag", sandDir + L"28.png");
		ResourceManager::AddImages("sandbag", sandDir + L"29.png");
		ResourceManager::AddImages("sandbag", sandDir + L"30.png");
		ResourceManager::AddImages("sandbag", sandDir + L"31.png");
		//피격 2
		ResourceManager::AddImages("sandbag", sandDir + L"32.png");
		ResourceManager::AddImages("sandbag", sandDir + L"33.png");
		ResourceManager::AddImages("sandbag", sandDir + L"34.png");
		ResourceManager::AddImages("sandbag", sandDir + L"35.png");
		ResourceManager::AddImages("sandbag", sandDir + L"36.png");
		ResourceManager::AddImages("sandbag", sandDir + L"37.png");
		ResourceManager::AddImages("sandbag", sandDir + L"38.png");
		ResourceManager::AddImages("sandbag", sandDir + L"39.png");
		ResourceManager::AddImages("sandbag", sandDir + L"40.png");
		ResourceManager::AddImages("sandbag", sandDir + L"41.png");
		ResourceManager::AddImages("sandbag", sandDir + L"42.png");
		ResourceManager::AddImages("sandbag", sandDir + L"43.png");
		ResourceManager::AddImages("sandbag", sandDir + L"44.png");
		ResourceManager::AddImages("sandbag", sandDir + L"45.png");
		//사망
		ResourceManager::AddImages("sandbag", sandDir + L"46.png");
		ResourceManager::AddImages("sandbag", sandDir + L"47.png");
		ResourceManager::AddImages("sandbag", sandDir + L"48.png");
		ResourceManager::AddImages("sandbag", sandDir + L"49.png");
		ResourceManager::AddImages("sandbag", sandDir + L"50.png");
		ResourceManager::AddImages("sandbag", sandDir + L"51.png");
		ResourceManager::AddImages("sandbag", sandDir + L"52.png");
		ResourceManager::AddImages("sandbag", sandDir + L"53.png");
		ResourceManager::AddImages("sandbag", sandDir + L"54.png");
		ResourceManager::AddImages("sandbag", sandDir + L"55.png");
		ResourceManager::AddImages("sandbag", sandDir + L"56.png");
	}
	//모션 정의
	{
		MotionContainer motionContainer;
		//일반 모션
		subAnimation subAnim;
		subAnim.next = CharacterNormalState::LOOP;
		subAnim.scale = 0.85;
		subAnim.subImageStartIndex = 0;
		subAnim.subImageSize = 18;
		motionContainer[CharacterNormalState::IDLE] = subAnim;
		//피격 1
		subAnim.next = CharacterNormalState::None;
		subAnim.scale = 1.6;
		subAnim.subImageStartIndex = 18;
		subAnim.subImageSize = 8;
		//subAnim.subImageSize = 14;
		motionContainer[CharacterNormalState::MOTION1] = subAnim;
		//피격 2
		subAnim.next = CharacterNormalState::None;
		subAnim.scale = 1.25;
		subAnim.subImageStartIndex = 32;
		subAnim.subImageSize = 8;
		//subAnim.subImageSize = 14;
		motionContainer[CharacterNormalState::MOTION2] = subAnim;
		//사망
		subAnim.next = CharacterNormalState::None;
		subAnim.scale = 0.85;
		subAnim.subImageStartIndex = 46;
		subAnim.subImageSize = 11;
		motionContainer[CharacterNormalState::MOTION3] = subAnim;
		ResourceManager::AddMotion("sandbag", std::move(motionContainer));
	}
	
	//물리 정의
	{
		//일반 모션
		ResourceManager::AddCollision("sandbag", sandColDir + "0.txt");
		ResourceManager::AddCollision("sandbag", sandColDir + "1.txt");
		ResourceManager::AddCollision("sandbag", sandColDir + "2.txt");
		ResourceManager::AddCollision("sandbag", sandColDir + "3.txt");
		ResourceManager::AddCollision("sandbag", sandColDir + "4.txt");
		ResourceManager::AddCollision("sandbag", sandColDir + "5.txt");
		ResourceManager::AddCollision("sandbag", sandColDir + "6.txt");
		ResourceManager::AddCollision("sandbag", sandColDir + "7.txt");
		ResourceManager::AddCollision("sandbag", sandColDir + "8.txt");
		ResourceManager::AddCollision("sandbag", sandColDir + "9.txt");
		ResourceManager::AddCollision("sandbag", sandColDir + "10.txt");
		ResourceManager::AddCollision("sandbag", sandColDir + "11.txt");
		ResourceManager::AddCollision("sandbag", sandColDir + "12.txt");
		ResourceManager::AddCollision("sandbag", sandColDir + "13.txt");
		ResourceManager::AddCollision("sandbag", sandColDir + "14.txt");
		ResourceManager::AddCollision("sandbag", sandColDir + "15.txt");
		ResourceManager::AddCollision("sandbag", sandColDir + "16.txt");
		ResourceManager::AddCollision("sandbag", sandColDir + "17.txt");
		//피격 1
		ResourceManager::AddCollision("sandbag", sandColDir + "18.txt");
		ResourceManager::AddCollision("sandbag", sandColDir + "19.txt");
		ResourceManager::AddCollision("sandbag", sandColDir + "20.txt");
		ResourceManager::AddCollision("sandbag", sandColDir + "21.txt");
		ResourceManager::AddCollision("sandbag", sandColDir + "22.txt");
		ResourceManager::AddCollision("sandbag", sandColDir + "23.txt");
		ResourceManager::AddCollision("sandbag", sandColDir + "24.txt");
		ResourceManager::AddCollision("sandbag", sandColDir + "25.txt");
		ResourceManager::AddCollision("sandbag", sandColDir + "26.txt");
		ResourceManager::AddCollision("sandbag", sandColDir + "27.txt");
		ResourceManager::AddCollision("sandbag", sandColDir + "28.txt");
		ResourceManager::AddCollision("sandbag", sandColDir + "29.txt");
		ResourceManager::AddCollision("sandbag", sandColDir + "30.txt");
		ResourceManager::AddCollision("sandbag", sandColDir + "31.txt");
		//피격 2
		ResourceManager::AddCollision("sandbag", sandColDir + "32.txt");
		ResourceManager::AddCollision("sandbag", sandColDir + "33.txt");
		ResourceManager::AddCollision("sandbag", sandColDir + "34.txt");
		ResourceManager::AddCollision("sandbag", sandColDir + "35.txt");
		ResourceManager::AddCollision("sandbag", sandColDir + "36.txt");
		ResourceManager::AddCollision("sandbag", sandColDir + "37.txt");
		ResourceManager::AddCollision("sandbag", sandColDir + "38.txt");
		ResourceManager::AddCollision("sandbag", sandColDir + "39.txt");
		ResourceManager::AddCollision("sandbag", sandColDir + "40.txt");
		ResourceManager::AddCollision("sandbag", sandColDir + "41.txt");
		ResourceManager::AddCollision("sandbag", sandColDir + "42.txt");
		ResourceManager::AddCollision("sandbag", sandColDir + "43.txt");
		ResourceManager::AddCollision("sandbag", sandColDir + "44.txt");
		ResourceManager::AddCollision("sandbag", sandColDir + "45.txt");
		//사망
		ResourceManager::AddCollision("sandbag", sandColDir + "46.txt");
		ResourceManager::AddCollision("sandbag", sandColDir + "47.txt");
		ResourceManager::AddCollision("sandbag", sandColDir + "48.txt");
		ResourceManager::AddCollision("sandbag", sandColDir + "49.txt");
		ResourceManager::AddCollision("sandbag", sandColDir + "50.txt");
		ResourceManager::AddCollision("sandbag", sandColDir + "51.txt");
		ResourceManager::AddCollision("sandbag", sandColDir + "52.txt");
		ResourceManager::AddCollision("sandbag", sandColDir + "53.txt");
		ResourceManager::AddCollision("sandbag", sandColDir + "54.txt");
		ResourceManager::AddCollision("sandbag", sandColDir + "55.txt");
		ResourceManager::AddCollision("sandbag", sandColDir + "56.txt");
	}
#pragma endregion

#pragma region Guarder
	const std::wstring guarderDir = L"Resources/guarder/img/";
	const std::string guarderColDir = "Resources/guarder/col/";
	//이미지 정의
	{
		ResourceManager::AddImages("guarder", guarderDir + L"0.png");
		ResourceManager::AddImages("guarder", guarderDir + L"1.png");
		ResourceManager::AddImages("guarder", guarderDir + L"2.png");
		ResourceManager::AddImages("guarder", guarderDir + L"3.png");
		ResourceManager::AddImages("guarder", guarderDir + L"4.png");
		ResourceManager::AddImages("guarder", guarderDir + L"5.png");
		ResourceManager::AddImages("guarder", guarderDir + L"6.png");
		ResourceManager::AddImages("guarder", guarderDir + L"7.png");
		ResourceManager::AddImages("guarder", guarderDir + L"8.png");
		ResourceManager::AddImages("guarder", guarderDir + L"9.png");
		ResourceManager::AddImages("guarder", guarderDir + L"10.png");
		ResourceManager::AddImages("guarder", guarderDir + L"11.png");
		ResourceManager::AddImages("guarder", guarderDir + L"12.png");
		ResourceManager::AddImages("guarder", guarderDir + L"13.png");
		ResourceManager::AddImages("guarder", guarderDir + L"14.png");
		ResourceManager::AddImages("guarder", guarderDir + L"15.png");
		ResourceManager::AddImages("guarder", guarderDir + L"16.png");
		ResourceManager::AddImages("guarder", guarderDir + L"17.png");
		ResourceManager::AddImages("guarder", guarderDir + L"18.png");
		ResourceManager::AddImages("guarder", guarderDir + L"19.png");
		ResourceManager::AddImages("guarder", guarderDir + L"20.png");
		ResourceManager::AddImages("guarder", guarderDir + L"21.png");
		ResourceManager::AddImages("guarder", guarderDir + L"22.png");
		ResourceManager::AddImages("guarder", guarderDir + L"23.png");
		ResourceManager::AddImages("guarder", guarderDir + L"24.png");
	}
	//모션 정의
	{
		MotionContainer motionContainer;
		subAnimation subAnim;
		//대기
		subAnim.next = CharacterNormalState::LOOP;
		subAnim.scale = 0.1;
		subAnim.subImageStartIndex = 23;
		subAnim.subImageSize = 2;
		motionContainer[CharacterNormalState::IDLE] = subAnim;
		subAnim.next = CharacterNormalState::None;
		motionContainer[CharacterNormalState::MOTION6] = subAnim;
		//이동
		subAnim.next = CharacterNormalState::None;
		subAnim.scale = 1;
		subAnim.subImageStartIndex = 0;
		subAnim.subImageSize = 6;
		motionContainer[CharacterNormalState::MOTION1] = subAnim;
		//공격1
		subAnim.next = CharacterNormalState::None;
		subAnim.scale = 0.8;
		subAnim.subImageStartIndex = 6;
		subAnim.subImageSize = 5;
		motionContainer[CharacterNormalState::MOTION2] = subAnim;
		//공격2
		subAnim.next = CharacterNormalState::None;
		subAnim.scale = 0.8;
		subAnim.subImageStartIndex = 11;
		subAnim.subImageSize = 6;
		motionContainer[CharacterNormalState::MOTION3] = subAnim;
		//피격
		subAnim.next = CharacterNormalState::None;
		subAnim.scale = 0.25;
		subAnim.subImageStartIndex = 17;
		subAnim.subImageSize = 2;
		motionContainer[CharacterNormalState::MOTION4] = subAnim;
		//사망
		subAnim.next = CharacterNormalState::None;
		subAnim.scale = 1;
		subAnim.subImageStartIndex = 19;
		subAnim.subImageSize = 4;
		motionContainer[CharacterNormalState::MOTION5] = subAnim;
		//가드
		ResourceManager::AddMotion("guarder", std::move(motionContainer));
	}

	//물리 정의
	{
		//이동
		ResourceManager::AddCollision("guarder", guarderColDir + "0.txt");
		ResourceManager::AddCollision("guarder", guarderColDir + "1.txt");
		ResourceManager::AddCollision("guarder", guarderColDir + "2.txt");
		ResourceManager::AddCollision("guarder", guarderColDir + "3.txt");
		ResourceManager::AddCollision("guarder", guarderColDir + "4.txt");
		ResourceManager::AddCollision("guarder", guarderColDir + "5.txt");
		//공격1
		ResourceManager::AddCollision("guarder", guarderColDir + "6.txt");
		ResourceManager::AddCollision("guarder", guarderColDir + "7.txt");
		ResourceManager::AddCollision("guarder", guarderColDir + "8.txt");
		ResourceManager::AddCollision("guarder", guarderColDir + "9.txt");
		ResourceManager::AddCollision("guarder", guarderColDir + "10.txt");
		//공격2
		ResourceManager::AddCollision("guarder", guarderColDir + "11.txt");
		ResourceManager::AddCollision("guarder", guarderColDir + "12.txt");
		ResourceManager::AddCollision("guarder", guarderColDir + "13.txt");
		ResourceManager::AddCollision("guarder", guarderColDir + "14.txt");
		ResourceManager::AddCollision("guarder", guarderColDir + "15.txt");
		ResourceManager::AddCollision("guarder", guarderColDir + "16.txt");
		//피격 1
		ResourceManager::AddCollision("guarder", guarderColDir + "17.txt");
		ResourceManager::AddCollision("guarder", guarderColDir + "18.txt");
		//사망
		ResourceManager::AddCollision("guarder", guarderColDir + "19.txt");
		ResourceManager::AddCollision("guarder", guarderColDir + "20.txt");
		ResourceManager::AddCollision("guarder", guarderColDir + "21.txt");
		ResourceManager::AddCollision("guarder", guarderColDir + "22.txt");
		//가드
		ResourceManager::AddCollision("guarder", guarderColDir + "23.txt");
		ResourceManager::AddCollision("guarder", guarderColDir + "24.txt");
	}
#pragma endregion

#pragma region Archer
	const std::wstring archerDir = L"Resources/archer/img/";
	const std::string archerColDir = "Resources/archer/col/";
	//이미지 정의
	{
		ResourceManager::AddImages("archer", archerDir + L"0.png");
		ResourceManager::AddImages("archer", archerDir + L"1.png");
		ResourceManager::AddImages("archer", archerDir + L"2.png");
		ResourceManager::AddImages("archer", archerDir + L"3.png");
		ResourceManager::AddImages("archer", archerDir + L"4.png");
		ResourceManager::AddImages("archer", archerDir + L"5.png");
		ResourceManager::AddImages("archer", archerDir + L"13.png");
		ResourceManager::AddImages("archer", archerDir + L"12.png");
		ResourceManager::AddImages("archer", archerDir + L"11.png");
		ResourceManager::AddImages("archer", archerDir + L"10.png");
		ResourceManager::AddImages("archer", archerDir + L"9.png");
		ResourceManager::AddImages("archer", archerDir + L"8.png");
		ResourceManager::AddImages("archer", archerDir + L"7.png");
		ResourceManager::AddImages("archer", archerDir + L"6.png");
		ResourceManager::AddImages("archer", archerDir + L"14.png");
		ResourceManager::AddImages("archer", archerDir + L"15.png");
		ResourceManager::AddImages("archer", archerDir + L"16.png");
		ResourceManager::AddImages("archer", archerDir + L"17.png");
		ResourceManager::AddImages("archer", archerDir + L"18.png");
		ResourceManager::AddImages("archer", archerDir + L"19.png");
		ResourceManager::AddImages("archer", archerDir + L"20.png");
		ResourceManager::AddImages("archer", archerDir + L"21.png");
		ResourceManager::AddImages("archer", archerDir + L"22.png");
		ResourceManager::AddImages("archer", archerDir + L"23.png");
		ResourceManager::AddImages("archer", archerDir + L"24.png");
		ResourceManager::AddImages("archer", archerDir + L"25.png");
		ResourceManager::AddImages("archer", archerDir + L"26.png");
		ResourceManager::AddImages("archer", archerDir + L"27.png");
		ResourceManager::AddImages("archer", archerDir + L"28.png");
		ResourceManager::AddImages("archer", archerDir + L"29.png");
		ResourceManager::AddImages("archer", archerDir + L"30.png");
		ResourceManager::AddImages("archer", archerDir + L"31.png");
		ResourceManager::AddImages("archer", archerDir + L"32.png");
		ResourceManager::AddImages("archer", archerDir + L"33.png");
		ResourceManager::AddImages("archer", archerDir + L"34.png");
		ResourceManager::AddImages("archer", archerDir + L"35.png");
		ResourceManager::AddImages("archer", archerDir + L"36.png");
		ResourceManager::AddImages("archer", archerDir + L"37.png");
		ResourceManager::AddImages("archer", archerDir + L"38.png");
		ResourceManager::AddImages("archer", archerDir + L"39.png");

	}
	//모션 정의
	{
		MotionContainer motionContainer;
		subAnimation subAnim;
		//대기
		subAnim.next = CharacterNormalState::LOOP;
		subAnim.scale = 1;
		subAnim.subImageStartIndex = 0;
		subAnim.subImageSize = 6;
		motionContainer[CharacterNormalState::IDLE] = subAnim;
		//이동
		subAnim.next = CharacterNormalState::None;
		subAnim.scale = 1;
		subAnim.subImageStartIndex = 6;
		subAnim.subImageSize = 8;
		motionContainer[CharacterNormalState::MOTION1] = subAnim;
		//피격
		subAnim.next = CharacterNormalState::None;
		subAnim.scale = 0.25;
		subAnim.subImageStartIndex = 14;
		subAnim.subImageSize = 2;
		motionContainer[CharacterNormalState::MOTION2] = subAnim;
		//다운
		subAnim.next = CharacterNormalState::None;
		subAnim.scale = 1;
		subAnim.subImageStartIndex = 16;
		subAnim.subImageSize = 6;
		motionContainer[CharacterNormalState::MOTION3] = subAnim;
		//공격1(원거리)
		subAnim.next = CharacterNormalState::None;
		subAnim.scale = 0.5;
		subAnim.subImageStartIndex = 22;
		subAnim.subImageSize = 11;
		motionContainer[CharacterNormalState::MOTION4] = subAnim;
		//공격2(근거리)
		subAnim.next = CharacterNormalState::None;
		subAnim.scale = 1;
		subAnim.subImageStartIndex = 33;
		subAnim.subImageSize = 7;
		motionContainer[CharacterNormalState::MOTION5] = subAnim;
		ResourceManager::AddMotion("archer", std::move(motionContainer));
	}

	//물리 정의
	{
		// 대기
		ResourceManager::AddCollision("archer", archerColDir + "0.txt");
		ResourceManager::AddCollision("archer", archerColDir + "1.txt");
		ResourceManager::AddCollision("archer", archerColDir + "2.txt");
		ResourceManager::AddCollision("archer", archerColDir + "3.txt");
		ResourceManager::AddCollision("archer", archerColDir + "4.txt");
		ResourceManager::AddCollision("archer", archerColDir + "5.txt");
		//이동
		ResourceManager::AddCollision("archer", archerColDir + "13.txt");
		ResourceManager::AddCollision("archer", archerColDir + "12.txt");
		ResourceManager::AddCollision("archer", archerColDir + "11.txt");
		ResourceManager::AddCollision("archer", archerColDir + "10.txt");
		ResourceManager::AddCollision("archer", archerColDir + "9.txt");
		ResourceManager::AddCollision("archer", archerColDir + "8.txt");
		ResourceManager::AddCollision("archer", archerColDir + "7.txt");
		ResourceManager::AddCollision("archer", archerColDir + "6.txt");
		// 피격
		ResourceManager::AddCollision("archer", archerColDir + "14.txt");
		ResourceManager::AddCollision("archer", archerColDir + "15.txt");
		// 다운
		ResourceManager::AddCollision("archer", archerColDir + "16.txt");
		ResourceManager::AddCollision("archer", archerColDir + "17.txt");
		ResourceManager::AddCollision("archer", archerColDir + "18.txt");
		ResourceManager::AddCollision("archer", archerColDir + "19.txt");
		ResourceManager::AddCollision("archer", archerColDir + "20.txt");
		ResourceManager::AddCollision("archer", archerColDir + "21.txt");
		// 공격1(원거리)
		ResourceManager::AddCollision("archer", archerColDir + "22.txt");
		ResourceManager::AddCollision("archer", archerColDir + "23.txt");
		ResourceManager::AddCollision("archer", archerColDir + "24.txt");
		ResourceManager::AddCollision("archer", archerColDir + "25.txt");
		ResourceManager::AddCollision("archer", archerColDir + "26.txt");
		ResourceManager::AddCollision("archer", archerColDir + "27.txt");
		ResourceManager::AddCollision("archer", archerColDir + "28.txt");
		ResourceManager::AddCollision("archer", archerColDir + "29.txt");
		ResourceManager::AddCollision("archer", archerColDir + "30.txt");
		ResourceManager::AddCollision("archer", archerColDir + "31.txt");
		ResourceManager::AddCollision("archer", archerColDir + "32.txt");
		// 공격2(근거리)
		ResourceManager::AddCollision("archer", archerColDir + "33.txt");
		ResourceManager::AddCollision("archer", archerColDir + "34.txt");
		ResourceManager::AddCollision("archer", archerColDir + "35.txt");
		ResourceManager::AddCollision("archer", archerColDir + "36.txt");
		ResourceManager::AddCollision("archer", archerColDir + "37.txt");
		ResourceManager::AddCollision("archer", archerColDir + "38.txt");
		ResourceManager::AddCollision("archer", archerColDir + "39.txt");
	}
#pragma endregion

#pragma region Effects
	{
		const std::wstring effect1Dir = L"Resources/effect/effect1_1/img/";
		const std::string effect1ColDir = "Resources/effect1/effect1_1/col/";

		//이미지 정의
		{

			ResourceManager::AddImages("effect1", effect1Dir + L"0.png");
			ResourceManager::AddImages("effect1", effect1Dir + L"1.png");
			ResourceManager::AddImages("effect1", effect1Dir + L"2.png");
			ResourceManager::AddImages("effect1", effect1Dir + L"3.png");
			ResourceManager::AddImages("effect1", effect1Dir + L"4.png");
			ResourceManager::AddImages("effect1", effect1Dir + L"5.png");

			MotionContainer motionContainer;
			subAnimation subAnim;
			subAnim.next = CharacterNormalState::None;
			subAnim.scale = 1;
			subAnim.subImageStartIndex = 0;
			subAnim.subImageSize = 6;
			motionContainer[CharacterNormalState::IDLE] = subAnim;
			ResourceManager::AddMotion("effect1", std::move(motionContainer));
		
			subEffect subEffect;
			subEffect.ImageTag = "effect1";
			subEffect.MotionTag = "effect1";
			subEffect.CollisionTag = "effect1";
			subEffect.ImageMargin = Vec2DF{ 165,120 };
			subEffect.func = CommonEffectFunctionSet::GetOnceAnimeSet();
			Effect::AddEffect("effect1", std::move(subEffect));
		}
	}
	//실드 히트
	{
		const std::wstring shieldDir = L"Resources/effect/shield/";
		const std::string shieldColDir = "Resources/effect1/shield/col/";
		ResourceManager::AddImages("shield", shieldDir + L"0.png");
		ResourceManager::AddImages("shield", shieldDir + L"1.png");
		ResourceManager::AddImages("shield", shieldDir + L"2.png");
		ResourceManager::AddImages("shield", shieldDir + L"3.png");
		ResourceManager::AddImages("shield", shieldDir + L"4.png");
		MotionContainer motionContainer;

		subAnimation subAnim;
		subAnim.next = CharacterNormalState::None;
		subAnim.scale = 1;
		subAnim.subImageStartIndex = 0;
		subAnim.subImageSize = 5;
		motionContainer[CharacterNormalState::IDLE] = subAnim;
		ResourceManager::AddMotion("shield", std::move(motionContainer));

		subEffect subEffect;
		subEffect.ImageTag = "shield";
		subEffect.MotionTag = "shield";
		subEffect.CollisionTag = "shield";
		subEffect.ImageMargin = Vec2DF{ 63,98 };
		subEffect.func = CommonEffectFunctionSet::GetOnceAnimeSet();
		Effect::AddEffect("shield", std::move(subEffect));
	}
	//퍼펙트 실드 히트
	{
		const std::wstring shieldDir = L"Resources/effect/perfect/";
		const std::string shieldColDir = "Resources/effect1/perfect/col/";
		ResourceManager::AddImages("perfect", shieldDir + L"0.png");
		ResourceManager::AddImages("perfect", shieldDir + L"1.png");
		ResourceManager::AddImages("perfect", shieldDir + L"2.png");
		ResourceManager::AddImages("perfect", shieldDir + L"3.png");
		ResourceManager::AddImages("perfect", shieldDir + L"4.png");
		ResourceManager::AddImages("perfect", shieldDir + L"5.png");
		ResourceManager::AddImages("perfect", shieldDir + L"6.png");
		MotionContainer motionContainer;

		subAnimation subAnim;
		subAnim.next = CharacterNormalState::None;
		subAnim.scale = 1;
		subAnim.subImageStartIndex = 0;
		subAnim.subImageSize = 7;
		motionContainer[CharacterNormalState::IDLE] = subAnim;
		ResourceManager::AddMotion("perfect", std::move(motionContainer));

		subEffect subEffect;
		subEffect.ImageTag = "perfect";
		subEffect.MotionTag = "perfect";
		subEffect.CollisionTag = "perfect";
		subEffect.ImageMargin = Vec2DF{ 131,125 };
		subEffect.func = CommonEffectFunctionSet::GetOnceAnimeSet();
		Effect::AddEffect("perfect", std::move(subEffect));
	}
#pragma endregion

#pragma region BackGround

#pragma region Drago

	{
		const std::wstring bgDragoDir = L"Resources/back/bg_drago/back/";
		const std::wstring midDragoDir = L"Resources/back/bg_drago/mid/";
		const std::wstring tileDragoDir = L"Resources/back/bg_drago/tile/";
		//이미지 정의
		{
			//일반 모션
			ResourceManager::AddImages("bg-drago-back", bgDragoDir + L"0.png");
			ResourceManager::AddImages("bg-drago-mid", midDragoDir + L"0.png");
			ResourceManager::AddImages("bg-drago-mid", midDragoDir + L"1.png");
			ResourceManager::AddImages("bg-drago-tile", tileDragoDir + L"0.png");
			ResourceManager::AddImages("bg-drago-tile", tileDragoDir + L"1.png");
			ResourceManager::AddImages("bg-drago-tile", tileDragoDir + L"2.png");
			ResourceManager::AddImages("bg-drago-tile", tileDragoDir + L"3.png");
			ResourceManager::AddImages("bg-drago-tile", tileDragoDir + L"4.png");
			ResourceManager::AddImages("bg-drago-tile", tileDragoDir + L"5.png");
		}
	}

	{
		const std::wstring bgDragoDir = L"Resources/back/bg_drago_n/back/";
		const std::wstring midDragoDir = L"Resources/back/bg_drago_n/mid/";
		const std::wstring tileDragoDir = L"Resources/back/bg_drago_n/tile/";
		const std::wstring lowDragoDir = L"Resources/back/bg_drago_n/low/";
		//이미지 정의
		{
			//일반 모션
			ResourceManager::AddImages("bg-drago-n-back", bgDragoDir + L"0.png");
			ResourceManager::AddImages("bg-drago-n-mid", midDragoDir + L"0.png");
			ResourceManager::AddImages("bg-drago-n-mid", midDragoDir + L"1.png");
			ResourceManager::AddImages("bg-drago-n-tile", tileDragoDir + L"0.png");
			ResourceManager::AddImages("bg-drago-n-tile", tileDragoDir + L"1.png");
			ResourceManager::AddImages("bg-drago-n-tile", tileDragoDir + L"2.png");
			ResourceManager::AddImages("bg-drago-n-tile", tileDragoDir + L"3.png");
			ResourceManager::AddImages("bg-drago-n-tile", tileDragoDir + L"4.png");
			ResourceManager::AddImages("bg-drago-n-tile", tileDragoDir + L"5.png");
			ResourceManager::AddImages("bg-drago-n-low", tileDragoDir + L"0.png");
		}
	}

#pragma endregion

#pragma endregion

#pragma region UIIMage
	{
		const std::wstring playerHpDir = L"Resources/ui/hpbar/";
		ResourceManager::AddImages("ui-playerhpbar", playerHpDir + L"0.png");
		ResourceManager::AddImages("ui-playerhpbar", playerHpDir + L"1.png");
		ResourceManager::AddImages("ui-playerhpbar", playerHpDir + L"2.png");
	}
#pragma endregion



#pragma region Sound
	const std::string sndAttackDir = "Resources/sound/attack/";
	const std::string sndHitDir = "Resources/sound/hit/";
	const std::string bgmDir = "Resources/sound/bgm/";
	//SoundSystem::Load("zero", bgmDir + "zero.mp3");
	SoundSystem::Load("atk-slash", sndAttackDir + "blunt_01.wav");
	SoundSystem::Load("hit-bite", sndHitDir + "bite.wav");
	SoundSystem::Load("hit-steel", sndHitDir + "steel.wav");
	SoundSystem::Load("hit-cut", sndHitDir + "cut.wav");
#pragma endregion



}