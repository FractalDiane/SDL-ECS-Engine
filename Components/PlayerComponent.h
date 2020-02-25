#pragma once

#include "Component.h"

class PlayerComponent : public Component {
public:
	enum class Direction { Up, Down, Left, Right };

private:
	unsigned int favorite_number;
	float speed = 200;
	Direction direction = Direction::Down;

public:
	float get_speed() { return speed; }

	Direction get_direction() { return direction; }
	void set_direction(Direction value) { direction = value; }
};
