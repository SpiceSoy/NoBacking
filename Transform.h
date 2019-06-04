#pragma once
#include <array>
#include <Windows.h>
#include <unordered_map>
#include <map>
#include <string>

#include "IFrameworkObject.h"
#include "Vec2D.h"
#include "Rect.h"


using Tag = std::string;
class GameStateObject;

class Transform : public IFrameworkObject
{
	static constexpr float gravity = 9.8f * 100;
	using Ty = float;
	//태그간의 충돌 관계 지정
	GameStateObject& obj;
	std::map<Tag, bool> checkMap;
	float MaxJumpPower = 0;
	float JumpPower = 0;
	float frictionPower = 0;
	int frictionVector = 0;
public:
	Transform(GameStateObject& obj, GameFramework* framework) : obj(obj), IFrameworkObject(framework) {};
	Vec2D<Ty> Position = Vec2D<Ty>{ 0, 0 };
	Vec2D<Ty> Size = Vec2D<Ty>{ 0,0 };
	Vec2D<Ty> Scale = Vec2D<Ty>{ 1,1 };
	Ty Roation = 0.0f;
	void Update(float deltaTime);
	void Translate(Vec2D<Ty> vec,bool checkCol = true, int count = 4);
	void Jump(float power);
	void KnockBack(const Vec2DF vector);
	void SetY(float pos);
	bool CheckCollision(Transform& other);
	bool GetCheckMap(const Tag& tag);
	void SetCheckMap(const Tag& tag, bool checkCollision);
	bool GetJumpState() const { return this->MaxJumpPower != 0; }
	float GetJumpPower() const { return this->JumpPower; }
	//std::array<POINT, 3> GetRotatedRect();

};