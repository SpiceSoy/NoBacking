#pragma once
#include "Vec2D.h"
class Camera
{
	Vec2DF minPosition = Vec2DF{-1000,0};
	Vec2DF maxPosition = Vec2DF{7300,800};
	Vec2DF position = Vec2DF{ 0.0f,0.0f };
	float Scale = 1.0f;
public:
	Vec2DF CameraTransform(const Vec2DF& transform) const;
	void Lerp(Vec2DF other, float t);
	void Move(Vec2DF vec);
	void Teleport(Vec2DF vec);
	void clamp();
	void BackDraw(PaintInfo info) const;
	void Draw(PaintInfo info) const;
	Vec2DF GetMaxPosition() const { return maxPosition; };
	Vec2DF GetMinPosition() const { return minPosition; };
};