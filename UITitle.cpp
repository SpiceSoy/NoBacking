#include "pch.h"
#include "UITItle.h"
#include "ResourceManager.h"
#include "GameFramework.h"

void UITitle::Update(float deltaTime)
{
	if (framework->GetGameState() == true)
	{
		alpha = Utill::clamp(alpha - 0.5f *deltaTime, 0.0f, 1.0f);
	}
	else 
	{
		alpha = Utill::clamp(alpha + 3.0f * deltaTime, 0.0f, 1.0f);
	}
	if (framework->GetGameState() == false)
	{
		if (GetAsyncKeyState(VK_UP) & 0x0001)
		{
			curSelect = Utill::clamp(curSelect - 1, 1, 2);
		}
		else if (GetAsyncKeyState(VK_DOWN) & 0x0001)
		{
			curSelect = Utill::clamp(curSelect + 1, 1, 2);
		}
		if ( GetAsyncKeyState(VK_RETURN))
		{
			if (curSelect == 1)
			{
				framework->SetGameState(true);
			}
			else 
			{
				PostQuitMessage(0);
			}
		}
	}
}

void UITitle::Draw(PaintInfo info)
{
	auto& img = ResourceManager::GetImages("ui-title")->at(0).img;
	auto& csr = ResourceManager::GetImages("ui-title")->at(1).img;
	if (alpha != 0.0f)
	{
		img->AlphaBlend(info.hdc, 0, 0, 255* alpha);
		if (framework->GetGameState() == false)
		{
			Vec2DU pos[2] = { {500,464}, {566,537} };
			csr->Draw(info.hdc, pos[curSelect - 1]);
		}
	}
	else 
	{
	}
	//Rectangle(info.hdc, info.margin, info.margin, 1280, 720);
}
