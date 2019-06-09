#pragma once
#include "Vec2D.h"
#include "PaintInfo.h"
#include <vector>
#include <string>

//
//enum class CollisionTag
//{
//	None,
//	PlayerBody,
//	PlayerAttack,
//};
using CollisionTag = std::string;

enum class CollisionShapeType
{
	Point,Rect,Circle
};
class GameStateObject;

struct CollisionResult
{
	using ResultVector = std::vector<std::pair<CollisionTag, CollisionTag>>;
	static ResultVector result;
	static ResultVector reverseResult;
	static std::pair<const GameStateObject*, const GameStateObject*> AB;
	static bool isFalse() { return result.size() == 0; }
	static const ResultVector& GetResult(GameStateObject* id) 
	{
		if (AB.first == id)
		{
			return result;
		}
		else if((AB.second == id))
		{
			return reverseResult; 
		}
		else 
		{
			assert(false);
		}
	}
	static void clear() { result.clear(); reverseResult.clear(); }
	static void reserve(size_t size) { result.reserve(size); reverseResult.reserve(size);}
};

struct SubCollisionData
{
	CollisionShapeType shape = CollisionShapeType::Point;
	Vec2DF pos;
	Vec2DF size;
	void Draw(PaintInfo info, const Vec2DF& parentPos) const;
	static bool CheckIntersect(const SubCollisionData& A, const Vec2DF& APos, const SubCollisionData& B, const Vec2DF& BPos);
	static bool IntersectPointToPoint(const SubCollisionData& P1, const Vec2DF& P1Pos, const SubCollisionData& P2, const Vec2DF& P2Pos);
	static bool IntersectPointToRect(const SubCollisionData& P1, const Vec2DF& P1Pos, const SubCollisionData& R2, const Vec2DF& R2Pos);
	static bool IntersectRectToRect(const SubCollisionData& R1, const Vec2DF& R1Pos, const SubCollisionData& R2, const Vec2DF& R2Pos);
	static bool IntersectCircleToPoint(const SubCollisionData& C1, const Vec2DF& C1Pos, const SubCollisionData& P2, const Vec2DF& P12os);
	static bool IntersectCircleToCircle(const SubCollisionData& C1, const Vec2DF& C1Pos, const SubCollisionData& C2, const Vec2DF& C2Pos);
	static bool IntersectCircleToRect(const SubCollisionData& C1, const Vec2DF& C1Pos, const SubCollisionData& R2, const Vec2DF& R2Pos);
};

//각 2계층
class Collision
{
	std::vector<SubCollisionData> subCollision;
public:
	Vec2DF center;
	float radius;
	const CollisionTag tag;
	void AddCollision(SubCollisionData& col);
	void AddCollision(SubCollisionData&& col);
	Collision(CollisionTag tag,Vec2DF center, float radius) : tag(tag), center(center), radius(radius) {};
	Collision(CollisionTag tag,Vec2DF center, float radius, std::vector<SubCollisionData>&& data) : tag(tag), center(center), radius(radius), subCollision(std::move(data)) {};
	void Draw(PaintInfo info , const Vec2DF& parentPos) const;
	static bool CheckIntersect(const Collision& A, const Vec2DF& APos, const Collision& B, const Vec2DF& BPos);
	Vec2DF GetFirstCenter() const { return subCollision[0].pos; }
};
//1계층
class CollisionCollection
{
	bool isNull = false;
	std::vector<Collision> collection;
	Vec2DF center;
	float radius;
	int boundIndex = -1;
	CollisionCollection(bool isNull) :isNull(true), center(0, 0), radius(0) {};
public:
	CollisionCollection(Vec2DF center, float radius) : center(center), radius(radius) {};
	CollisionCollection(const std::string dir, float scale = 0.0f) { this->Load(dir,scale); };
	void AddCollision(Collision& col);
	void AddCollision(Collision&& col);
	void Draw(PaintInfo info , const Vec2DF& parentPos) const;
	Vec2DF GetBoundCenter() const 
	{
		return (boundIndex != -1) ? (this->collection[boundIndex].GetFirstCenter()) : (Vec2DF{0,0});
	};
	static bool CheckIntersect(const CollisionCollection& A, const Vec2DF& APos, const  GameStateObject* Aptr, const CollisionCollection& B, const Vec2DF& BPos, const  GameStateObject* Bptr);
	static CollisionCollection& Null();
	void Load(const std::string& dir,float scale = 0.0f);
};
//콜리전 요약
// UPDATE -> 애니메이트 프레임 계산 -> 해당 오브젝트 ANIMATE에서 해당 프레임의 콜리젼 데이터 가져와서 갱신
// 물리충돌