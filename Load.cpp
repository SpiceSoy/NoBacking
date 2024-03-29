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
		// 스킬1
		ResourceManager::AddImages("character1", C1Dir + L"74.png");
		ResourceManager::AddImages("character1", C1Dir + L"75.png");
		ResourceManager::AddImages("character1", C1Dir + L"76.png");
		ResourceManager::AddImages("character1", C1Dir + L"77.png");
		ResourceManager::AddImages("character1", C1Dir + L"78.png");
		ResourceManager::AddImages("character1", C1Dir + L"78.png");
		ResourceManager::AddImages("character1", C1Dir + L"78.png");
		ResourceManager::AddImages("character1", C1Dir + L"78.png");
		ResourceManager::AddImages("character1", C1Dir + L"78.png");
		ResourceManager::AddImages("character1", C1Dir + L"78.png");
		ResourceManager::AddImages("character1", C1Dir + L"78.png");
		ResourceManager::AddImages("character1", C1Dir + L"78.png");
		ResourceManager::AddImages("character1", C1Dir + L"79.png");
		ResourceManager::AddImages("character1", C1Dir + L"80.png");
		ResourceManager::AddImages("character1", C1Dir + L"81.png");
		ResourceManager::AddImages("character1", C1Dir + L"82.png");
		ResourceManager::AddImages("character1", C1Dir + L"83.png");
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
		// 스킬1
		ResourceManager::AddImages("character2", C2Dir + L"74.png");
		ResourceManager::AddImages("character2", C2Dir + L"75.png");
		ResourceManager::AddImages("character2", C2Dir + L"76.png");
		ResourceManager::AddImages("character2", C2Dir + L"77.png");
		ResourceManager::AddImages("character2", C2Dir + L"78.png");
		ResourceManager::AddImages("character2", C2Dir + L"78.png");
		ResourceManager::AddImages("character2", C2Dir + L"78.png");
		ResourceManager::AddImages("character2", C2Dir + L"78.png");
		ResourceManager::AddImages("character2", C2Dir + L"78.png");
		ResourceManager::AddImages("character2", C2Dir + L"78.png");
		ResourceManager::AddImages("character2", C2Dir + L"78.png");
		ResourceManager::AddImages("character2", C2Dir + L"78.png");
		ResourceManager::AddImages("character2", C2Dir + L"79.png");
		ResourceManager::AddImages("character2", C2Dir + L"80.png");
		ResourceManager::AddImages("character2", C2Dir + L"81.png");
		ResourceManager::AddImages("character2", C2Dir + L"82.png");
		ResourceManager::AddImages("character2", C2Dir + L"83.png");
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
		// 스킬1
		ResourceManager::AddImages("character3", C3Dir + L"74.png");
		ResourceManager::AddImages("character3", C3Dir + L"75.png");
		ResourceManager::AddImages("character3", C3Dir + L"76.png");
		ResourceManager::AddImages("character3", C3Dir + L"77.png");
		ResourceManager::AddImages("character3", C3Dir + L"78.png");
		ResourceManager::AddImages("character3", C3Dir + L"78.png");
		ResourceManager::AddImages("character3", C3Dir + L"78.png");
		ResourceManager::AddImages("character3", C3Dir + L"78.png");
		ResourceManager::AddImages("character3", C3Dir + L"78.png");
		ResourceManager::AddImages("character3", C3Dir + L"78.png");
		ResourceManager::AddImages("character3", C3Dir + L"78.png");
		ResourceManager::AddImages("character3", C3Dir + L"78.png");
		ResourceManager::AddImages("character3", C3Dir + L"79.png");
		ResourceManager::AddImages("character3", C3Dir + L"80.png");
		ResourceManager::AddImages("character3", C3Dir + L"81.png");
		ResourceManager::AddImages("character3", C3Dir + L"82.png");
		ResourceManager::AddImages("character3", C3Dir + L"83.png");
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
		subAnim.scale = 1;
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
		subAnim.scale = 1.0;
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
		//skill
		subAnim.next = CharacterNormalState::None;
		subAnim.subImageStartIndex = 93;
		subAnim.scale = 2.0;
		subAnim.subImageSize = 17;
		motionContainer[CharacterNormalState::MOTION16] = subAnim;
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
		//스킬
		ResourceManager::AddCollision("character", ChaColDir + "74.txt");
		ResourceManager::AddCollision("character", ChaColDir + "75.txt");
		ResourceManager::AddCollision("character", ChaColDir + "76.txt");
		ResourceManager::AddCollision("character", ChaColDir + "77.txt");
		ResourceManager::AddCollision("character", ChaColDir + "78.txt");
		ResourceManager::AddCollision("character", ChaColDir + "78.txt");
		ResourceManager::AddCollision("character", ChaColDir + "78.txt");
		ResourceManager::AddCollision("character", ChaColDir + "78.txt");
		ResourceManager::AddCollision("character", ChaColDir + "78.txt");
		ResourceManager::AddCollision("character", ChaColDir + "78.txt");
		ResourceManager::AddCollision("character", ChaColDir + "78.txt");
		ResourceManager::AddCollision("character", ChaColDir + "78.txt");
		ResourceManager::AddCollision("character", ChaColDir + "79.txt");
		ResourceManager::AddCollision("character", ChaColDir + "80.txt");
		ResourceManager::AddCollision("character", ChaColDir + "81.txt");
		ResourceManager::AddCollision("character", ChaColDir + "82.txt");
		ResourceManager::AddCollision("character", ChaColDir + "83.txt");
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
		subAnim.scale = 0.7;
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
		subAnim.scale = 0.4;
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
		subAnim.scale = 0.6;
		subAnim.subImageStartIndex = 22;
		subAnim.subImageSize = 11;
		motionContainer[CharacterNormalState::MOTION4] = subAnim;
		//공격2(근거리)
		subAnim.next = CharacterNormalState::None;
		subAnim.scale = 1.0;
		subAnim.subImageStartIndex = 32;
		subAnim.subImageSize = 7;
		motionContainer[CharacterNormalState::MOTION5] = subAnim;
		ResourceManager::AddMotion("archer", std::move(motionContainer));
	}

	//물리 정의
	{
		// 대기
		ResourceManager::AddCollision("archer", archerColDir + "0.txt", 0.65f);
		ResourceManager::AddCollision("archer", archerColDir + "1.txt", 0.65f);
		ResourceManager::AddCollision("archer", archerColDir + "2.txt", 0.65f);
		ResourceManager::AddCollision("archer", archerColDir + "3.txt", 0.65f);
		ResourceManager::AddCollision("archer", archerColDir + "4.txt", 0.65f);
		ResourceManager::AddCollision("archer", archerColDir + "5.txt", 0.65f);
		//이동
		ResourceManager::AddCollision("archer", archerColDir + "13.txt", 0.65f);
		ResourceManager::AddCollision("archer", archerColDir + "12.txt", 0.65f);
		ResourceManager::AddCollision("archer", archerColDir + "11.txt", 0.65f);
		ResourceManager::AddCollision("archer", archerColDir + "10.txt", 0.65f);
		ResourceManager::AddCollision("archer", archerColDir + "9.txt", 0.65f), 
		ResourceManager::AddCollision("archer", archerColDir + "8.txt", 0.65f), 
		ResourceManager::AddCollision("archer", archerColDir + "7.txt", 0.65f);
		ResourceManager::AddCollision("archer", archerColDir + "6.txt", 0.65f);
		// 피격													
		ResourceManager::AddCollision("archer", archerColDir + "14.txt", 0.65f);
		ResourceManager::AddCollision("archer", archerColDir + "15.txt", 0.65f);
		// 다운
		ResourceManager::AddCollision("archer", archerColDir + "16.txt", 0.65f);
		ResourceManager::AddCollision("archer", archerColDir + "17.txt", 0.65f);
		ResourceManager::AddCollision("archer", archerColDir + "18.txt", 0.65f);
		ResourceManager::AddCollision("archer", archerColDir + "19.txt", 0.65f);
		ResourceManager::AddCollision("archer", archerColDir + "20.txt", 0.65f);
		ResourceManager::AddCollision("archer", archerColDir + "21.txt", 0.65f);
		// 공격1(원거리)
		ResourceManager::AddCollision("archer", archerColDir + "22.txt", 0.65f);
		ResourceManager::AddCollision("archer", archerColDir + "23.txt", 0.65f);
		ResourceManager::AddCollision("archer", archerColDir + "24.txt", 0.65f);
		ResourceManager::AddCollision("archer", archerColDir + "25.txt", 0.65f);
		ResourceManager::AddCollision("archer", archerColDir + "26.txt", 0.65f);
		ResourceManager::AddCollision("archer", archerColDir + "27.txt", 0.65f);
		ResourceManager::AddCollision("archer", archerColDir + "28.txt", 0.65f);
		ResourceManager::AddCollision("archer", archerColDir + "29.txt", 0.65f);
		ResourceManager::AddCollision("archer", archerColDir + "30.txt", 0.65f);
		ResourceManager::AddCollision("archer", archerColDir + "31.txt", 0.65f);
		ResourceManager::AddCollision("archer", archerColDir + "32.txt", 0.65f);
		// 공격2(근거리)
		ResourceManager::AddCollision("archer", archerColDir + "33.txt", 0.65f);
		ResourceManager::AddCollision("archer", archerColDir + "34.txt", 0.65f);
		ResourceManager::AddCollision("archer", archerColDir + "35.txt", 0.65f);
		ResourceManager::AddCollision("archer", archerColDir + "36.txt", 0.65f);
		ResourceManager::AddCollision("archer", archerColDir + "37.txt", 0.65f);
		ResourceManager::AddCollision("archer", archerColDir + "38.txt", 0.65f);
		ResourceManager::AddCollision("archer", archerColDir + "39.txt", 0.65f);
	}
