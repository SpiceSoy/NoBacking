#include "pch.h"
#include "Collision.h"
#include "Vec2D.h"


CollisionResult::ResultVector CollisionResult::result = CollisionResult::ResultVector();

void Collision::AddCollision(SubCollisionData& col)
{
	this->subCollision.push_back((col));
}
void Collision::AddCollision(SubCollisionData&& col)
{
	this->subCollision.emplace_back(std::move(col));
}

void Collision::Draw(PaintInfo info, const Vec2DF& parentPos) const
{
	auto old = SelectObject(info.hdc, info.CollisionPen[1]);
	auto rt = RectF(this->center + parentPos, radius);
	Ellipse(info.hdc, rt.left, rt.top, rt.right, rt.bottom);
	SelectObject(info.hdc, old);
	for (auto& subC : this->subCollision)
	{
		subC.Draw(info, parentPos);
	}
}

bool Collision::CheckIntersect(const Collision& A, const Vec2DF& APos, const Collision& B, const Vec2DF& BPos)
{
	auto dist = ((A.center + APos) - (B.center - BPos)).GetScaleSq();
	auto r1 = abs(A.radius);
	auto r2 = abs(B.radius);
	if (dist <= pow(r1 + r2, 2))
	{
		for (auto a = A.subCollision.cbegin(); a != A.subCollision.cend(); a++)
		{
			for (auto b = B.subCollision.cbegin(); b != B.subCollision.cend(); b++)
			{
				if (SubCollisionData::CheckIntersect(*a, APos, *b, BPos)) { return true; }
			}
		}
	}
	return false;
}

void CollisionCollection::AddCollision(Collision& col)
{
	this->collection.push_back((col));
}
void CollisionCollection::AddCollision(Collision&& col)
{
	this->collection.emplace_back(std::move(col));
}

void CollisionCollection::Draw(PaintInfo info , const Vec2DF& parentPos) const
{

	auto old = SelectObject(info.hdc, info.CollisionPen[0]);
	auto oldBr = SelectObject(info.hdc,GetStockObject(NULL_BRUSH));
	auto rt = RectF(this->center + parentPos, radius);
	Ellipse(info.hdc, rt.left, rt.top, rt.right, rt.bottom);
	SelectObject(info.hdc, old);
	for (auto& subC : this->collection)
	{
		subC.Draw(info, parentPos);
	}
	SelectObject(info.hdc, oldBr);
}

bool CollisionCollection::CheckIntersect(const CollisionCollection& A, const Vec2DF& APos, const CollisionCollection& B, const Vec2DF& BPos)
{
	bool Check = false;
	auto dist = ((A.center + APos) - (B.center+BPos)).GetScaleSq();
	auto r1 = abs(A.radius);
	auto r2 = abs(B.radius);
	if (dist <= pow(r1 + r2, 2) && !A.isNull && !B.isNull)
	{
		for (auto a = A.collection.cbegin(); a != A.collection.cend(); a++)
		{
			for (auto b = B.collection.cbegin(); b != B.collection.cend(); b++)
			{
				if (Collision::CheckIntersect(*a,APos, *b,BPos)) 
				{
					if (!Check) 
					{
						CollisionResult::clear();
						Check = true;
					}
					CollisionResult::result.push_back(std::make_pair(a->tag, b->tag));
				}
			}
		}
	}
	return Check;
}

CollisionCollection& CollisionCollection::Null()
{
	static CollisionCollection nullObj(true);
	return nullObj;
}
