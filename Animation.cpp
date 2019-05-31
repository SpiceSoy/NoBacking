#include "pch.h"
#include "Animation.h"

subImage::subImage(const std::wstring& image)
{
	this->img.Load(image.c_str());
}

void Animation::ChangeState(CharacterNormalState state, bool reset)
{
	assert(this->motionData.count(state) == 1);
	if (this->thisState != state || reset)
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
			case CharacterNormalState::None: thisTime -= scale * deltaTime; this->isActive = false; break;
			case CharacterNormalState::LOOP: 
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
	if (motionData.empty())
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

void Animation::AddCollision(CollisionCollection& col)
{
	this->frameCollision.push_back(col);
}
void Animation::AddCollision(CollisionCollection&& col)
{
	this->frameCollision.emplace_back(std::move(col));
}

void Animation::AddMotion(CharacterNormalState state, subAnimation motion)
{
	this->motionData[state] = motion;
}

bool Animation::isEnd(CharacterNormalState state) const
{
	return (this->thisState == state && this->isActive == false);
}

float Animation::GetTotalTime(CharacterNormalState state) const
{
	return motionData.at(state).subImageSize* motionData.at(state).scale * Animation::frameTime;
}

const CollisionCollection& Animation::GetCurrentCollisionData() const
{
	if (frameCollision.empty())
	{
		return CollisionCollection::Null();
	}
	if (motionData.empty())
	{
		return this->frameCollision.at(0);
	}
	else
	{
		auto ani = this->GetCurrentAnimation();
		if (this->frameCollision.size() > ani.subImageStartIndex + thisTime / (frameTime))
		{
			return this->frameCollision.at(ani.subImageStartIndex + thisTime / (frameTime));
		}
		else 
		{
			return CollisionCollection::Null();
		}
	}
}
