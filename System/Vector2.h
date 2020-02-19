#ifndef __VECTOR2_H
#define __VECTOR2_H

#include <cmath>

struct Vector2 {
	float x;
	float y;

	Vector2() : x{0}, y{0} {}
	Vector2(float x_, float y_) : x{x_}, y{y_} {}
	Vector2(const Vector2& rvalue) : x{rvalue.x}, y{rvalue.y} {}
	Vector2& operator=(const Vector2& rvalue) {
		if (this != &rvalue) {
			x = rvalue.x;
			y = rvalue.y;
		}

		return *this;
	}

	float magnitude() const {
		return std::sqrt(x * x + y * y);
	}

	Vector2 normalized() const {
		float m = magnitude();
		return m == 0 ? Vector2{x, y} : Vector2{x / m, y / m};
	}

	float dot(const Vector2& rvalue) const {
		return x * rvalue.x + y * rvalue.y;
	}


	Vector2 operator+(const Vector2& rvalue) const {
		return Vector2{x + rvalue.x, y + rvalue.y};
	}

	Vector2 operator-(const Vector2& rvalue) const {
		return Vector2{x - rvalue.x , y - rvalue.y};
	}

	Vector2 operator*(const float& rvalue) const {
		return Vector2{x * rvalue, y * rvalue};
	}

	Vector2 operator/(const float& rvalue) const {
		return Vector2{x / rvalue, y / rvalue};
	}


	Vector2& operator+=(const Vector2& rvalue) {
		x += rvalue.x;
		y += rvalue.y;
		return *this;
	}

	Vector2& operator-=(const Vector2& rvalue) {
		x -= rvalue.x;
		y -= rvalue.y;
		return *this;
	}

	Vector2& operator*=(const float& rvalue) {
		x *= rvalue;
		y *= rvalue;
		return *this;
	}

	Vector2& operator/=(const float& rvalue) {
		x /= rvalue;
		y /= rvalue;
		return *this;
	}

	Vector2 operator-() const {
		return *this * -1;
	}


	bool operator==(const Vector2& rvalue) const {
		return x == rvalue.x && y == rvalue.y;
	}

	bool operator!=(const Vector2& rvalue) const {
		return x != rvalue.x || y != rvalue.y;
	}
};

#endif
