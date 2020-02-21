#include "Transform.h"
#include "Sprite.h"
#include "PlayerComponent.h"
#include "PlayerSystem.h"
#include "RenderSystem.h"

#include "Input.h"
#include "World.h"
#include "Window.h"

#ifdef ECS_DEBUG
#warning [ECS] Compiling in debug mode
#endif

// ====================================================================================================================

int main() {
	// Inits
	World game_world;

	// Entities/Components
	Entity* ent = new Entity{};
	Transform* t = new Transform{};

	Sprite* spr = new Sprite{"../Sprites/Boss.png"};

	PlayerComponent* player = new PlayerComponent{};
	
	ent->add_component(t);
	ent->add_component(spr);
	ent->add_component(player);

	PlayerSystem psys{};
	RenderSystem rsys{};

	game_world.add_entity(ent);
	game_world.add_component(t);
	game_world.add_component(spr);
	game_world.add_component(player);
	game_world.add_system(&psys);
	game_world.add_system(&rsys);

	Window::create_window("SDL Test", 640, 480);

	while (!game_world.game_quit()) {
		game_world.poll_events();
		game_world.tick_delta_time();

		Window::clear();

		game_world.process_systems();

		Window::update();
	}

	Window::destroy_window();
	SDL_Quit();
}
