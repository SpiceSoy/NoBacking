#include "pch.h"
#include "Transform.h"
#include "GameFramework.h"
#include "Camera.h"


constexpr int TranslationCount = 10;

bool Transform::GetCheckMap(const Tag& tag)
{
	if (this->checkMap.find(tag) == this->checkMap.end())
	{
		return false;
	}
	else
	{
		return this->checkMap.find(tag)->second;
	}
}

void Transform::Update(float deltaTime)
{
	if (MaxJumpPower != 0)
	{
		JumpPower -= gravity*deltaTime;
		this->Translate(Vec2DF::Up() * JumpPower * deltaTime,true, 1);
	}
	if(JumpPower < MaxJumpPower)
	{
		this->Translate(Vec2DF::Up() * (JumpPower- MaxJumpPower),false, 1);
		MaxJumpPower = 0; 
		JumpPower = 0;
	}
	if (frictionPower > 0)
	{
		if (this->GetJumpState()) 
		{
			JumpFriction = true;
			frictionPower -= 1.0f * deltaTime;
			this->Translate(Vec2DF::Right() * frictionVector * (frictionPower)/5, true, 1);
		}
		else 
		{
			if (JumpFriction)
			{
				frictionPower -= frictionPower + 1;
				JumpFriction = false;
			}
			else 
			{
				frictionPower -= 10.0f * deltaTime;
				this->Translate(Vec2DF::Right() * frictionVector * (frictionPower), true, 1);
			}
		}
	}
	else 
	{
		JumpFriction = false;
	}
}

void Transform::Translate(Vec2D<Ty> vec , bool checkCol, int count)
{
	int cnt = Utill::clamp(count, 1, 5);
	for (size_t i = 0; i < cnt; i++)
	{
		auto temp = this->Position;
		this->Position += vec / cnt;
		if (checkCol)
		{
			this->framework->CheckBound(this->obj);
			if (this->Position.x < this->framework->GetCamera().GetMinPosition().x)
			{
				this->Position.x = temp.x;
			}
		}
	}
}

void Transform::Jump(float power)
{
	if (this->MaxJumpPower == 0)
	{
		this->JumpPower = power;
		MaxJumpPower = this->JumpPower * -1;
	}
}

void Transform::KnockBack(const Vec2DF vector)
{
	frictionPower = abs(vector.x);
	frictionVector = (vector.x>0)?(1):(-1);
	if (vector.y != 0)
	{
		if (this->GetJumpState())
		{
			JumpPower += -vector.y;
		}
		else 
		{
			this->Jump(-vector.y);
		}
	}
}

void Transform::SetY(float pos)
{
	this->Position.y = pos;
}

void Transform::SetCheckMap(const Tag& tag, bool checkCollision)
{
	this->checkMap[tag] = checkCollision;
}

bool Transform::CheckCollision(Transform& other)
{
	auto thisRect = RectF(this->Position, this->Size.x, this->Size.y);
	auto otherRect = RectF(other.Position, other.Size.x, other.Size.y);
	return thisRect.isCollision(otherRect);
}

