#include "PlayerSystem.h"

#include <iostream>

#include "World.h"
#include "Input.h"

void PlayerSystem::run(World& world) {
	for (auto p : world.get_components<PlayerComponent>()) {
		player_input(world.delta_time(), p);
		//std::cout << p->get_transform()->get_position().x << "\n";
	}
}


void PlayerSystem::player_input(double delta, PlayerComponent* player) {
	int x1 = Input::is_key_held(SDLK_RIGHT) ? 1 : 0;
	int x2 = Input::is_key_held(SDLK_LEFT) ? 1 : 0;
	int y1 = Input::is_key_held(SDLK_DOWN) ? 1 : 0;
	int y2 = Input::is_key_held(SDLK_UP) ? 1 : 0;

	Vector2 vel = Vector2{x1 - x2, y1 - y2}.normalized() * player->get_speed() * delta;

	Vector2 pos = player->get_transform()->get_position();
	player->get_transform()->set_position(Vector2{pos + vel});
}
