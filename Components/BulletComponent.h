#pragma once

#include "Component.h"
#include "Vector2.h"

class BulletComponent : public Component {
private:
	float speed = 500;
	Vector2 velocity = {0, 0};

public:
	float get_speed() { return speed; }

	const Vector2& get_velocity() { return velocity; }
	void set_velocity(const Vector2& value) { velocity = value; }
};
