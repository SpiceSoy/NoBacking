#include "pch.h"
#include "Animation.h"

subImage::subImage(const std::wstring& image)
{
	this->img.Load(image.c_str());
}

void Animation::ChangeState(CharacterState state)
{
	assert(this->motionData.count(state) == 1);
	if (this->thisState != state)
	{
		this->isActive = true;
		this->thisState = state;
		this->thisTime = 0;
	}
}

void Animation::Update(float deltaTime)
{
	if (this->isActive == true)
	{
		float scale = motionData[thisState].scale;
		thisTime += scale * deltaTime;
		if (thisTime > motionData[thisState].subImageSize * frameTime)
		{
			switch (motionData[thisState].next)
			{
			case CharacterState::None: thisTime -= scale * deltaTime; this->isActive = true; break;
			case CharacterState::LOOP: 
			{
				while (thisTime > motionData[thisState].subImageSize * frameTime)
				{
					thisTime -= (motionData[thisState].subImageSize * frameTime);
				}
			} break;
			default:
				this->ChangeState(motionData[thisState].next);
				break;
			}

		}
	}
	//현재 프레임 계산
}

const subImage& Animation::GetCurrentImage() const
{
	if (frameImageData.empty())
	{
		return this->frameImageData.at(0);
	}
	else 
	{
		auto ani = this->GetCurrentAnimation();
		return this->frameImageData.at(ani.subImageStartIndex + thisTime / (frameTime));
	}
}

subAnimation Animation::GetCurrentAnimation() const
{
	return motionData.at(thisState);
}

void Animation::AddImage(subImage image)
{
	this->frameImageData.push_back(image);
}
void Animation::AddImage(const std::wstring& dir)
{
	this->frameImageData.emplace_back(dir);
}

void Animation::AddMotion(CharacterState state, subAnimation motion)
{
	this->motionData[state] = motion;
}
