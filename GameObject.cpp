#include "pch.h"
#include "GameObject.h"

bool GameStateObject::isCollision(GameStateObject& other)
{
	return this->playerState.isCollision(other);
}

bool GameStateObject::CheckCollision(GameStateObject& other)
{
	auto& thisCol = this->playerAnime.GetCurrentCollisionData();
	auto thisPos = this->transform.Position + this->ImageMargin;
	auto& otherCol = other.playerAnime.GetCurrentCollisionData();
	auto otherPos = other.transform.Position + other.ImageMargin;
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
	return false;
}
