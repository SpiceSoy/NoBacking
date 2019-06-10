#include "pch.h"
#include "Camera.h"
#include "ResourceManager.h"

static auto TiledF = [](float& a, float imageSize, float count)
{
	if (a > imageSize * (count / 2))
	{
		a -= imageSize * count;
	}
	else if (a < -imageSize * (count / 2))
	{
		a += imageSize * count;
	}
};

static auto TiledI = [](int& a, int imageSize, int count)
{
	if (a > imageSize * (count / 2))
	{
		a -= imageSize * count;
	}
	else if (a < -imageSize * (count / 2))
	{
		a += imageSize * count;
	}
};





Vec2DF Camera::CameraTransform(const Vec2DF& transform) const
{
	return Vec2DF(transform.x - position.x, transform.y - position.y);
}

void Camera::Lerp(Vec2DF other, float t)
{
	this->minPosition.x = this->position.x;
	this->position = this->position.Lerp(other, t);
	clamp();
}

void Camera::Move(Vec2DF vec)
{
	this->position += vec;
	clamp();
}

void Camera::Teleport(Vec2DF vec)
{
	this->position = vec;
	clamp();
}

void Camera::clamp()
{
	this->position.x = Utill::clamp(this->position.x, this->minPosition.x, this->maxPosition.x);
	this->position.y = Utill::clamp(this->position.y, this->minPosition.y, this->maxPosition.y);
}

void Camera::BackDraw(PaintInfo info) const
{
	{
		auto& backImg = ResourceManager::GetImages("bg-drago-n-back")->at(0).img;
		float scale = info.DrawSize.y / static_cast<float>(backImg->GetHeight()) * 1.05;
		Vec2DF imageSize = Vec2DF
		{
			 ResourceManager::GetImages("bg-drago-n-back")->at(0).img->GetWidth() * scale,
			  ResourceManager::GetImages("bg-drago-n-back")->at(0).img->GetHeight() * scale
		};
		float xNum = 0.15;
		float yNum = 0.05;
		float cnt = 3;
		for (size_t i = 0; i < cnt; i++)
		{
			float firstX = -position.x * xNum + (imageSize.x - 1) * i; TiledF(firstX, (imageSize.x - 1), cnt);
			backImg->Draw(info.hdc, firstX, position.y * yNum, imageSize.x, imageSize.y);
		}
	}
	{
		float scale = info.DrawSize.y / static_cast<float>(ResourceManager::GetImages("bg-drago-n-tile")->at(0).img->GetHeight()) * 0.9;
		Vec2DF imageSize = Vec2DF
		{
			 ResourceManager::GetImages("bg-drago-n-tile")->at(0).img->GetWidth() * scale,
			  ResourceManager::GetImages("bg-drago-n-tile")->at(0).img->GetHeight() * scale
		};
		float xNum = 1;
		float yNum = 1;
		float cnt = 16;
		int idx[16] =
		{
			4,1,4,0,
			4,3,4,0,
			4,2,4,3,
			4,5,4,1
		};
		for (size_t i = 0; i < cnt; i++)
		{
			auto& backImg = ResourceManager::GetImages("bg-drago-n-tile")->at(idx[i]).img;
			float firstX = -position.x * xNum + (imageSize.x - 1) * i; TiledF(firstX, (imageSize.x - 1), cnt);
			backImg->Draw(info.hdc, firstX, -position.y * yNum + 100, imageSize.x, imageSize.y);
		}

	}
}

void Camera::Draw(PaintInfo info) const
{
	if (true)
	{
		{
			auto& backImg = ResourceManager::GetImages("bg-drago-n-mid")->at(0).img;
			//float scale = info.DrawSize.y / static_cast<float>(backImg->GetHeight()) * 0.9;
			float scale = 1;
			Vec2DF imageSize = Vec2DF
			{
				 ResourceManager::GetImages("bg-drago-n-mid")->at(0).img->GetWidth() * scale,
				  ResourceManager::GetImages("bg-drago-n-mid")->at(0).img->GetHeight() * scale
			};
			float xNum = 1;
			float yNum = 1;
			float cnt = 6;
			for (size_t i = 0; i < cnt; i++)
			{
				float firstX = -position.x * xNum + (imageSize.x - 0.9) * i; TiledF(firstX, (imageSize.x - 0.9), cnt);
				backImg->Draw(info.hdc, firstX, -position.y * yNum + 630, imageSize.x, imageSize.y);
			}
		}
		{
			auto& backImg = ResourceManager::GetImages("bg-drago-n-mid")->at(1).img;
			//float scale = info.DrawSize.y / static_cast<float>(backImg->GetHeight()) * 0.9;
			float scale = 1;
			Vec2DF imageSize = Vec2DF
			{
				 ResourceManager::GetImages("bg-drago-n-mid")->at(1).img->GetWidth() * scale,
				  ResourceManager::GetImages("bg-drago-n-mid")->at(1).img->GetHeight() * scale
			};
			float xNum = 1;
			float yNum = 1;
			float cnt = 6;
			for (size_t i = 0; i < cnt; i++)
			{
				float firstX = -position.x * xNum + (imageSize.x - 0.9) * i; TiledF(firstX, (imageSize.x - 0.9), cnt);
				backImg->Draw(info.hdc, firstX, -position.y * yNum - 5, imageSize.x, imageSize.y);

			}

		}
	}
}


