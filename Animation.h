#pragma once
#include <vector>
#include <Windows.h>
#include <unordered_map>
#include <atlimage.h>
#include "Vec2D.h"
#include "Rect.h"
#include "StateEnum.h"
#include "AnimatedCollisionData.h"


constexpr float frameTime = (1000.f / 60.f)/250.f;
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
	CharacterState next = CharacterState::LOOP;
};

class Animation
{
	float thisTime;
	bool isActive = true;
	CharacterState thisState;
	std::vector<subImage> frameImageData;
	std::vector<std::vector<AnimatedCollisionData>> frameCollisionData;
	std::unordered_map<CharacterState,subAnimation> motionData;
public:
	void ChangeState(CharacterState state);
	void Update(float deltaTime);
	const subImage& GetCurrentImage() const;
	subAnimation GetCurrentAnimation() const;
	void AddImage(subImage image);
	void AddImage(const std::wstring& image);
	void AddMotion(CharacterState state, subAnimation motion);
	void ReSize(size_t cnt) { this->frameImageData.reserve(cnt); }
	//subImage GetCurrentCollisionData() const;

};