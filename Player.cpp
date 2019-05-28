#include "pch.h"
#include "Player.h"
#include <atlimage.h>
Player::Player(GameFramework* framework, const std::string& tag)
	:GameObject(framework,tag)
{
	this->playerAnime.ReSize(71);
	//기본
	this->playerAnime.AddImage(L"Resources/png/6.png");
	this->playerAnime.AddImage(L"Resources/png/7.png");
	this->playerAnime.AddImage(L"Resources/png/8.png");
	this->playerAnime.AddImage(L"Resources/png/9.png");
	this->playerAnime.AddImage(L"Resources/png/10.png");
	this->playerAnime.AddImage(L"Resources/png/11.png");
	subAnimation subAnim;
	subAnim.next = CharacterState::LOOP;
	subAnim.subImageStartIndex = 0;
	subAnim.subImageSize = 6;
	this->playerAnime.AddMotion(CharacterState::IDLE, subAnim);
	//걷기
	this->playerAnime.AddImage(L"Resources/png/12.png");
	this->playerAnime.AddImage(L"Resources/png/13.png");
	this->playerAnime.AddImage(L"Resources/png/14.png");
	this->playerAnime.AddImage(L"Resources/png/15.png");
	this->playerAnime.AddImage(L"Resources/png/16.png");
	this->playerAnime.AddImage(L"Resources/png/17.png");
	this->playerAnime.AddImage(L"Resources/png/18.png");
	this->playerAnime.AddImage(L"Resources/png/19.png");
	this->playerAnime.AddImage(L"Resources/png/20.png");
	this->playerAnime.AddImage(L"Resources/png/21.png");
	subAnim.next = CharacterState::LOOP;
	subAnim.subImageStartIndex = 6;
	subAnim.subImageSize = 10;
	this->playerAnime.AddMotion(CharacterState::MOTION1, subAnim);
	//달리기
	this->playerAnime.AddImage(L"Resources/png/22.png");
	this->playerAnime.AddImage(L"Resources/png/23.png");
	this->playerAnime.AddImage(L"Resources/png/24.png");
	this->playerAnime.AddImage(L"Resources/png/25.png");
	this->playerAnime.AddImage(L"Resources/png/26.png");
	this->playerAnime.AddImage(L"Resources/png/27.png");
	this->playerAnime.AddImage(L"Resources/png/28.png");
	this->playerAnime.AddImage(L"Resources/png/29.png");
	subAnim.next = CharacterState::LOOP;
	subAnim.subImageStartIndex = 16;
	subAnim.subImageSize = 8;
	this->playerAnime.AddMotion(CharacterState::MOTION2, subAnim);
	//가드
	this->playerAnime.AddImage(L"Resources/png/84.png");
	this->playerAnime.AddImage(L"Resources/png/85.png");
	this->playerAnime.AddImage(L"Resources/png/86.png");
	this->playerAnime.AddImage(L"Resources/png/87.png");
	this->playerAnime.AddImage(L"Resources/png/88.png");
	this->playerAnime.AddImage(L"Resources/png/89.png");
	this->playerAnime.AddImage(L"Resources/png/90.png");
	subAnim.next = CharacterState::None;
	subAnim.subImageStartIndex = 24;
	subAnim.subImageSize = 7;
	this->playerAnime.AddMotion(CharacterState::MOTION3, subAnim);
	//찌르기
	this->playerAnime.AddImage(L"Resources/png/60.png");
	this->playerAnime.AddImage(L"Resources/png/61.png");
	this->playerAnime.AddImage(L"Resources/png/62.png");
	this->playerAnime.AddImage(L"Resources/png/63.png");
	this->playerAnime.AddImage(L"Resources/png/64.png");
	this->playerAnime.AddImage(L"Resources/png/65.png");
	subAnim.next = CharacterState::None;
	subAnim.subImageStartIndex = 31;
	subAnim.scale = 1.15;
	subAnim.subImageSize = 6;
	this->playerAnime.AddMotion(CharacterState::MOTION4, subAnim);
	//점프
	this->playerAnime.AddImage(L"Resources/png/30.png");
	this->playerAnime.AddImage(L"Resources/png/31.png");
	this->playerAnime.AddImage(L"Resources/png/32.png");
	subAnim.next = CharacterState::None;
	subAnim.subImageStartIndex = 37;
	subAnim.scale = 1.0;
	subAnim.subImageSize = 3;
	this->playerAnime.AddMotion(CharacterState::MOTION5, subAnim);
	this->playerAnime.AddImage(L"Resources/png/33.png");
	subAnim.next = CharacterState::None;
	subAnim.subImageStartIndex = 40;
	subAnim.scale = 1.0;
	subAnim.subImageSize = 1;
	this->playerAnime.AddMotion(CharacterState::MOTION6, subAnim);
	this->playerAnime.AddImage(L"Resources/png/34.png");
	this->playerAnime.AddImage(L"Resources/png/35.png");
	subAnim.next = CharacterState::None;
	subAnim.subImageStartIndex = 41;
	subAnim.scale = 1.0;
	subAnim.subImageSize = 2;
	this->playerAnime.AddMotion(CharacterState::MOTION7, subAnim);
	//점프 공격
	this->playerAnime.AddImage(L"Resources/png/43.png");
	this->playerAnime.AddImage(L"Resources/png/44.png");
	this->playerAnime.AddImage(L"Resources/png/45.png");
	this->playerAnime.AddImage(L"Resources/png/46.png");
	this->playerAnime.AddImage(L"Resources/png/47.png");
	this->playerAnime.AddImage(L"Resources/png/48.png");
	this->playerAnime.AddImage(L"Resources/png/49.png");
	this->playerAnime.AddImage(L"Resources/png/50.png");
	subAnim.next = CharacterState::None;
	subAnim.subImageStartIndex = 43;
	subAnim.scale = 1.5;
	subAnim.subImageSize = 8;
	this->playerAnime.AddMotion(CharacterState::MOTION8, subAnim);
	//베기
	this->playerAnime.AddImage(L"Resources/png/51.png");
	this->playerAnime.AddImage(L"Resources/png/52.png");
	this->playerAnime.AddImage(L"Resources/png/53.png");
	this->playerAnime.AddImage(L"Resources/png/54.png");
	this->playerAnime.AddImage(L"Resources/png/55.png");
	this->playerAnime.AddImage(L"Resources/png/56.png");
	this->playerAnime.AddImage(L"Resources/png/57.png");
	this->playerAnime.AddImage(L"Resources/png/58.png");
	this->playerAnime.AddImage(L"Resources/png/59.png");
	subAnim.next = CharacterState::None;
	subAnim.subImageStartIndex = 51;
	subAnim.scale = 1.0;
	subAnim.subImageSize = 9;
	this->playerAnime.AddMotion(CharacterState::MOTION9, subAnim);

	//점공2
	this->playerAnime.AddImage(L"Resources/png/36.png");
	this->playerAnime.AddImage(L"Resources/png/37.png");
	this->playerAnime.AddImage(L"Resources/png/38.png");
	this->playerAnime.AddImage(L"Resources/png/39.png");
	this->playerAnime.AddImage(L"Resources/png/40.png");
	this->playerAnime.AddImage(L"Resources/png/41.png");
	this->playerAnime.AddImage(L"Resources/png/42.png");
	this->playerAnime.AddImage(L"Resources/png/43.png");
	this->playerAnime.AddImage(L"Resources/png/44.png");
	this->playerAnime.AddImage(L"Resources/png/45.png");
	this->playerAnime.AddImage(L"Resources/png/46.png");
	subAnim.next = CharacterState::None;
	subAnim.subImageStartIndex = 60;
	subAnim.scale = 1.0;
	subAnim.subImageSize = 11;
	this->playerAnime.AddMotion(CharacterState::MOTION10, subAnim);





	this->playerAnime.ChangeState(CharacterState::IDLE);
	this->transform.Translate(Vec2DF::Down() * 500,1);

}

