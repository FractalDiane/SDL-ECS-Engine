#pragma once

#include "Component.h"
#include "Transform.h"
#include "SpriteRenderer.h"

#include <string>

class PlayerComponent : public Component {
private:
	std::string name;
	unsigned int favorite_number;
	float speed;

	Transform* player_transform;
	SpriteRenderer* spr;

public:
	PlayerComponent(Transform* t, SpriteRenderer* sp) : player_transform{t}, spr{sp} {}

	Transform* get_transform() { return player_transform; }
	SpriteRenderer* get_sprite() { return spr; }
	float get_speed() { return speed; }
};
