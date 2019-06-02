#include "pch.h"
#include "Collision.h"
#include "Vec2D.h"

#include <fstream>
#include <algorithm>


CollisionResult::ResultVector CollisionResult::result = CollisionResult::ResultVector();
CollisionResult::ResultVector CollisionResult::reverseResult = CollisionResult::ResultVector();
std::pair<const GameStateObject*, const GameStateObject*> CollisionResult::AB = { nullptr,nullptr };
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
	auto dist = ((A.center + APos) - (B.center + BPos)).GetScaleSq();
	auto r1 = abs(A.radius/2);
	auto r2 = abs(B.radius/2);
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

bool CollisionCollection::CheckIntersect(const CollisionCollection& A, const Vec2DF& APos,const  GameStateObject* Aptr, const CollisionCollection& B, const Vec2DF& BPos, const  GameStateObject* Bptr)
{
	bool Check = false;
	auto dist = ((A.center + APos) - (B.center+BPos)).GetScaleSq();
	auto r1 = abs(A.radius/2);
	auto r2 = abs(B.radius/2);
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
						CollisionResult::AB.first = Aptr;
						CollisionResult::AB.second = Bptr;
					}
					CollisionResult::result.push_back(std::make_pair(a->tag, b->tag));
					CollisionResult::reverseResult.push_back(std::make_pair(b->tag, a->tag));
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

void CollisionCollection::Load(const std::string& dir)
{
	std::ifstream ifs(dir);
	std::string imgdir;
	float imgPivotX;
	float imgPivoty;
	if (!ifs.eof())
	{
		ifs >> imgdir >> imgPivotX >> imgPivoty;
		int CollisionCount = 0;
		ifs >> this->center.x >> this->center.y >> this->radius >> CollisionCount;
		for (int i = 0; i < CollisionCount; i++)
		{
			CollisionTag tag;
			Vec2DF colPos;
			float colRadius;
			int subCollisionCount = 0;
			ifs >> tag >> colPos.x >> colPos.y >> colRadius >> subCollisionCount;
			std::transform(tag.begin(), tag.end(), tag.begin(), tolower);

			std::vector<SubCollisionData> subColldata;
			for (size_t i = 0; i < subCollisionCount; i++)
			{
				SubCollisionData subData;
				int type;
				ifs >> type >> subData.pos.x >> subData.pos.y >> subData.size.x >> subData.size.y;
				subData.shape = static_cast<CollisionShapeType>(type);
				subColldata.push_back(subData);
			}
			auto col = Collision(tag, colPos, colRadius,std::move(subColldata));
			this->collection.push_back(std::move(col));
		}
	}
}