/*

void Camera::BackDraw(PaintInfo info) const
{
	{
		auto& backImg = ResourceManager::GetImages("bg-drago-back")->at(0).img;
		float scale = info.DrawSize.y / static_cast<float>(backImg->GetHeight()) * 1.05;
		Vec2DF imageSize = Vec2DF
		{
			 ResourceManager::GetImages("bg-drago-back")->at(0).img->GetWidth() * scale,
			  ResourceManager::GetImages("bg-drago-back")->at(0).img->GetHeight() * scale
		};
		float xNum = 0.5;
		float yNum = 0.15;
		float cnt = 3;
		for (size_t i = 0; i < cnt; i++)
		{
			float firstX = -position.x * xNum + (imageSize.x - 1) * i; TiledF(firstX, (imageSize.x - 1), cnt);
			backImg->Draw(info.hdc, firstX, position.y * yNum, imageSize.x, imageSize.y);
		}
	}
	{
		auto& backImg = ResourceManager::GetImages("bg-drago-tile")->at(4).img;
		float scale = info.DrawSize.y / static_cast<float>(backImg->GetHeight()) * 0.9;
		Vec2DF imageSize = Vec2DF
		{
			 ResourceManager::GetImages("bg-drago-tile")->at(0).img->GetWidth() * scale,
			  ResourceManager::GetImages("bg-drago-tile")->at(0).img->GetHeight() * scale
		};
		float xNum = 1;
		float yNum = 1;
		float cnt = 16;
		for (size_t i = 0; i < cnt; i++)
		{
			float firstX = -position.x * xNum + (imageSize.x - 0.9) * i; TiledF(firstX, (imageSize.x - 0.9), cnt);
			backImg->Draw(info.hdc, firstX, -position.y * yNum + 100, imageSize.x, imageSize.y);
		}

	}
}

void Camera::Draw(PaintInfo info) const
{
	if (true)
	{
		{
			auto& backImg = ResourceManager::GetImages("bg-drago-mid")->at(0).img;
			//float scale = info.DrawSize.y / static_cast<float>(backImg->GetHeight()) * 0.9;
			float scale = 1;
			Vec2DF imageSize = Vec2DF
			{
				 ResourceManager::GetImages("bg-drago-mid")->at(0).img->GetWidth() * scale,
				  ResourceManager::GetImages("bg-drago-mid")->at(0).img->GetHeight() * scale
			};
			float xNum = 1;
			float yNum = 1;
			float cnt = 5;
			for (size_t i = 0; i < cnt; i++)
			{
				float firstX = -position.x * xNum + (imageSize.x - 0.9) * i; TiledF(firstX, (imageSize.x - 0.9), cnt);
				backImg->Draw(info.hdc, firstX, -position.y * yNum + 510, imageSize.x, imageSize.y);
			}
		}
		{
			auto& backImg = ResourceManager::GetImages("bg-drago-mid")->at(1).img;
			//float scale = info.DrawSize.y / static_cast<float>(backImg->GetHeight()) * 0.9;
			float scale = 1;
			Vec2DF imageSize = Vec2DF
			{
				 ResourceManager::GetImages("bg-drago-mid")->at(1).img->GetWidth() * scale,
				  ResourceManager::GetImages("bg-drago-mid")->at(1).img->GetHeight() * scale
			};
			float xNum = 1;
			float yNum = 1;
			float cnt = 5;
			for (size_t i = 0; i < cnt; i++)
			{
				float firstX = -position.x * xNum + (imageSize.x - 0.9) * i; TiledF(firstX, (imageSize.x - 0.9), cnt);
				backImg->Draw(info.hdc, firstX, -position.y * yNum, imageSize.x, imageSize.y);

			}

		}
	}
}

*/