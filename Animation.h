#pragma once
#include <vector>
#include <Windows.h>
#include <unordered_map>
#include <atlimage.h>
#include "Vec2D.h"
#include "Rect.h"
#include "StateEnum.h"
#include "Collision.h"


struct subImage
{
	CImage img;
	subImage(const std::wstring& image);
	//HBITMAP bitmap;
	//RectU size;
	//subImage(const subImage& other);
};
struct subAnimation
{
	size_t subImageStartIndex = 0;
	size_t subImageSize = 0;
	float scale = 1.0f;
	CharacterNormalState next = CharacterNormalState::LOOP;
};

class Animation
{
	static constexpr float frameTime = (1000.f / 60.f) / 250.f;
	float thisTime;
	bool isActive = true;
	CharacterNormalState thisState;
	std::vector<subImage> frameImageData;
	std::vector<CollisionCollection> frameCollision;
	std::unordered_map<CharacterNormalState,subAnimation> motionData;
public:
	void ChangeState(CharacterNormalState state , bool reset = false);
	void Update(float deltaTime);
	const subImage& GetCurrentImage() const;
	subAnimation GetCurrentAnimation() const;
	void AddImage(subImage image);
	void AddImage(const std::wstring& image);
	void AddCollision(CollisionCollection& col);
	void AddCollision(CollisionCollection&& col);
	void AddCollision(const std::string& dir);
	void AddMotion(CharacterNormalState state, subAnimation motion);
	void ReSize(size_t cnt) { this->frameImageData.reserve(cnt); }
	bool isEnd(CharacterNormalState state) const;
	float GetTotalTime(CharacterNormalState state) const;
	const CollisionCollection& GetCurrentCollisionData() const;

};