void Player::Update(float deltaTime)
{
	this->transform.Update(deltaTime);
	this->playerAnime.Update(deltaTime);
	bool keyinput = false;
	if (this->transform.GetJumpState())
	{
		if (GetAsyncKeyState('Z')) 
		{
			this->playerAnime.ChangeState(CharacterState::MOTION8);
		}
		else if (GetAsyncKeyState('X'))
		{
			this->playerAnime.ChangeState(CharacterState::MOTION10);
		}
		else if (this->transform.GetJumpPower() > 0)
		{
			this->playerAnime.ChangeState(CharacterState::MOTION5);
		}
		else if(this->transform.GetJumpPower() < 0)
		{
			this->playerAnime.ChangeState(CharacterState::MOTION6);

		}

		if (GetAsyncKeyState(VK_LEFT))
		{
			this->transform.Translate(Vec2DF::Left() * 150.0f * deltaTime);
			keyinput = true;
		}
		else if (GetAsyncKeyState(VK_RIGHT))
		{
			this->transform.Translate(Vec2DF::Right() * 350.0f * deltaTime);
			keyinput = true;
		}
		GetAsyncKeyState(VK_SPACE);
		keyinput = true;
	}
	else if (GetAsyncKeyState(VK_DOWN))
	{
		this->playerAnime.ChangeState(CharacterState::MOTION3);
		keyinput = true;
	}
	else if (GetAsyncKeyState(VK_SPACE) &0x0001)
	{
 		this->transform.Jump(500);
		keyinput = true;
	}
	else if (GetAsyncKeyState('Z'))
	{
		this->playerAnime.ChangeState(CharacterState::MOTION4);
		keyinput = true;
	}
	else if (GetAsyncKeyState('X'))
	{
		this->playerAnime.ChangeState(CharacterState::MOTION9);
		keyinput = true;
	}
	else if (GetAsyncKeyState(VK_LEFT))
	{
		this->playerAnime.ChangeState(CharacterState::MOTION1);
		this->transform.Translate(Vec2DF::Left() * 150.0f * deltaTime);
		keyinput = true;
	}
	else if (GetAsyncKeyState(VK_RIGHT))
	{
		this->playerAnime.ChangeState(CharacterState::MOTION2);
		this->transform.Translate(Vec2DF::Right() * 350.0f * deltaTime);
		keyinput = true;
	}

	if (!keyinput)
	{
		this->playerAnime.ChangeState(CharacterState::IDLE);
	}
}

void Player::Draw(PaintInfo info)
{

	auto rt = RECT{ 0,0,2200,2200};
	FillRect(info.hdc, &rt, (HBRUSH)GetStockObject(WHITE_BRUSH));
	this->playerAnime.GetCurrentImage().img.Draw(info.hdc, this->transform.Position.x, this->transform.Position.y);
}
