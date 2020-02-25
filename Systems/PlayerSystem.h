#pragma once

#include "System.h"
#include "PlayerComponent.h"
#include "AnimatedSprite.h"

class PlayerSystem : public System {
public:
	void run(World& world) override;

private:
	void player_input(double delta, PlayerComponent* player, World& world);
	void fire_bullet(const Vector2& player_pos, World& world);
	
	void direction_management(const Vector2I& velocity, PlayerComponent* player);
	void sprite_management(PlayerComponent* player, AnimatedSprite* spr, const Vector2& velocity);
};
