#include "pch.h"
#include "UIDie.h"
#include "ResourceManager.h"
#include "GameFramework.h"

void UIDied::Update(float deltaTime)
{
	if (On)
	{
		alpha = Utill::clamp(alpha + 0.2f * deltaTime, 0.0f, 1.0f);
		if (alpha == 1.0f)
		{
			delayCounter += deltaTime;
			if (delayCounter > 2)
			{
				//메인화면 전환
				framework->SetGameState(false);
				isOffed = true;
			}
		}
	}
	if (isOffed)
	{
		alpha = Utill::clamp(alpha - 3.0f * deltaTime, 0.0f, 1.0f);
		if (alpha == 0.0f)
		{
			//메인화면 전환
			framework->SetGameState(false);
			isOffed = false;
			On = false;
		}
	}
}

void UIDied::Draw(PaintInfo info)
{
	auto& died = ResourceManager::GetImages("ui-died")->at(0).img;
	auto& text = ResourceManager::GetImages("ui-died")->at(1).img;
	if (On)
	{
		if (alpha == 1.0f || isOffed)
		{
			died->Draw(info.hdc, 0, 0);
		}
		else 
		{
			died->AlphaBlend(info.hdc, 0, 0, 255 * alpha);
		}
		if (isOffed)
		{
			text->AlphaBlend(info.hdc, 0, 0, 255 * alpha);
		}
		else 
		{
			text->Draw(info.hdc, 0, 0);
		}
	}
}
