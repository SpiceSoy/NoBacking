#include "pch.h"
#include "GameFramework.h"
#include "ResourceManager.h"
void GameFramework::Load()
{
#pragma region PlayerC1
	const std::wstring C1Dir = L"Resources/character/c1/";
	const std::wstring C2Dir = L"Resources/character/c2/";
	const std::wstring C3Dir = L"Resources/character/c3/";
	const std::string ChaColDir = "Resources/character/col/";
	//C1 이미지 정의
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
	}
	//C2 이미지 정의
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

	}
	//C3 이미지 정의
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
	}
	//물리 정의
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

	}
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



}