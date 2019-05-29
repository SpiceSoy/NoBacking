#include "pch.h"
#include "Collision.h"

void SubCollisionData::Draw(PaintInfo info)
{
	auto old = SelectObject(info.hdc,info.CollisionPen[2]);
	switch (this->shape)
	{
	case CollisionShapeType::Circle:
	{
		auto rt = RectF(this->pos, this->size.x);
		Ellipse(info.hdc, rt.left, rt.top, rt.right, rt.bottom);
	}
		break;
	case CollisionShapeType::Point:
	{
		auto rt = RectF(this->pos, 2);
		Ellipse(info.hdc, rt.left, rt.top, rt.right, rt.bottom);
	}
		break;
	case CollisionShapeType::Rect:
	{
		auto rt = RectF(this->pos, this->size.x,this->size.y);
		Rectangle(info.hdc, rt.left, rt.top, rt.right, rt.bottom);
	}
		break;
	}
	SelectObject(info.hdc, old);
}

bool SubCollisionData::CheckIntersect(const SubCollisionData& A, const SubCollisionData& B)
{
	switch (A.shape)
	{
		case CollisionShapeType::Circle:
		{
			switch (B.shape)
			{
			case CollisionShapeType::Circle:
				return SubCollisionData::IntersectCircleToCircle(A,B);
			case CollisionShapeType::Point:
				return SubCollisionData::IntersectCircleToPoint(A,B);
			case CollisionShapeType::Rect:
				return SubCollisionData::IntersectCircleToRect(A,B);
			}
		}
			break;
		case CollisionShapeType::Point: 
		{
			switch (B.shape)
			{
			case CollisionShapeType::Circle: return SubCollisionData::IntersectCircleToPoint(B,A);
			case CollisionShapeType::Point: return SubCollisionData::IntersectPointToPoint(A,B);
			case CollisionShapeType::Rect: return SubCollisionData::IntersectPointToRect(A,B);
			}
		}
			break;
		case CollisionShapeType::Rect: 
		{
			switch (B.shape)
			{
			case CollisionShapeType::Circle: return SubCollisionData::IntersectCircleToRect(B,A);
			case CollisionShapeType::Point: return SubCollisionData::IntersectPointToRect(B,A);
			case CollisionShapeType::Rect: return SubCollisionData::IntersectRectToRect(A,B);
			}
		}
	}
}

bool SubCollisionData::IntersectPointToPoint(const SubCollisionData& P1, const SubCollisionData& P2)
{
	assert(P1.shape == CollisionShapeType::Point && P2.shape == CollisionShapeType::Point);
	return Utill::approximation(P1.pos.x, P2.pos.x) && Utill::approximation(P1.pos.y, P2.pos.y);
}

bool SubCollisionData::IntersectPointToRect(const SubCollisionData& P1, const SubCollisionData& R2)
{
	assert(P1.shape == CollisionShapeType::Point && R2.shape == CollisionShapeType::Rect);
	auto rt = RectF(R2.pos, R2.size.x, R2.size.y);
	return rt.hasIn(P1.pos);
}

bool SubCollisionData::IntersectRectToRect(const SubCollisionData& R1, const SubCollisionData& R2)
{
	assert(R1.shape == CollisionShapeType::Rect && R2.shape == CollisionShapeType::Rect);
	auto rt1 = RectF(R1.pos, R1.size.x, R1.size.y);
	auto rt2 = RectF(R2.pos, R2.size.x, R2.size.y);

	return rt1.isCollision(rt2);
}

bool SubCollisionData::IntersectCircleToPoint(const SubCollisionData& C1, const SubCollisionData& P2)
{
	assert(C1.shape == CollisionShapeType::Circle && P2.shape == CollisionShapeType::Point);
	auto r = abs(C1.size.x);
	return (P2.pos - C1.pos).GetScaleSq() <= r*r;
}
bool SubCollisionData::IntersectCircleToCircle(const SubCollisionData& C1, const SubCollisionData& C2)
{
	assert(C1.shape == CollisionShapeType::Circle && C2.shape == CollisionShapeType::Circle);
	auto dist = (C2.pos - C1.pos).GetScaleSq();
	auto r1 = abs(C1.size.x);
	auto r2 = abs(C1.size.x);
	return dist <= pow(r1+r2,2);
}
bool SubCollisionData::IntersectCircleToRect(const SubCollisionData& C1, const SubCollisionData& R2)
{
	assert(C1.shape == CollisionShapeType::Circle && R2.shape == CollisionShapeType::Rect);
	auto rt = RectF(R2.pos, R2.size.x, R2.size.y);
	auto r = abs(C1.size.x);

	bool rt1 = RectF(R2.pos, R2.size.x + 2 * r, R2.size.y).hasIn(C1.pos);
	bool rt2 = RectF(R2.pos, R2.size.x, R2.size.y + 2 * r).hasIn(C1.pos);
	bool secTL = ((C1.pos - Vec2DF{rt.top, rt.left}).GetScaleSq() <= r * r);
	bool secTR = ((C1.pos - Vec2DF{rt.top, rt.right}).GetScaleSq() <= r * r);
	bool secBL = ((C1.pos - Vec2DF{rt.bottom, rt.left}).GetScaleSq() <= r * r);
	bool secBR = ((C1.pos - Vec2DF{rt.bottom, rt.right }).GetScaleSq() <= r * r);

	return rt1 || rt2 || secTL || secTR || secBL || secBR;
}