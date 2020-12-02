#pragma once

#include "Systems/System.h"
#include "Components/PlayerComponent.h"
#include "Components/AnimatedSprite.h"

class PlayerSystem : public System {
public:
	void run(World& world) override;

private:
	void player_input(double delta, PlayerComponent* player, World& world);
	void fire_bullet(const Vector2& player_pos, World& world);
	
	void direction_management(const Vector2I& velocity, PlayerComponent* player);
	void sprite_management(PlayerComponent* player, AnimatedSprite* spr, const Vector2& velocity);
};
