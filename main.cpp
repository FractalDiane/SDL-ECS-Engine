#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <cstdio>
#include <iostream>
#include <vector>
#include <cstdint>

#include "TestEntity.h"
#include "Transform.h"
#include "SpriteRenderer.h"
//#include "CustomBehavior.h"
#include "Input.h"
#include "World.h"
#include "Window.h"

void process_entities(const std::vector<Entity*>& entities, SDL_Surface* window_surface, const double& delta) {
	for (Entity* ent : entities) {
		for (auto comp : ent->get_component_list())
			comp.second->_comp_process(static_cast<float>(delta), window_surface);
	}
}

// ====================================================================================================================

int main() {
	// Inits
	World game_world;

	// Entities/Components
	/*TestEntity test_ent{};
	SpriteRenderer spr{"../Sprites/Boss.png"};
	test_ent.add_component(&spr);
	CustomBehavior cb{};
	test_ent.add_component(&cb);
	Transform tr{};
	tr.set_position(Vector2{320, 240});
	test_ent.add_component(&tr);

	game_world.add_entity(&test_ent);*/

	Window game_window{"SDL Test", 640, 480};

	while (!game_world.game_quit()) {
		game_world.poll_events();
		game_world.tick_delta_time();

		

		game_window.clear();
		game_window.update();
	}

	SDL_Quit();
}
