#include "PlayerSystem.h"

#include <iostream>

#include "World.h"
#include "Input.h"

void PlayerSystem::run(World& world) {
	//for (auto p : world.get_components<PlayerComponent>()) {
	for (size_t i = 0; i < world.get_components<PlayerComponent>().size(); i++) {
		PlayerComponent* p = world.get_components<PlayerComponent>()[i];
		if (p)
			player_input(world.delta_time(), p, world);
	}
}


void PlayerSystem::player_input(double delta, PlayerComponent* player, World& world) {
	int x1 = Input::is_key_held(SDLK_RIGHT) ? 1 : 0;
	int x2 = Input::is_key_held(SDLK_LEFT) ? 1 : 0;
	int y1 = Input::is_key_held(SDLK_DOWN) ? 1 : 0;
	int y2 = Input::is_key_held(SDLK_UP) ? 1 : 0;

	Vector2 vel = Vector2{x1 - x2, y1 - y2}.normalized() * player->get_speed() * delta;

	Vector2 pos = player->get_owner_component<Transform>()->get_position();
	player->get_owner_component<Transform>()->set_position(Vector2{pos + vel});

	if (Input::is_key_pressed(SDLK_t)) {
		//world.destroy_entity(player->get_owner());
		world.destroy_component(player);
	}
}
