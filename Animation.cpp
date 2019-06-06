#include "pch.h"
#include "Animation.h"
#include "ResourceManager.h"


void Animation::ChangeState(CharacterNormalState state, bool reset)
{
	assert(this->motionData->count(state) == 1);
	if (this->thisState != state || reset || isEnd())
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
		float scale = (*motionData)[thisState].scale;
		thisTime += scale * deltaTime;
		if (thisTime > (*motionData)[thisState].subImageSize * frameTime)
		{
			switch ((*motionData)[thisState].next)
			{
			case CharacterNormalState::None: thisTime -= scale * deltaTime; this->isActive = false; break;
			case CharacterNormalState::LOOP: 
			{
				while (thisTime > (*motionData)[thisState].subImageSize * frameTime)
				{
					thisTime -= ((*motionData)[thisState].subImageSize * frameTime);
				}
			} break;
			default:
				this->ChangeState((*motionData)[thisState].next);
				break;
			}

		}
	}
	//현재 프레임 계산
}

bool Animation::isChangeFrame()
{
	if (this->frameImageData->size() == 1)
	{
		return true;
	}
	if (motionData->empty())
	{
		if (lastIndex != 0)
		{
			lastIndex = 0;
			return true;
		}
		else 
		{
			return false;
		}
	}
	else
	{
		auto ani = this->GetCurrentAnimation();
		if (lastIndex != static_cast<int>(ani.subImageStartIndex + thisTime / (frameTime)))
		{
			lastIndex = ani.subImageStartIndex + thisTime / (frameTime);
			return true;
		}
		else
		{
			return false;
		}
	}
}

const subImage& Animation::GetCurrentImage() const
{
	if (motionData->empty())
	{
		return this->frameImageData->at(0);
	}
	else 
	{
		auto ani = this->GetCurrentAnimation();
		return this->frameImageData->at(ani.subImageStartIndex + thisTime / (frameTime));
	}
}

subAnimation Animation::GetCurrentAnimation() const
{
	return motionData->at(thisState);
}

void Animation::SetCollision(CollisionCollectionContainer* data)
{
	this->frameCollision = data;
}

void Animation::SetImageSet(ImageSetContainer* data)
{
	this->frameImageData = data;
}
void Animation::SetMotionSet(MotionContainer* data)
{
	this->motionData = data;
}

void Animation::Set(const std::string& tag)
{
	this->SetImageSet(ResourceManager::GetImages(tag));
	this->SetMotionSet(ResourceManager::GetMotion(tag));
	this->SetCollision(ResourceManager::GetCollision(tag));
}

void Animation::Set(const std::string& imgTag, const std::string& motionTag, const std::string& colTag)
{
	this->SetImageSet(ResourceManager::GetImages(imgTag));
	this->SetMotionSet(ResourceManager::GetMotion(motionTag));
	this->SetCollision(ResourceManager::GetCollision(colTag));
}

bool Animation::isEnd(CharacterNormalState state) const
{
	if (state == CharacterNormalState::THISMOTION) { return this->isActive == false; }
	return (this->thisState == state && this->isActive == false);
}

float Animation::GetTotalTime(CharacterNormalState state) const
{
	if (state == CharacterNormalState::THISMOTION) { state = this->thisState; }
	return motionData->at(state).subImageSize * Animation::frameTime / motionData->at(state).scale;
}

int Animation::GetCurrentFrame() const
{
	if (motionData->empty())
	{
		return 0;
	}
	else
	{
		return thisTime / (frameTime);
	}
}

CharacterNormalState Animation::GetThisState() const
{
	return this->thisState;
}

const CollisionCollection& Animation::GetCurrentCollisionData() const
{
	if (frameCollision == nullptr || frameCollision->empty())
	{
		return CollisionCollection::Null();
	}
	if (motionData == nullptr || motionData->empty())
	{
		return CollisionCollection::Null();
		//return this->frameCollision->at(0);
	}
	else
	{
		auto ani = this->GetCurrentAnimation();
		if (this->frameCollision->size() > ani.subImageStartIndex + thisTime / (frameTime))
		{
			return this->frameCollision->at(ani.subImageStartIndex + thisTime / (frameTime));
		}
		else 
		{
			return CollisionCollection::Null();
		}
	}
}
