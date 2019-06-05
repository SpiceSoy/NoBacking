#include "pch.h"
#include "GameObject.h"

bool GameStateObject::isCollision(GameStateObject& other)
{
	if (isActive)
	{
		return this->playerState.isCollision(other);
	}
	else 
	{
		return false;
	}
}

bool GameStateObject::CheckCollision(GameStateObject& other)
{
	if (isActive)
	{
		auto& thisCol = this->playerAnime.GetCurrentCollisionData();
		auto thisPos = this->transform.Position;
		auto& otherCol = other.playerAnime.GetCurrentCollisionData();
		auto otherPos = other.transform.Position;
		if (this->playerAnime.isChangeFrame() || other.playerAnime.isChangeFrame())
		{
			if (CollisionCollection::CheckIntersect(thisCol, thisPos, this, otherCol, otherPos, &other))
			{
				bool ret = false;
				ret |= this->isCollision(other);
				ret |= other.isCollision(*this);
				return ret;
			}
			else
			{
				return false;
			}
		}
	}
	return false;
}

void GameStateObject::Damaged(int hp , bool off)
{
	if (isCanDamaged)
	{
		this->hp = Utill::clamp(this->hp - hp, 0, INT_MAX);
		if (!off) { this->isCanDamaged = false; }
	}
}

void GameStateObject::ResetDamageCounter()
{
	this->isCanDamaged = true;
}
