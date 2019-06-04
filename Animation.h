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




class Animation
{
	static constexpr float frameTime = (1000.f / 60.f) / 250.f;
	float thisTime;
	int lastIndex = -1;
	bool isActive = true;
	CharacterNormalState thisState;
	std::vector<subImage>* frameImageData = nullptr;
	std::vector<CollisionCollection>* frameCollision = nullptr;
	std::unordered_map<CharacterNormalState,subAnimation>* motionData = nullptr;
public:
	void ChangeState(CharacterNormalState state , bool reset = false);
	void Update(float deltaTime);
	bool isChangeFrame();
	const subImage& GetCurrentImage() const;
	subAnimation GetCurrentAnimation() const;
	void SetCollision(CollisionCollectionContainer* data);
	void SetImageSet(ImageSetContainer* data);
	void SetMotionSet(MotionContainer* data);
	void Set(const std::string& tag);
	void Set(const std::string& imgTag, const std::string& motionTag, const std::string& colTag);
	bool isEnd(CharacterNormalState state = CharacterNormalState::THISMOTION) const;
	float GetTotalTime(CharacterNormalState state = CharacterNormalState::THISMOTION) const;
	int GetCurrentFrame() const;
	CharacterNormalState GetThisState() const;
	const CollisionCollection& GetCurrentCollisionData() const;

};