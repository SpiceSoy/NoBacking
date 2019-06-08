#include "pch.h"
#include "PlayerHPBar.h"
#include "ResourceManager.h"

auto floatLerp = [](float src, float dest, float t)
{
	return (src) * (1 - t) + dest * t;
};
void PlayerHPBar::Update(float deltaTime)
{
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
	auto rt = RectF(Vec2DF{ 280.f - info.margin/4,90 }, backImageSize.x, backImageSize.y);
	backImg->Draw(info.hdc, rt);
	auto percentRt = RectF((int)rt.left + 83, (int)rt.top + 30, (int)rt.left + 83 + (barImageSize.x * currnetPercent), (int)rt.top + 30 + barImageSize.y);
	hpbarImg->BitBlt(info.hdc, percentRt, POINT{ 0,0 });

}

void EnemyHPBar::Update(float deltaTime)
{
	if (On) 
	{
		this->currnetPercent = floatLerp(this->currnetPercent, this->destPercent, 3 * deltaTime);
	}
}

void EnemyHPBar::Draw(PaintInfo info)
{
	if (On)
	{
		auto& backImg = ResourceManager::GetImages("ui-playerhpbar")->at(2).img;
		auto& hpbarImg = ResourceManager::GetImages("ui-playerhpbar")->at(1).img;
		auto& markImg = ResourceManager::GetImages(this->markTag)->at(0).img;
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
		auto rt = RectF(Vec2DF{1030.f - info.margin / 2,90 }, backImageSize.x, backImageSize.y);
		backImg->Draw(info.hdc, rt);
		auto percentRt = RectF((int)rt.left + 6, (int)rt.top + 30, (int)rt.left + 6 + (barImageSize.x * currnetPercent), (int)rt.top + 30 + barImageSize.y);
		hpbarImg->BitBlt(info.hdc, percentRt, POINT{ 0,0 });
		markImg->Draw(info.hdc, rt);
	}
}
