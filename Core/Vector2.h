#pragma once

#include <cmath>

struct Vector2I;

struct Vector2 {
	float x;
	float y;

	Vector2();
	Vector2(float x_, float y_);
	Vector2(const Vector2& rvalue);
	Vector2& operator=(const Vector2& rvalue);

	operator Vector2I() const;

	float angle() const;
	void set_rotation(float radians);
	float magnitude() const;
	Vector2 normalized() const;
	float dot(const Vector2& rvalue) const;
	float cross(const Vector2& rvalue) const;
	float distance_to(const Vector2& rvalue) const;
	float angle_to(const Vector2& rvalue) const;
	Vector2 rotated(float by) const;


	Vector2 operator+(const Vector2& rvalue) const;
	Vector2 operator-(const Vector2& rvalue) const;
	Vector2 operator*(const float& rvalue) const;
	Vector2 operator/(const float& rvalue) const;


	Vector2& operator+=(const Vector2& rvalue);
	Vector2& operator-=(const Vector2& rvalue);
	Vector2& operator*=(const float& rvalue);
	Vector2& operator/=(const float& rvalue);

	Vector2 operator-() const;

	bool operator==(const Vector2& rvalue) const;
	bool operator!=(const Vector2& rvalue) const;
};


struct Vector2I {
	int x;
	int y;

	Vector2I();
	Vector2I(int x_, int y_);
	Vector2I(const Vector2I& rvalue);
	Vector2I& operator=(const Vector2I& rvalue);

	operator Vector2() const;
};
