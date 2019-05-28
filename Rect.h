#pragma once

#include <Windows.h>
#include "Vec2D.h"

template <class Ty>
class Rect
{
	using ThisType = Rect<Ty>;
	//using Ty = float;
public:

	Rect() :top(0), left(0), bottom(0), right(0) {};

	//
	Rect(const Ty& left, const Ty& top, const Ty& right, const Ty& bottom)
		:TL(top, left), RB(right, bottom)
	{

	};
	//�� �ΰ��� ��Ʈ ����
	Rect(const Vec2D<Ty>& TL, const Vec2D<Ty>& RB) :TL(TL), RB(RB) {};
	//�߰����� ����, ���� ������� ��Ʈ ����
	Rect(const Vec2D<Ty>& center, Ty width, Ty height) :top(center.y - height / 2), left(center.x - width / 2), bottom(center.y + height / 2), right(center.x + width / 2) {}
	//�߰����� �� �ѷ��� ���簢�� ��Ʈ ����
	Rect(const Vec2D<Ty>& center, Ty round) :Rect(center, round, round) {}
	//API RECT to Rect
	Rect(const RECT& rect) : top(rect.top), left(rect.left), bottom(rect.bottom), right(rect.right) {}

	union
	{
		struct
		{
			Ty top;
			Ty left;
		};
		Vec2D<Ty> TL;
	};
	union
	{
		struct
		{
			Ty right;
			Ty bottom;
		};
		Vec2D<Ty> RB;
	};

	Ty Width() const
	{
		return right - left;
	}
	Ty Heigth() const
	{
		return bottom - top;
	}
	Vec2D<Ty> GetSize() const
	{
		return Vec2D<Ty>(this->Width(), this->Heigth());
	}
	operator RECT() const
	{
		return RECT{
			static_cast<decltype(RECT::left)>(left),
			static_cast<decltype(RECT::top)>(top),
			static_cast<decltype(RECT::right)>(right),
			static_cast<decltype(RECT::bottom)>(bottom)
		};
	}
	//�浹 ���� �Լ�
	//1. Rect�� Rect �� ��ġ���� (isCollision)
	//2. Vec2D�� �����ϰ� �ִ��� (isIn)
	//3. Rect�� �����ϰ� �ִ��� (isIn)
	bool isCollision(const ThisType& rect, ThisType* intercest = nullptr) const
	{
		if (intercest != nullptr)
		{
			intercest->left = (this->left > rect.left) ? this->left : rect.left;
			intercest->right = (this->right < rect.right) ? this->right : rect.right;
			intercest->top = (this->top > rect.top) ? this->top : rect.top;
			intercest->bottom = (this->bottom < rect.bottom) ? this->bottom : rect.bottom;
		}
		return (this->left < rect.right && this->right > rect.left && this->top < rect.bottom && this->bottom > rect.top);
	};

	//�ش� ���� ���� ��Ʈ�� ���ԵǴ���
	bool hasIn(const Vec2D<Ty>& point) const
	{
		return (this->left <= point.x && point.x <= this->right && this->top <= point.y && point.y <= this->bottom);
	}
	//�ش� ������ ���� ������ ���ԵǴ���
	bool hasIn(const ThisType & rect) const
	{
		return this->left <= rect.left && this->top <= rect.top && this->right >= rect.right && this->bottom >= rect.right;
	}
	//���� ������ �ش� ������ ���ԵǴ���
	bool isIn(const ThisType & rect) const
	{
		return rect.hasIn(*this);
	}

	template<typename TTy>
	ThisType operator+(const Vec2D<TTy> & vec)
	{
		ThisType rt = *this;
		rt.TL += vec;
		rt.RB += vec;
		return rt;
	}
	template<typename TTy>
	ThisType operator-(const Vec2D<TTy> & vec)
	{
		ThisType rt = *this;
		rt.TL -= vec;
		rt.RB -= vec;
		return rt;
	}
	template<typename TTy>
	ThisType& operator+=(const Vec2D<TTy> & vec)
	{
		ThisType& rt = *this;
		rt.TL += vec;
		rt.RB += vec;
		return rt;
	}
	template<typename TTy>
	ThisType& operator-=(const Vec2D<TTy> & vec)
	{
		ThisType& rt = *this;
		rt.TL -= vec;
		rt.RB -= vec;
		return rt;
	}
	Vec2D<Ty> GetCenter() const
	{
		auto vec = this->GetSize() / 2;
		return vec + Vec2D<Ty>{this->left, this->top};
	}
};

using RectU = Rect<int>;
using RectF = Rect<float>;