#include "pch.h"
#include "GameObject.h"
#include "GameFramework.h"

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
		if (this->framework->GetOnePunchMan())
		{
			hp *= 10000;
		}
		this->hp = Utill::clamp(this->hp - hp, 0, INT_MAX);
		if (!off) { this->isCanDamaged = false; }
	}
}

void GameStateObject::ResetDamageCounter()
{
	this->isCanDamaged = true;
}

bool GameStateObject::CheckBound(GameStateObject& other, bool justCheck)
{
	if (isActive && other.GetActiveState())
	{
		auto& thisCol = this->playerAnime.GetCurrentCollisionData();
		auto thisPos = this->transform.Position;
		auto& otherCol = other.playerAnime.GetCurrentCollisionData();
		auto otherPos = other.transform.Position;
		//if (this->playerAnime.isChangeFrame() || other.playerAnime.isChangeFrame())
		{
			if (CollisionCollection::CheckIntersect(thisCol, thisPos, this, otherCol, otherPos, &other))
			{
				auto& result = CollisionResult::GetResult(this);
				for (auto& res : result)
				{
					if (res.first == res.second && res.first == "bound")
					{
						while (!justCheck && this->CheckBound(other,true))
						{
							this->transform.Position.x += ((this->transform.Position + this->GetThisBoundingCenter()) - (other.transform.Position + other.GetThisBoundingCenter())).x * 0.05;
						}
						return true;
					}
				}
			}
			else
			{
				return false;
			}
		}
	}
	return false;
}
