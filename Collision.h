#pragma once
#include "Vec2D.h"
#include "PaintInfo.h"
#include <vector>

enum class CollisionTag
{
	None,
	PlayerBody,
	PlayerAttack,
};

enum class CollisionShapeType
{
	Point,Rect,Circle
};
class GameObject;

struct CollisionResult
{
	using ResultVector = std::vector<std::pair<CollisionTag, CollisionTag>>;
	static ResultVector result;
	static bool isFalse() { return result.size() == 0; }
	static const ResultVector& GetResult() { return result; }
	static void clear() { result.clear(); }
	static void reserve(size_t size) { result.reserve(size); }
};

struct SubCollisionData
{
	CollisionShapeType shape = CollisionShapeType::Point;
	Vec2DF pos;
	Vec2DF size;
	void Draw(PaintInfo info);
	static bool CheckIntersect(const SubCollisionData& A, const SubCollisionData& B);
	static bool IntersectPointToPoint(const SubCollisionData& P1, const SubCollisionData& P2);
	static bool IntersectPointToRect(const SubCollisionData& P1, const SubCollisionData& R2);
	static bool IntersectRectToRect(const SubCollisionData& R1, const SubCollisionData& R2);
	static bool IntersectCircleToPoint(const SubCollisionData& C1, const SubCollisionData& P2);
	static bool IntersectCircleToCircle(const SubCollisionData& C1, const SubCollisionData& C2);
	static bool IntersectCircleToRect(const SubCollisionData& C1, const SubCollisionData& R2);
};

//각 2계층
class Collision
{
	std::vector<SubCollisionData> subCollision;
	const Vec2DF center;
	const float radius;
public:
	const CollisionTag tag;
	Collision(CollisionTag tag,Vec2DF center, float radius) : tag(tag), center(center), radius(radius) {};
	template <class Ty>
	Collision(CollisionTag tag,Vec2DF center, float radius, Ty&& data) : tag(tag), center(center), radius(radius), subCollision(std::forward(data)) {};
	void Draw(PaintInfo info);
	static bool CheckIntersect(const Collision& A, const Collision& B);
};
//1계층
class CollisionCollection
{
	bool isNull = false;
	std::vector<Collision> collection;
	const Vec2DF center;
	const float radius;
	CollisionCollection(bool isNull) :isNull(true), center(0, 0), radius(0) {};
public:
	CollisionCollection(Vec2DF center, float radius) : center(center), radius(radius) {};
	void AddCollision(Collision&& col);
	void Draw(PaintInfo info);
	static bool CheckIntersect(const CollisionCollection& A, const CollisionCollection& B);
	static CollisionCollection& Null();
};
//콜리전 요약
// UPDATE -> 애니메이트 프레임 계산 -> 해당 오브젝트 ANIMATE에서 해당 프레임의 콜리젼 데이터 가져와서 갱신
// 물리충돌