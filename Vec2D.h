#pragma once
#pragma once
#include <Windows.h>
#include <cmath>
constexpr float pi = 3.14159265359;
template <typename Ty>
class Vec2D
{
	using ThisType = Vec2D<Ty>;
public:
	Vec2D() :x(0), y(0) {}
	Vec2D(Ty x, Ty y) :x(x), y(y) {}
	//API POINT to Vec2D<Ty>
	Vec2D(POINT pt) : x(pt.x), y(pt, y) {}
	Ty x;
	Ty y;

	float GetScale() const
	{
		return sqrt(pow(x, 2) + pow(y, 2));
	}
	float GetScaleSq() const
	{
		return (pow(x, 2) + pow(y, 2));
	}
	ThisType Nomal() const
	{
		return ThisType(x / this->GetScale(), y / this->GetScale());
	}
	ThisType& Nomalize()
	{
		this->x /= this->GetScale();
		this->y /= this->GetScale();
	}
	ThisType Lerp(const ThisType& dest, float t, float xerror = 0.15f, float yerror = 0.5f ) const
	{
		auto ret = (*this) * (1 - t) + dest * t;
		if (dest.x + xerror > this->x - xerror && this->x + xerror > dest.x - xerror)
		{
			//ret.x = dest.x;
			ret.x = this->x;
		}
		if (dest.y + yerror > this->y - yerror && this->y + yerror > dest.y - yerror)
		{
			ret.y = this->y;
			//ret.y = dest.y;
		}
		return ret;
	}
	ThisType RotatedPoint(const ThisType & pivot, float angle) const
	{
		float x = cos(angle / 360 * (2 * pi)) * abs((pivot - *this).GetScale()) + pivot.x;
		float y = sin(angle / 360 * (2 * pi)) * abs((pivot - *this).GetScale()) + pivot.y;
		return ThisType{ x,y };
	}
	ThisType Rotate(const ThisType & pivot, float angle) const
	{
		this->x = cos(angle / 360 * (2 * pi)) * abs((pivot - *this).GetScale()) + pivot.x;
		this->y = sin(angle / 360 * (2 * pi)) * abs((pivot - *this).GetScale()) + pivot.y;
	}

	operator POINT() const
	{
		return	POINT{ static_cast<decltype(POINT::x)>(x), static_cast<decltype(POINT::y)>(y) };
	}
	template <typename OtherTy>
	operator Vec2D<OtherTy>() const
	{
		return Vec2D<OtherTy>(static_cast<OtherTy>(x), static_cast<OtherTy>(y));
	}

	//사칙연산 정의
	ThisType operator+(const ThisType & other) const
	{
		return ThisType(other.x + x, other.y + y);
	}
	ThisType& operator+=(const ThisType & other)
	{
		this->x += other.x;
		this->y += other.y;
		return *this;
	}
	ThisType operator-(const ThisType & other) const
	{
		return ThisType(x - other.x, y - other.y);
	}
	ThisType& operator-=(const ThisType & other)
	{
		this->x -= other.x;
		this->y -= other.y;
		return *this;
	}
	ThisType operator*(int scala) const
	{
		return ThisType(x * scala, y * scala);
	}
	ThisType operator*(float scala) const
	{
		return ThisType(x * scala, y * scala);
	}
	ThisType& operator*=(float scala)
	{
		this->x *= scala;
		this->y *= scala;
		return *this;
	}
	ThisType& operator*=(int scala)
	{
		this->x *= scala;
		this->y *= scala;
		return *this;
	}
	ThisType operator/(int scala) const
	{
		return ThisType(x / scala, y / scala);
	}
	ThisType operator/(float scala) const
	{
		return ThisType(x / scala, y / scala);
	}
	ThisType& operator/=(float scala)
	{
		this->x /= scala;
		this->y /= scala;
		return *this;
	}
	ThisType& operator/=(int scala)
	{
		this->x /= scala;
		this->y /= scala;
		return *this;
	}
	bool operator==(const ThisType & other)
	{
		return this->x == other.x && this->y == other.y;
	}
	static ThisType Up() { return ThisType{ 0, -1 }; }
	static ThisType Left() { return ThisType{ -1, 0 }; }
	static ThisType Down() { return ThisType{ 0, 1 }; }
	static ThisType Right() { return ThisType{ 1, 0 }; }
	static ThisType Zero() { return ThisType{ 0, 0 }; }
};
using Vec2DU = Vec2D<int>;
using Vec2DF = Vec2D<float>;