#pragma once

#include "Component.h"
#include "Transform.h"
#include "Sprite.h"

#include <string>

class PlayerComponent : public Component {
private:
	std::string name;
	unsigned int favorite_number;
	float speed = 150;

public:
	//PlayerComponent(Transform* t, Sprite* sp) : player_transform{t}, spr{sp} {}

	float get_speed() { return speed; }
};
