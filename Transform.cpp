#include "pch.h"
#include "Transform.h"
#include "GameFramework.h"


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
		this->Translate(Vec2DF::Up() * JumpPower * deltaTime,1);
	}
	if(JumpPower < MaxJumpPower)
	{
		MaxJumpPower = 0;
		JumpPower = 0;
	}
}

void Transform::Translate(Vec2D<Ty> vec , bool checkCol, int count)
{
	int cnt = Utill::clamp(count, 1, 5);
	for (size_t i = 0; i < cnt; i++)
	{
		this->Position += vec / cnt;
		if (checkCol && this->framework->CheckCollision(this->obj))
		{
			this->Position -= vec / cnt; break; 
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