#pragma endregion

#pragma region Giant
	const std::wstring giantDir = L"Resources/giant/img/";
	const std::string giantColDir = "Resources/giant/col/";
	//이미지 정의
	{
		// 대기
		ResourceManager::AddImages("giant", giantDir + L"0.png",true);
		ResourceManager::AddImages("giant", giantDir + L"1.png",true);
		ResourceManager::AddImages("giant", giantDir + L"2.png",true);
		ResourceManager::AddImages("giant", giantDir + L"3.png",true);
		ResourceManager::AddImages("giant", giantDir + L"4.png",true);
		ResourceManager::AddImages("giant", giantDir + L"5.png",true);
		// 이동
		ResourceManager::AddImages("giant", giantDir + L"6.png",true);
		ResourceManager::AddImages("giant", giantDir + L"7.png",true);
		ResourceManager::AddImages("giant", giantDir + L"8.png",true);
		ResourceManager::AddImages("giant", giantDir + L"9.png",true);
		ResourceManager::AddImages("giant", giantDir + L"10.png",true);
		ResourceManager::AddImages("giant", giantDir + L"11.png",true);
		ResourceManager::AddImages("giant", giantDir + L"12.png",true);
		ResourceManager::AddImages("giant", giantDir + L"13.png",true);
		ResourceManager::AddImages("giant", giantDir + L"14.png",true);
		ResourceManager::AddImages("giant", giantDir + L"15.png",true);
		ResourceManager::AddImages("giant", giantDir + L"16.png",true);
		ResourceManager::AddImages("giant", giantDir + L"17.png",true);
		// 다운
		ResourceManager::AddImages("giant", giantDir + L"18.png",true);
		// 공격1
		ResourceManager::AddImages("giant", giantDir + L"19.png",true);
		ResourceManager::AddImages("giant", giantDir + L"20.png",true);
		ResourceManager::AddImages("giant", giantDir + L"21.png",true);
		ResourceManager::AddImages("giant", giantDir + L"22.png",true);
		ResourceManager::AddImages("giant", giantDir + L"23.png",true);
		ResourceManager::AddImages("giant", giantDir + L"24.png",true);
		ResourceManager::AddImages("giant", giantDir + L"25.png",true);
		ResourceManager::AddImages("giant", giantDir + L"26.png",true);
		// 공격2
		ResourceManager::AddImages("giant", giantDir + L"27.png", true);
		ResourceManager::AddImages("giant", giantDir + L"28.png", true);
		ResourceManager::AddImages("giant", giantDir + L"29.png", true);
		ResourceManager::AddImages("giant", giantDir + L"30.png", true);
		ResourceManager::AddImages("giant", giantDir + L"31.png", true);
		ResourceManager::AddImages("giant", giantDir + L"32.png", true);
		// 공격3
		ResourceManager::AddImages("giant", giantDir + L"33.png", true);
		ResourceManager::AddImages("giant", giantDir + L"34.png", true);
		ResourceManager::AddImages("giant", giantDir + L"35.png", true);
		ResourceManager::AddImages("giant", giantDir + L"36.png", true);
		ResourceManager::AddImages("giant", giantDir + L"37.png", true);
		ResourceManager::AddImages("giant", giantDir + L"38.png", true);
		// 공격4
		ResourceManager::AddImages("giant", giantDir + L"39.png", true);
		ResourceManager::AddImages("giant", giantDir + L"40.png", true);
		ResourceManager::AddImages("giant", giantDir + L"41.png", true);
		ResourceManager::AddImages("giant", giantDir + L"42.png", true);
		ResourceManager::AddImages("giant", giantDir + L"43.png", true);
		ResourceManager::AddImages("giant", giantDir + L"44.png", true);
		ResourceManager::AddImages("giant", giantDir + L"45.png", true);
		ResourceManager::AddImages("giant", giantDir + L"46.png", true);
		ResourceManager::AddImages("giant", giantDir + L"47.png", true);
		ResourceManager::AddImages("giant", giantDir + L"48.png", true);

	}
	//모션 정의
	{
		MotionContainer motionContainer;
		subAnimation subAnim;
		// 대기
		subAnim.next = CharacterNormalState::LOOP;
		subAnim.scale = 0.3;
		subAnim.subImageStartIndex = 0;
		subAnim.subImageSize = 6;
		motionContainer[CharacterNormalState::IDLE] = subAnim;
		// 이동
		subAnim.next = CharacterNormalState::None;
		subAnim.scale = 0.8;
		subAnim.subImageStartIndex = 6;
		subAnim.subImageSize = 12;
		motionContainer[CharacterNormalState::MOTION1] = subAnim;
		// 다운
		subAnim.next = CharacterNormalState::None;
		subAnim.scale = 0.25;
		subAnim.subImageStartIndex = 18;
		subAnim.subImageSize = 1;
		motionContainer[CharacterNormalState::MOTION2] = subAnim;
		// 공격1
		subAnim.next = CharacterNormalState::None;
		subAnim.scale = 0.5;
		subAnim.subImageStartIndex = 19;
		subAnim.subImageSize = 8;
		motionContainer[CharacterNormalState::MOTION3] = subAnim;
		// 공격2
		subAnim.next = CharacterNormalState::None;
		subAnim.scale = 0.5;
		subAnim.subImageStartIndex = 27;
		subAnim.subImageSize = 6;
		motionContainer[CharacterNormalState::MOTION4] = subAnim;
		// 공격3
		subAnim.next = CharacterNormalState::None;
		subAnim.scale = 0.2;
		subAnim.subImageStartIndex = 33;
		subAnim.subImageSize = 6;
		motionContainer[CharacterNormalState::MOTION5] = subAnim;
		// 공격4
		subAnim.next = CharacterNormalState::None;
		subAnim.scale = 0.40;
		subAnim.subImageStartIndex = 39;
		subAnim.subImageSize = 10;
		motionContainer[CharacterNormalState::MOTION6] = subAnim;
		ResourceManager::AddMotion("giant", std::move(motionContainer));
	}

	//물리 정의
	{
		// 대기
		ResourceManager::AddCollision("giant", giantColDir + "0.txt");
		ResourceManager::AddCollision("giant", giantColDir + "1.txt");
		ResourceManager::AddCollision("giant", giantColDir + "2.txt");
		ResourceManager::AddCollision("giant", giantColDir + "3.txt");
		ResourceManager::AddCollision("giant", giantColDir + "4.txt");
		ResourceManager::AddCollision("giant", giantColDir + "5.txt");
		ResourceManager::AddCollision("giant", giantColDir + "6.txt");
		ResourceManager::AddCollision("giant", giantColDir + "7.txt");
		ResourceManager::AddCollision("giant", giantColDir + "8.txt");
		ResourceManager::AddCollision("giant", giantColDir + "9.txt");
		ResourceManager::AddCollision("giant", giantColDir + "10.txt");
		ResourceManager::AddCollision("giant", giantColDir + "11.txt");
		ResourceManager::AddCollision("giant", giantColDir + "12.txt");
		ResourceManager::AddCollision("giant", giantColDir + "13.txt");
		ResourceManager::AddCollision("giant", giantColDir + "14.txt");
		ResourceManager::AddCollision("giant", giantColDir + "15.txt");
		ResourceManager::AddCollision("giant", giantColDir + "16.txt");
		ResourceManager::AddCollision("giant", giantColDir + "17.txt");
		ResourceManager::AddCollision("giant", giantColDir + "18.txt");
		ResourceManager::AddCollision("giant", giantColDir + "19.txt");
		ResourceManager::AddCollision("giant", giantColDir + "20.txt");
		ResourceManager::AddCollision("giant", giantColDir + "21.txt");
		ResourceManager::AddCollision("giant", giantColDir + "22.txt");
		ResourceManager::AddCollision("giant", giantColDir + "23.txt");
		ResourceManager::AddCollision("giant", giantColDir + "24.txt");
		ResourceManager::AddCollision("giant", giantColDir + "25.txt");
		ResourceManager::AddCollision("giant", giantColDir + "26.txt");
		ResourceManager::AddCollision("giant", giantColDir + "27.txt");
		ResourceManager::AddCollision("giant", giantColDir + "28.txt");
		ResourceManager::AddCollision("giant", giantColDir + "29.txt");
		ResourceManager::AddCollision("giant", giantColDir + "30.txt");
		ResourceManager::AddCollision("giant", giantColDir + "31.txt");
		ResourceManager::AddCollision("giant", giantColDir + "32.txt");
		ResourceManager::AddCollision("giant", giantColDir + "33.txt");
		ResourceManager::AddCollision("giant", giantColDir + "34.txt");
		ResourceManager::AddCollision("giant", giantColDir + "35.txt");
		ResourceManager::AddCollision("giant", giantColDir + "36.txt");
		ResourceManager::AddCollision("giant", giantColDir + "37.txt");
		ResourceManager::AddCollision("giant", giantColDir + "38.txt");
		ResourceManager::AddCollision("giant", giantColDir + "39.txt");
		ResourceManager::AddCollision("giant", giantColDir + "40.txt");
		ResourceManager::AddCollision("giant", giantColDir + "41.txt");
		ResourceManager::AddCollision("giant", giantColDir + "42.txt");
		ResourceManager::AddCollision("giant", giantColDir + "43.txt");
		ResourceManager::AddCollision("giant", giantColDir + "44.txt");
		ResourceManager::AddCollision("giant", giantColDir + "45.txt");
		ResourceManager::AddCollision("giant", giantColDir + "46.txt");
		ResourceManager::AddCollision("giant", giantColDir + "47.txt");
		ResourceManager::AddCollision("giant", giantColDir + "48.txt");
	}
