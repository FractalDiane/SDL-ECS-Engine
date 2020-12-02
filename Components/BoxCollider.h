#pragma once

#include "Components/Component.h"
#include "Components/Transform.h"
#include "Core/Vector2.h"

class BoxCollider : public Component {
private:
	Vector2 center;
	float extent_x;
	float extent_y;

public:
	BoxCollider(const Vector2& center, float extent_x, float extent_y) : center{center}, extent_x{extent_x}, extent_y{extent_y} {}
	~BoxCollider() {}

	float get_extent_x() { return extent_x; }
	float get_extent_y() { return extent_y; }
};
