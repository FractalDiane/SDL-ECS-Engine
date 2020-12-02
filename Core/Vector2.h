/*************************************************************************/
/*       Some functions in this file are adopted from Godot Engine       */
/*                      https://godotengine.org                          */
/*************************************************************************/
/* Copyright (c) 2007-2020 Juan Linietsky, Ariel Manzur.                 */
/* Copyright (c) 2014-2020 Godot Engine contributors (cf. AUTHORS.md).   */
/*                                                                       */
/* Permission is hereby granted, free of charge, to any person obtaining */
/* a copy of this software and associated documentation files (the       */
/* "Software"), to deal in the Software without restriction, including   */
/* without limitation the rights to use, copy, modify, merge, publish,   */
/* distribute, sublicense, and/or sell copies of the Software, and to    */
/* permit persons to whom the Software is furnished to do so, subject to */
/* the following conditions:                                             */
/*                                                                       */
/* The above copyright notice and this permission notice shall be        */
/* included in all copies or substantial portions of the Software.       */
/*                                                                       */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,       */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF    */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.*/
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY  */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,  */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE     */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                */
/*************************************************************************/

#pragma once

#include <cmath>

struct Vector2I;

struct Vector2 {
	float x;
	float y;

	static const Vector2 Zero;

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
