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
//�ݸ��� ���
// UPDATE -> �ִϸ���Ʈ ������ ��� -> �ش� ������Ʈ ANIMATE���� �ش� �������� �ݸ��� ������ �����ͼ� ����
// �����浹