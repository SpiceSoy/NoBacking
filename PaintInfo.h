#pragma once
#include <Windows.h>
#include "Vec2D.h"

struct PaintInfo
{
	HINSTANCE hinst = NULL;
	HDC hdc = NULL; // �׷��� DC : ���� ����DC
	HDC imageDc = NULL; // �̹���DC : �̹��� �ӽ÷� �����صδ� DC
	HDC stretchDc = NULL; // ��Ʈ��ġDC : Ȯ���ϱ� ���� �����صδ� DC
	int margin;
	Vec2DU DrawSize;
	Vec2DU StartPoint() const { return Vec2DU{ margin / 2, margin / 2 }; }
	Vec2DU EndPoint() const { return Vec2DU{ DrawSize.x + margin / 2, DrawSize.y + margin / 2 }; }
	HPEN CollisionPen[3];
	bool DrawCollision = false;
};