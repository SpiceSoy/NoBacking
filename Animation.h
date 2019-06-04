#pragma once
#include <vector>
#include <Windows.h>
#include <unordered_map>
#include <atlimage.h>
#include "Vec2D.h"
#include "Rect.h"
#include "StateEnum.h"
#include "Collision.h"
#include "ResourceManager.h"


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
	int lastIndex = -1;
	bool isActive = true;
	CharacterNormalState thisState;
	std::vector<subImage>* frameImageData = nullptr;
	std::vector<CollisionCollection>* frameCollision = nullptr;
	std::unordered_map<CharacterNormalState,subAnimation> motionData;
public:
	void ChangeState(CharacterNormalState state , bool reset = false);
	void Update(float deltaTime);
	bool isChangeFrame();
	const subImage& GetCurrentImage() const;
	subAnimation GetCurrentAnimation() const;
	void SetCollision(std::vector<CollisionCollection>* data);
	void SetImageSet(std::vector<subImage>* data);
	void Set(const std::string& tag);
	void Set(const std::string& imgTag, const std::string& colTag);
	void AddMotion(CharacterNormalState state, subAnimation motion);
	bool isEnd(CharacterNormalState state = CharacterNormalState::THISMOTION) const;
	float GetTotalTime(CharacterNormalState state) const;
	const CollisionCollection& GetCurrentCollisionData() const;

};