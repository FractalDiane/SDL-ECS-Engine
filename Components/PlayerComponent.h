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

	Transform* player_transform;
	Sprite* spr;


public:
	PlayerComponent(Transform* t, Sprite* sp) : player_transform{t}, spr{sp} {}

	Transform* get_transform() { return player_transform; }
	Sprite* get_sprite() { return spr; }
	float get_speed() { return speed; }
};
