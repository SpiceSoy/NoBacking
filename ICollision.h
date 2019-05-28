#pragma once
#include "Vec2D.h"
enum class CollisionType
{
	Point,Rect,Circle
};
class GameObject;
class Collision
{
	CollisionType type;
	GameObject& gameObject;
	Vec2DF center;
	Vec2DF size;
public:
	Collision(GameObject& gameObjcet) : gameObject(gameObject) {}
	CollisionType GetType() const { return type; }
	virtual bool CheckIntersect() = 0;
};
//콜리전 요약
// UPDATE -> 애니메이트 프레임 계산 -> 해당 오브젝트 ANIMATE에서 해당 프레임의 콜리젼 데이터 가져와서 갱신
// 물리충돌