#pragma endregion
#pragma region Lancer
	const std::wstring lancerDir = L"Resources/lancer/img/";
	const std::string lancerColDir = "Resources/lancer/col/";
	//이미지 정의
	{
		// 대기
		ResourceManager::AddImages("lancer", lancerDir + L"0.png", true);
		ResourceManager::AddImages("lancer", lancerDir + L"1.png", true);
		ResourceManager::AddImages("lancer", lancerDir + L"2.png", true);
		ResourceManager::AddImages("lancer", lancerDir + L"3.png", true);
		ResourceManager::AddImages("lancer", lancerDir + L"4.png", true);
		ResourceManager::AddImages("lancer", lancerDir + L"5.png", true);
		// 이동
		ResourceManager::AddImages("lancer", lancerDir + L"6.png", true);
		ResourceManager::AddImages("lancer", lancerDir + L"7.png", true);
		ResourceManager::AddImages("lancer", lancerDir + L"8.png", true);
		ResourceManager::AddImages("lancer", lancerDir + L"9.png", true);
		ResourceManager::AddImages("lancer", lancerDir + L"10.png", true);
		ResourceManager::AddImages("lancer", lancerDir + L"11.png", true);
		ResourceManager::AddImages("lancer", lancerDir + L"12.png", true);
		ResourceManager::AddImages("lancer", lancerDir + L"13.png", true);
		ResourceManager::AddImages("lancer", lancerDir + L"14.png", true);
		ResourceManager::AddImages("lancer", lancerDir + L"15.png", true);
		ResourceManager::AddImages("lancer", lancerDir + L"16.png", true);
		ResourceManager::AddImages("lancer", lancerDir + L"17.png", true);
		// 다운
		ResourceManager::AddImages("lancer", lancerDir + L"18.png", true);
		// 공격1
		ResourceManager::AddImages("lancer", lancerDir + L"19.png", true);
		ResourceManager::AddImages("lancer", lancerDir + L"20.png", true);
		ResourceManager::AddImages("lancer", lancerDir + L"21.png", true);
		ResourceManager::AddImages("lancer", lancerDir + L"22.png", true);
		ResourceManager::AddImages("lancer", lancerDir + L"23.png", true);
		ResourceManager::AddImages("lancer", lancerDir + L"24.png", true);
		ResourceManager::AddImages("lancer", lancerDir + L"25.png", true);
		ResourceManager::AddImages("lancer", lancerDir + L"26.png", true);
		// 공격2
		ResourceManager::AddImages("lancer",lancerDir + L"27.png", true);
		ResourceManager::AddImages("lancer",lancerDir + L"28.png", true);
		ResourceManager::AddImages("lancer",lancerDir + L"29.png", true);
		ResourceManager::AddImages("lancer",lancerDir + L"30.png", true);
		ResourceManager::AddImages("lancer",lancerDir + L"31.png", true);
		ResourceManager::AddImages("lancer",lancerDir + L"32.png", true);
		// 공격3
		ResourceManager::AddImages("lancer", lancerDir + L"33.png", true);
		ResourceManager::AddImages("lancer", lancerDir + L"34.png", true);
		ResourceManager::AddImages("lancer", lancerDir + L"35.png", true);
		

	}
	//모션 정의
	{
		MotionContainer motionContainer;
		subAnimation subAnim;
		// 대기
		subAnim.next = CharacterNormalState::LOOP;
		subAnim.scale = 0.5;
		subAnim.subImageStartIndex = 0;
		subAnim.subImageSize = 4;
		motionContainer[CharacterNormalState::IDLE] = subAnim;
		// 이동
		subAnim.next = CharacterNormalState::None;
		subAnim.scale = 0.8;
		subAnim.subImageStartIndex = 4;
		subAnim.subImageSize = 8;
		motionContainer[CharacterNormalState::MOTION1] = subAnim;
		// 피격
		subAnim.next = CharacterNormalState::None;
		subAnim.scale = 0.7;
		subAnim.subImageStartIndex = 12;
		subAnim.subImageSize = 2;
		motionContainer[CharacterNormalState::MOTION2] = subAnim;
		// 다운
		subAnim.next = CharacterNormalState::None;
		subAnim.scale = 0.5;
		subAnim.subImageStartIndex = 14;
		subAnim.subImageSize = 3;
		motionContainer[CharacterNormalState::MOTION3] = subAnim;
		// 공격1
		subAnim.next = CharacterNormalState::None;
		subAnim.scale = 0.4;
		subAnim.subImageStartIndex = 17;
		subAnim.subImageSize = 6;
		motionContainer[CharacterNormalState::MOTION4] = subAnim;
		// 공격2
		subAnim.next = CharacterNormalState::None;
		subAnim.scale = 1;
		subAnim.subImageStartIndex = 23;
		subAnim.subImageSize = 6;
		motionContainer[CharacterNormalState::MOTION5] = subAnim;
		// 공격3
		subAnim.next = CharacterNormalState::None;
		subAnim.scale = 0.3;
		subAnim.subImageStartIndex = 29;
		subAnim.subImageSize = 7;
		motionContainer[CharacterNormalState::MOTION6] = subAnim;
		ResourceManager::AddMotion("lancer", std::move(motionContainer));
	}

	//물리 정의
	{
		// 대기
		ResourceManager::AddCollision("lancer", lancerColDir + "0.txt");
		ResourceManager::AddCollision("lancer", lancerColDir + "1.txt");
		ResourceManager::AddCollision("lancer", lancerColDir + "2.txt");
		ResourceManager::AddCollision("lancer", lancerColDir + "3.txt");
		ResourceManager::AddCollision("lancer", lancerColDir + "4.txt");
		ResourceManager::AddCollision("lancer", lancerColDir + "5.txt");
		ResourceManager::AddCollision("lancer", lancerColDir + "6.txt");
		ResourceManager::AddCollision("lancer", lancerColDir + "7.txt");
		ResourceManager::AddCollision("lancer", lancerColDir + "8.txt");
		ResourceManager::AddCollision("lancer", lancerColDir + "9.txt");
		ResourceManager::AddCollision("lancer", lancerColDir + "10.txt");
		ResourceManager::AddCollision("lancer", lancerColDir + "11.txt");
		ResourceManager::AddCollision("lancer", lancerColDir + "12.txt");
		ResourceManager::AddCollision("lancer", lancerColDir + "13.txt");
		ResourceManager::AddCollision("lancer", lancerColDir + "14.txt");
		ResourceManager::AddCollision("lancer", lancerColDir + "15.txt");
		ResourceManager::AddCollision("lancer", lancerColDir + "16.txt");
		ResourceManager::AddCollision("lancer", lancerColDir + "17.txt");
		ResourceManager::AddCollision("lancer", lancerColDir + "18.txt");
		ResourceManager::AddCollision("lancer", lancerColDir + "19.txt");
		ResourceManager::AddCollision("lancer", lancerColDir + "20.txt");
		ResourceManager::AddCollision("lancer", lancerColDir + "21.txt");
		ResourceManager::AddCollision("lancer", lancerColDir + "22.txt");
		ResourceManager::AddCollision("lancer", lancerColDir + "23.txt");
		ResourceManager::AddCollision("lancer", lancerColDir + "24.txt");
		ResourceManager::AddCollision("lancer", lancerColDir + "25.txt");
		ResourceManager::AddCollision("lancer", lancerColDir + "26.txt");
		ResourceManager::AddCollision("lancer", lancerColDir + "27.txt");
		ResourceManager::AddCollision("lancer", lancerColDir + "28.txt");
		ResourceManager::AddCollision("lancer", lancerColDir + "29.txt");
		ResourceManager::AddCollision("lancer", lancerColDir + "30.txt");
		ResourceManager::AddCollision("lancer", lancerColDir + "31.txt");
		ResourceManager::AddCollision("lancer", lancerColDir + "32.txt");
		ResourceManager::AddCollision("lancer", lancerColDir + "33.txt");
		ResourceManager::AddCollision("lancer", lancerColDir + "34.txt");
		ResourceManager::AddCollision("lancer", lancerColDir + "35.txt");
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
	//화살
	{
		const std::wstring arrowDir = L"Resources/effect/arrow/";
		const std::string arrowColDir = "Resources/effect/arrow/";
		ResourceManager::AddImages("arrow", arrowDir + L"0.png");
		ResourceManager::AddCollision("arrow", arrowColDir + "0.txt");

		MotionContainer motionContainer;

		subAnimation subAnim;
		subAnim.next = CharacterNormalState::None;
		subAnim.scale = 1;
		subAnim.subImageStartIndex = 0;
		subAnim.subImageSize = 1;
		motionContainer[CharacterNormalState::IDLE] = subAnim;
		ResourceManager::AddMotion("arrow", std::move(motionContainer));

		subEffect subEffect;
		subEffect.ImageTag = "arrow";
		subEffect.MotionTag = "arrow";
		subEffect.CollisionTag = "arrow";
		subEffect.ImageMargin = Vec2DF{ 30,5 };
		subEffect.func = CommonEffectFunctionSet::GetMoveingEffectSet(Vec2DF{ -1000.0f,0 },
			[](GameStateObject& object, GameStateObject& other, const CollisionResult::ResultVector& result)->bool
			{
				for (auto& res : result)
				{
					if (res.second == "body")
					{
						other.Damaged(20);
						other.ResetDamageCounter();
						object.Deactive();
					}
				}
				return false;
			},this
			);
		Effect::AddEffect("arrow", std::move(subEffect));
	}
	// Giant 충격파
	{
		const std::wstring giant_waveDir = L"Resources/effect/giant_wave/";
		const std::string giant_waveColDir = "Resources/effect1/giant_wave/col/";
		ResourceManager::AddImages("giant_wave", giant_waveDir + L"0.png");
		ResourceManager::AddImages("giant_wave", giant_waveDir + L"1.png");
		ResourceManager::AddImages("giant_wave", giant_waveDir + L"2.png");
		ResourceManager::AddImages("giant_wave", giant_waveDir + L"3.png");
		ResourceManager::AddImages("giant_wave", giant_waveDir + L"4.png");
		ResourceManager::AddImages("giant_wave", giant_waveDir + L"5.png");
		ResourceManager::AddImages("giant_wave", giant_waveDir + L"6.png");
		ResourceManager::AddImages("giant_wave", giant_waveDir + L"7.png");
		ResourceManager::AddImages("giant_wave", giant_waveDir + L"8.png");
		ResourceManager::AddImages("giant_wave", giant_waveDir + L"9.png");
		MotionContainer motionContainer;

		subAnimation subAnim;
		subAnim.next = CharacterNormalState::None;
		subAnim.scale = 1;
		subAnim.subImageStartIndex = 0;
		subAnim.subImageSize = 10;
		motionContainer[CharacterNormalState::IDLE] = subAnim;
		ResourceManager::AddMotion("giant_wave", std::move(motionContainer));

		subEffect subEffect;
		subEffect.ImageTag = "giant_wave";
		subEffect.MotionTag = "giant_wave";
		subEffect.CollisionTag = "giant_wave";
		subEffect.ImageMargin = Vec2DF{ 400,50 };
		subEffect.func = CommonEffectFunctionSet::GetOnceAnimeSet();
		Effect::AddEffect("giant_wave", std::move(subEffect));
	}
	// Giant 공격1
	{
		const std::wstring giant_swingDir = L"Resources/effect/giant_swing/";
		const std::string giant_swingColDir = "Resources/effect1/giant_swing/col/";
		ResourceManager::AddImages("giant_swing", giant_swingDir + L"0.png");
		ResourceManager::AddImages("giant_swing", giant_swingDir + L"1.png");
		ResourceManager::AddImages("giant_swing", giant_swingDir + L"2.png");
		ResourceManager::AddImages("giant_swing", giant_swingDir + L"3.png");
		ResourceManager::AddImages("giant_swing", giant_swingDir + L"4.png");
		ResourceManager::AddImages("giant_swing", giant_swingDir + L"5.png");
		MotionContainer motionContainer;

		subAnimation subAnim;
		subAnim.next = CharacterNormalState::None;
		subAnim.scale = 1;
		subAnim.subImageStartIndex = 0;
		subAnim.subImageSize = 6;
		motionContainer[CharacterNormalState::IDLE] = subAnim;
		ResourceManager::AddMotion("giant_swing", std::move(motionContainer));

		subEffect subEffect;
		subEffect.ImageTag = "giant_swing";
		subEffect.MotionTag = "giant_swing";
		subEffect.CollisionTag = "giant_swing";
		subEffect.ImageMargin = Vec2DF{ 250,200 };
		subEffect.func = CommonEffectFunctionSet::GetOnceAnimeSet();
		Effect::AddEffect("giant_swing", std::move(subEffect));
	}
	// Giant 공격2(종휘두르기)
	{
		const std::wstring giant_smashDir = L"Resources/effect/giant_smash/";
		const std::string giant_smashColDir = "Resources/effect1/giant_smash/col/";
		ResourceManager::AddImages("giant_smash", giant_smashDir + L"0.png");
		ResourceManager::AddImages("giant_smash", giant_smashDir + L"1.png");
		ResourceManager::AddImages("giant_smash", giant_smashDir + L"2.png");
		ResourceManager::AddImages("giant_smash", giant_smashDir + L"3.png");
		ResourceManager::AddImages("giant_smash", giant_smashDir + L"4.png");
		ResourceManager::AddImages("giant_smash", giant_smashDir + L"5.png");
		ResourceManager::AddImages("giant_smash", giant_smashDir + L"6.png");
		ResourceManager::AddImages("giant_smash", giant_smashDir + L"7.png");
		ResourceManager::AddImages("giant_smash", giant_smashDir + L"8.png");
		MotionContainer motionContainer;

		subAnimation subAnim;
		subAnim.next = CharacterNormalState::None;
		subAnim.scale = 0.7;
		subAnim.subImageStartIndex = 0;
		subAnim.subImageSize = 9;
		motionContainer[CharacterNormalState::IDLE] = subAnim;
		ResourceManager::AddMotion("giant_smash", std::move(motionContainer));

		subEffect subEffect;
		subEffect.ImageTag = "giant_smash";
		subEffect.MotionTag = "giant_smash";
		subEffect.CollisionTag = "giant_smash";
		subEffect.ImageMargin = Vec2DF{ 450,350 };
		subEffect.func = CommonEffectFunctionSet::GetOnceAnimeSet();
		Effect::AddEffect("giant_smash", std::move(subEffect));
	}
	// Giant 용암
	{
		const std::wstring giant_lavaDir = L"Resources/effect/giant_lava/";
		const std::string giant_lavaColDir = "Resources/effect1/giant_lava/col/";
		ResourceManager::AddImages("giant_lava", giant_lavaDir + L"0.png");
		ResourceManager::AddImages("giant_lava", giant_lavaDir + L"1.png");
		ResourceManager::AddImages("giant_lava", giant_lavaDir + L"2.png");
		ResourceManager::AddImages("giant_lava", giant_lavaDir + L"3.png");
		ResourceManager::AddImages("giant_lava", giant_lavaDir + L"4.png");
		ResourceManager::AddImages("giant_lava", giant_lavaDir + L"5.png");
		ResourceManager::AddImages("giant_lava", giant_lavaDir + L"6.png");
		ResourceManager::AddImages("giant_lava", giant_lavaDir + L"7.png");
		ResourceManager::AddImages("giant_lava", giant_lavaDir + L"8.png");
		ResourceManager::AddImages("giant_lava", giant_lavaDir + L"9.png");
		ResourceManager::AddImages("giant_lava", giant_lavaDir + L"10.png");
		ResourceManager::AddImages("giant_lava", giant_lavaDir + L"11.png");
		ResourceManager::AddImages("giant_lava", giant_lavaDir + L"12.png");
		ResourceManager::AddImages("giant_lava", giant_lavaDir + L"13.png");
		ResourceManager::AddImages("giant_lava", giant_lavaDir + L"14.png");
		ResourceManager::AddImages("giant_lava", giant_lavaDir + L"15.png");
		ResourceManager::AddImages("giant_lava", giant_lavaDir + L"16.png");
		MotionContainer motionContainer;

		subAnimation subAnim;
		subAnim.next = CharacterNormalState::None;
		subAnim.scale = 1;
		subAnim.subImageStartIndex = 0;
		subAnim.subImageSize = 17;
		motionContainer[CharacterNormalState::IDLE] = subAnim;
		ResourceManager::AddMotion("giant_lava", std::move(motionContainer));

		subEffect subEffect;
		subEffect.ImageTag = "giant_lava";
		subEffect.MotionTag = "giant_lava";
		subEffect.CollisionTag = "giant_lava";
		subEffect.ImageMargin = Vec2DF{ 300,150 };
		subEffect.func = CommonEffectFunctionSet::GetOnceAnimeSet();
		Effect::AddEffect("giant_lava", std::move(subEffect));
	}
	// Giant 에너지
	{
		const std::wstring giant_energyDir = L"Resources/effect/giant_energy/";
		const std::string giant_energyColDir = "Resources/effect1/giant_energy/col/";
		ResourceManager::AddImages("giant_energy", giant_energyDir + L"0.png");
		ResourceManager::AddImages("giant_energy", giant_energyDir + L"1.png");
		ResourceManager::AddImages("giant_energy", giant_energyDir + L"2.png");
		ResourceManager::AddImages("giant_energy", giant_energyDir + L"3.png");
		ResourceManager::AddImages("giant_energy", giant_energyDir + L"4.png");
		ResourceManager::AddImages("giant_energy", giant_energyDir + L"5.png");
		ResourceManager::AddImages("giant_energy", giant_energyDir + L"6.png");
		ResourceManager::AddImages("giant_energy", giant_energyDir + L"7.png");
		ResourceManager::AddImages("giant_energy", giant_energyDir + L"8.png");
		ResourceManager::AddImages("giant_energy", giant_energyDir + L"9.png");
		ResourceManager::AddImages("giant_energy", giant_energyDir + L"10.png");
		ResourceManager::AddImages("giant_energy", giant_energyDir + L"11.png");
		MotionContainer motionContainer;

		subAnimation subAnim;
		subAnim.next = CharacterNormalState::None;
		subAnim.scale = 1;
		subAnim.subImageStartIndex = 0;
		subAnim.subImageSize = 12;
		motionContainer[CharacterNormalState::IDLE] = subAnim;
		ResourceManager::AddMotion("giant_energy", std::move(motionContainer));

		subEffect subEffect;
		subEffect.ImageTag = "giant_energy";
		subEffect.MotionTag = "giant_energy";
		subEffect.CollisionTag = "giant_energy";
		subEffect.ImageMargin = Vec2DF{ 250,300 };
		subEffect.func = CommonEffectFunctionSet::GetOnceAnimeSet();
		Effect::AddEffect("giant_energy", std::move(subEffect));
	}
	// Player Skill1
	{
		const std::wstring flashslash1Dir = L"Resources/effect/flashslash1/";
		const std::string flashslash1ColDir = "Resources/effect/flashslash1/";
		ResourceManager::AddImages("flashslash1", flashslash1Dir + L"8.png", true);
		ResourceManager::AddImages("flashslash1", flashslash1Dir + L"9.png", true);
		ResourceManager::AddImages("flashslash1", flashslash1Dir + L"10.png", true);
		ResourceManager::AddImages("flashslash1", flashslash1Dir + L"11.png", true);
		ResourceManager::AddImages("flashslash1", flashslash1Dir + L"12.png", true);
		ResourceManager::AddImages("flashslash1", flashslash1Dir + L"13.png", true);
		ResourceManager::AddImages("flashslash1", flashslash1Dir + L"14.png", true);
		ResourceManager::AddImages("flashslash1", flashslash1Dir + L"15.png", true);
		ResourceManager::AddImages("flashslash1", flashslash1Dir + L"16.png", true);
		ResourceManager::AddCollision("flashslash1", flashslash1ColDir + "8.txt");
		ResourceManager::AddCollision("flashslash1", flashslash1ColDir + "9.txt");
		ResourceManager::AddCollision("flashslash1", flashslash1ColDir + "10.txt");
		ResourceManager::AddCollision("flashslash1", flashslash1ColDir + "11.txt");
		ResourceManager::AddCollision("flashslash1", flashslash1ColDir + "12.txt");
		ResourceManager::AddCollision("flashslash1", flashslash1ColDir + "13.txt");
		ResourceManager::AddCollision("flashslash1", flashslash1ColDir + "14.txt");
		ResourceManager::AddCollision("flashslash1", flashslash1ColDir + "15.txt");
		ResourceManager::AddCollision("flashslash1", flashslash1ColDir + "16.txt");
		MotionContainer motionContainer;

		subAnimation subAnim;
		subAnim.next = CharacterNormalState::None;
		subAnim.scale = 0.8;
		subAnim.subImageStartIndex = 0;
		subAnim.subImageSize = 9;
		motionContainer[CharacterNormalState::IDLE] = subAnim;
		ResourceManager::AddMotion("flashslash1", std::move(motionContainer));

		subEffect subEffect;
		subEffect.ImageTag = "flashslash1";
		subEffect.MotionTag = "flashslash1";
		subEffect.CollisionTag = "flashslash1";
		subEffect.ImageMargin = Vec2DF{ 900,45 };
		subEffect.func = CommonEffectFunctionSet::GetSkillSet(this);
		Effect::AddEffect("flashslash1", std::move(subEffect));

	}
	{
		const std::wstring flashslash2Dir = L"Resources/effect/flashslash2/";
		const std::string flashslash2ColDir = "Resources/effect/flashslash2/";
		ResourceManager::AddImages("flashslash2", flashslash2Dir + L"0.png");
		ResourceManager::AddImages("flashslash2", flashslash2Dir + L"1.png");
		ResourceManager::AddImages("flashslash2", flashslash2Dir + L"2.png");
		ResourceManager::AddImages("flashslash2", flashslash2Dir + L"3.png");
		ResourceManager::AddImages("flashslash2", flashslash2Dir + L"4.png");
		ResourceManager::AddImages("flashslash2", flashslash2Dir + L"5.png");
		ResourceManager::AddImages("flashslash2", flashslash2Dir + L"6.png");
		ResourceManager::AddImages("flashslash2", flashslash2Dir + L"7.png");
		ResourceManager::AddImages("flashslash2", flashslash2Dir + L"8.png");
		ResourceManager::AddImages("flashslash2", flashslash2Dir + L"9.png");
		ResourceManager::AddImages("flashslash2", flashslash2Dir + L"10.png");
		ResourceManager::AddImages("flashslash2", flashslash2Dir + L"11.png");
		ResourceManager::AddImages("flashslash2", flashslash2Dir + L"12.png");
		ResourceManager::AddImages("flashslash2", flashslash2Dir + L"13.png");
		ResourceManager::AddImages("flashslash2", flashslash2Dir + L"14.png");

		ResourceManager::AddCollision("flashslash2", flashslash2ColDir + "0.txt");
		ResourceManager::AddCollision("flashslash2", flashslash2ColDir + "1.txt");
		ResourceManager::AddCollision("flashslash2", flashslash2ColDir + "2.txt");
		ResourceManager::AddCollision("flashslash2", flashslash2ColDir + "3.txt");
		ResourceManager::AddCollision("flashslash2", flashslash2ColDir + "4.txt");
		ResourceManager::AddCollision("flashslash2", flashslash2ColDir + "5.txt");
		ResourceManager::AddCollision("flashslash2", flashslash2ColDir + "6.txt");
		ResourceManager::AddCollision("flashslash2", flashslash2ColDir + "7.txt");
		ResourceManager::AddCollision("flashslash2", flashslash2ColDir + "8.txt");
		ResourceManager::AddCollision("flashslash2", flashslash2ColDir + "9.txt");
		ResourceManager::AddCollision("flashslash2", flashslash2ColDir + "10.txt");
		ResourceManager::AddCollision("flashslash2", flashslash2ColDir + "11.txt");
		ResourceManager::AddCollision("flashslash2", flashslash2ColDir + "12.txt");
		ResourceManager::AddCollision("flashslash2", flashslash2ColDir + "13.txt");
		ResourceManager::AddCollision("flashslash2", flashslash2ColDir + "14.txt");
		MotionContainer motionContainer;

		subAnimation subAnim;
		subAnim.next = CharacterNormalState::None;
		subAnim.scale = 1;
		subAnim.subImageStartIndex = 0;
		subAnim.subImageSize = 15;
		motionContainer[CharacterNormalState::IDLE] = subAnim;
		ResourceManager::AddMotion("flashslash2", std::move(motionContainer));

		subEffect subEffect;
		subEffect.ImageTag = "flashslash2";
		subEffect.MotionTag = "flashslash2";
		subEffect.CollisionTag = "flashslash2";
		subEffect.ImageMargin = Vec2DF{ 375,251 };
		subEffect.func = CommonEffectFunctionSet::GetSkillSet(this);
		Effect::AddEffect("flashslash2", std::move(subEffect));
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
		const std::wstring markDir = L"Resources/ui/mark/";
		ResourceManager::AddImages("mark-def", markDir + L"def.png");
		ResourceManager::AddImages("mark-ach", markDir + L"ach.png");
		ResourceManager::AddImages("mark-pist", markDir + L"pist.png");
		ResourceManager::AddImages("mark-lancer", markDir + L"lancer.png");
		ResourceManager::AddImages("mark-giant", markDir + L"giant.png");
		const std::wstring titleDir = L"Resources/ui/title/";
		ResourceManager::AddImages("ui-title", titleDir + L"title.png");
		ResourceManager::AddImages("ui-title", titleDir + L"csr.png", true);
		ResourceManager::AddImages("ui-died", titleDir + L"dark.png", true);
		ResourceManager::AddImages("ui-died", titleDir + L"died-text.png", true);
		ResourceManager::AddImages("ui-died", titleDir + L"clear.png", true);
		ResourceManager::AddImages("ui-help", titleDir + L"help.png", true);

	}


#pragma endregion



#pragma region Sound
	const std::string sndAttackDir = "Resources/sound/attack/";
	const std::string sndHitDir = "Resources/sound/hit/";
	const std::string bgmDir = "Resources/sound/bgm/";
	//SoundSystem::Load("zero", bgmDir + "zero.mp3");
	SoundSystem::Load("atk-slash", sndAttackDir + "blunt_01.wav");
	SoundSystem::Load("atk-boom", sndAttackDir + "boom.wav");
	SoundSystem::Load("atk-charge", sndAttackDir + "charge.wav");
	SoundSystem::Load("hit-bite", sndHitDir + "bite.wav");
	SoundSystem::Load("hit-steel", sndHitDir + "steel.wav");
	SoundSystem::Load("hit-cut", sndHitDir + "cut.wav");
#pragma endregion



}