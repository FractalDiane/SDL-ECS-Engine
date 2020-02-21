#pragma once

#include "Component.h"

class BulletComponent : public Component {
private:
	float speed = 500;

public:
	float get_speed() { return speed; }
};
