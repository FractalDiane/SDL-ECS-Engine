#pragma once

#include "System.h"
#include "PlayerComponent.h"

class PlayerSystem : public System {
public:
	void run(World& world) override;

private:
	void player_input(double delta, PlayerComponent* player, World& world);
	void fire_bullet(const Vector2& player_pos, World& world);
};
