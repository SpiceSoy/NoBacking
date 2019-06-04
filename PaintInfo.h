#pragma once
#include <Windows.h>
#include "Vec2D.h"

struct PaintInfo
{
	HINSTANCE hinst = NULL;
	HDC hdc = NULL; // 그려질 DC : 보통 버퍼DC
	HDC imageDc = NULL; // 이미지DC : 이미지 임시로 저장해두는 DC
	HDC stretchDc = NULL; // 스트레치DC : 확대하기 전에 저장해두는 DC
	int margin;
	Vec2DU DrawSize;
	Vec2DU StartPoint() const { return Vec2DU{ margin / 2, margin / 2 }; }
	Vec2DU EndPoint() const { return Vec2DU{ DrawSize.x + margin / 2, DrawSize.y + margin / 2 }; }
	HPEN CollisionPen[3];
	bool DrawCollision = false;
};