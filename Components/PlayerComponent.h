#pragma once

#include "Component.h"

class PlayerComponent : public Component {
private:
	unsigned int favorite_number;
	float speed = 150;

public:
	float get_speed() { return speed; }
};
