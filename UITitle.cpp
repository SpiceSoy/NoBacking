#include "pch.h"
#include "UITItle.h"
#include "ResourceManager.h"
#include "GameFramework.h"

void UITitle::Update(float deltaTime)
{
	if (framework->GetGameState() == true)
	{
		alpha = Utill::clamp(alpha - 0.5f * deltaTime, 0.0f, 1.0f);
	}
	else
	{
		alpha = Utill::clamp(alpha + 3.0f * deltaTime, 0.0f, 1.0f);
	}
	if (framework->GetGameState() == false)
	{
		if (HelpOn)
		{
			if (GetAsyncKeyState(VK_RETURN) & 0x0001 || GetAsyncKeyState(VK_ESCAPE) & 0x0001)
			{
				HelpOn = false;
			}
		}
		else
		{
			if (GetAsyncKeyState(VK_UP) & 0x0001)
			{
				curSelect = Utill::clamp(curSelect - 1, 1, 3);
			}
			if (GetAsyncKeyState(VK_DOWN) & 0x0001)
			{
				curSelect = Utill::clamp(curSelect + 1, 1, 3);
			}
			if (GetAsyncKeyState(VK_RETURN))
			{
				if (curSelect == 1)
				{
					framework->SetGameState(true);
				}
				else if (curSelect == 2)
				{
					HelpOn = true;
				}
				else
				{
					PostQuitMessage(0);
				}
			}
		}
	}
}

void UITitle::Draw(PaintInfo info)
{
	auto& img = ResourceManager::GetImages("ui-title")->at(0).img;
	auto& csr = ResourceManager::GetImages("ui-title")->at(1).img;
	auto& help = ResourceManager::GetImages("ui-help")->at(0).img;
	if (alpha != 0.0f)
	{
		img->AlphaBlend(info.hdc, 0, 0, 255 * alpha);
		if (framework->GetGameState() == false)
		{
			if (HelpOn)
			{
				help->Draw(info.hdc, 0, 0);
			}
			else
			{
				Vec2DU pos[3] = { {500,464}, {566,523}, {566,583} };
				csr->Draw(info.hdc, pos[curSelect - 1]);
			}
		}
	}
	else
	{
	}
	//Rectangle(info.hdc, info.margin, info.margin, 1280, 720);
}

void UITitle::GetMouseInput(Vec2DU MousePos, UINT iMessage)
{
	switch (iMessage)
	{
	case WM_MOUSEMOVE:
		if (framework->GetGameState() == false)
		{
			if (HelpOn)
			{
			}
			else
			{
				Vec2DU pos[3] = { {498,463}, {498,524}, {498,579} };
				for (size_t i = 0; i < 3; i++)
				{
					auto rt = RectF(pos[i].x, pos[i].y, pos[i].x + 272, pos[i].y + 51);
					if (rt.hasIn(MousePos))
					{
						curSelect = i + 1;
					}
				}
			}
		}
		break;
	case WM_LBUTTONDOWN:
		if (framework->GetGameState() == false)
		{
			if (HelpOn)
			{
				HelpOn = false;
			}
			else
			{
				if (HelpOn)
				{
				}
				else
				{
					Vec2DU pos[3] = { {498,463}, {498,524}, {498,579} };
					for (size_t i = 0; i < 3; i++)
					{
						auto rt = RectF(pos[i].x, pos[i].y, pos[i].x + 272, pos[i].y + 51);
						if (rt.hasIn(MousePos))
						{
							curSelect = i + 1;
							if (curSelect == 1)
							{
								framework->SetGameState(true);
							}
							else if (curSelect == 2)
							{
								HelpOn = true;
							}
							else
							{
								PostQuitMessage(0);
							}
						}
					}
				}

			}
		}
		break;
	}
}
