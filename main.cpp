#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <cstdio>
#include <iostream>
#include <vector>
#include <cstdint>

#include "Transform.h"
#include "Sprite.h"
#include "PlayerComponent.h"
#include "PlayerSystem.h"
#include "RenderSystem.h"

#include "Input.h"
#include "World.h"
#include "Window.h"

// ====================================================================================================================

int main() {
	// Inits
	World game_world;

	// Entities/Components
	Entity ent{};

	Transform t{};

	Sprite spr{"../Sprites/Boss.png"};

	PlayerComponent player{};

	ent.add_component(&t);
	ent.add_component(&spr);
	ent.add_component(&player);

	PlayerSystem psys{};
	RenderSystem rsys{};

	game_world.add_entity(&ent);
	game_world.add_component(&t);
	game_world.add_component(&spr);
	game_world.add_component(&player);
	game_world.add_system(&psys);
	game_world.add_system(&rsys);
	Window::create_window("SDL Test", 640, 480);

	while (!game_world.game_quit()) {
		game_world.poll_events();
		game_world.tick_delta_time();

		//game_window.clear();
		Window::clear();

		game_world.process_systems();

		Window::update();
	}

	Window::destroy_window();
	SDL_Quit();
}
