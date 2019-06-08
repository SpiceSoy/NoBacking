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
		alpha = Utill::clamp(alpha + 0.3f * deltaTime, 0.0f, 1.0f);
	}
	if (framework->GetGameState() == false)
	{
		if ( GetAsyncKeyState(VK_RETURN))
		{
			framework->SetGameState(true);
		}
	}
}

void UITitle::Draw(PaintInfo info)
{
	auto& img = ResourceManager::GetImages("ui-title")->at(0).img;
	if (alpha != 0.0f)
	{
		img->AlphaBlend(info.hdc, 0, 0, 255* alpha);
	}
	else 
	{
		//img->Draw(info.hdc, 0,0,1280, 720);
	}
	//Rectangle(info.hdc, info.margin, info.margin, 1280, 720);
}
