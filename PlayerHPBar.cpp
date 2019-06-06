#include "pch.h"
#include "PlayerHPBar.h"
#include "ResourceManager.h"

auto floatLerp = [](float src, float dest, float t)
{
	return (src) * (1 - t) + dest * t;
};
void PlayerHPBar::Update(float deltaTime)
{
	//if (GetAsyncKeyState('9') & 0x0001)
	//{
	//	this->destPercent = Utill::clamp(this->destPercent + 0.1f, 0.0f, 1.0f);
	//}
	//if (GetAsyncKeyState('8') & 0x0001)
	//{
	//	this->destPercent = Utill::clamp(this->destPercent - 0.1f, 0.0f, 1.0f);
	//}
	//if (GetAsyncKeyState('0'))
	//{
	//	this->destPercent = 0;
	//}
	this->currnetPercent = floatLerp(this->currnetPercent, this->destPercent, 3 * deltaTime);
}

void PlayerHPBar::Draw(PaintInfo info)
{
	auto& backImg = ResourceManager::GetImages("ui-playerhpbar")->at(0).img;
	auto& hpbarImg = ResourceManager::GetImages("ui-playerhpbar")->at(1).img;
	auto backImageSize = Vec2DF
	{
		static_cast<float>(backImg->GetWidth()),
		static_cast<float>(backImg->GetHeight())
	};
	auto barImageSize = Vec2DF
	{
		static_cast<float>(hpbarImg->GetWidth()),
		static_cast<float>(hpbarImg->GetHeight())
	};
	auto rt = RectF(Vec2DF{ 280,90 }, backImageSize.x, backImageSize.y);
	backImg->Draw(info.hdc, rt);
	auto percentRt = RectF((int)rt.left + 82, (int)rt.top + 30, (int)rt.left + 82 + (barImageSize.x * currnetPercent), (int)rt.top + 30 + barImageSize.y);
	hpbarImg->BitBlt(info.hdc, percentRt, POINT{ 0,0 });

}
