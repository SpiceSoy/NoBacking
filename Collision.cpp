#include "pch.h"
#include "Collision.h"


CollisionResult::ResultVector CollisionResult::result = CollisionResult::ResultVector();

void Collision::Draw(PaintInfo info)
{
	auto old = SelectObject(info.hdc, info.CollisionPen[1]);
	auto rt = RectF(this->center, radius);
	Ellipse(info.hdc, rt.left, rt.top, rt.right, rt.bottom);
	SelectObject(info.hdc, old);
}

bool Collision::CheckIntersect(const Collision& A, const Collision& B)
{
	auto dist = (A.center - B.center).GetScaleSq();
	auto r1 = abs(A.radius);
	auto r2 = abs(B.radius);
	if (dist <= pow(r1 + r2, 2))
	{
		for (auto a = A.subCollision.cbegin(); a != A.subCollision.cend(); a++)
		{
			for (auto b = B.subCollision.cbegin(); b != B.subCollision.cend(); b++)
			{
				if (SubCollisionData::CheckIntersect(*a, *b)) { return true; }
			}
		}
	}
	return false;
}

void CollisionCollection::AddCollision(Collision&& col)
{
	this->collection.emplace_back(std::move(col));
}

void CollisionCollection::Draw(PaintInfo info)
{
	auto old = SelectObject(info.hdc, info.CollisionPen[0]);
	auto rt = RectF(this->center, radius);
	Ellipse(info.hdc, rt.left, rt.top, rt.right, rt.bottom);
	SelectObject(info.hdc, old);
}

bool CollisionCollection::CheckIntersect(const CollisionCollection& A, const CollisionCollection& B)
{
	bool Check = false;
	auto dist = (A.center - B.center).GetScaleSq();
	auto r1 = abs(A.radius);
	auto r2 = abs(B.radius);
	if (dist <= pow(r1 + r2, 2) && !A.isNull && !B.isNull)
	{
		for (auto a = A.collection.cbegin(); a != A.collection.cend(); a++)
		{
			for (auto b = B.collection.cbegin(); b != B.collection.cend(); b++)
			{
				if (Collision::CheckIntersect(*a, *b)) 
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
