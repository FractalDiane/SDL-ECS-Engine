#include "Components/Transform.h"
#include "Components/Sprite.h"
#include "Components/AnimatedSprite.h"
#include "Components/PlayerComponent.h"
#include "Systems/PlayerSystem.h"
#include "Systems/RenderSystem.h"
#include "Components/BulletComponent.h"
#include "Systems/BulletSystem.h"
#include "Components/BoxCollider.h"

#include "Core/Input.h"
#include "Core/World.h"
#include "Core/Window.h"

#if defined(_WIN32) && 0
#include <SDL.h>
#undef main
#else
#include <SDL2/SDL.h>
#endif

#ifdef ECS_DEBUG
#ifdef _MSC_VER
#pragma message("[ECS] Compiling in debug mode")
#else
#warning [ECS] Compiling in debug mode
#endif
#endif


int main() {
	// Inits
	World game_world;

	Window::create_window("SDL Test", 640, 480);

	// Entities/Components
	Entity* ent = new Entity{};
	Transform* t = new Transform{};
	t->set_scale(Vector2{2, 2});

	AnimatedSprite* spr = new AnimatedSprite{};
	spr->add_textures({
		"Sprites/Player/Player_up.png",
		"Sprites/Player/Player_up2.png",
		"Sprites/Player/Player_up3.png",
		"Sprites/Player/Player_up4.png",
		"Sprites/Player/Player_up5.png",
		
		"Sprites/Player/Player_down.png",
		"Sprites/Player/Player_down2.png",
		"Sprites/Player/Player_down3.png",
		"Sprites/Player/Player_down4.png",
		"Sprites/Player/Player_down5.png",
		
		"Sprites/Player/Player_left.png",
		"Sprites/Player/Player_left2.png",
		"Sprites/Player/Player_left3.png",
		"Sprites/Player/Player_left4.png",
		"Sprites/Player/Player_left5.png",

		"Sprites/Player/Player_right.png",
		"Sprites/Player/Player_right2.png",
		"Sprites/Player/Player_right3.png",
		"Sprites/Player/Player_right4.png",
		"Sprites/Player/Player_right5.png"});

	spr->add_animation("up", {0});
	spr->add_animation("up_walk", {1, 2, 1, 0, 3, 4, 3, 0}, 10.0);
	spr->add_animation("down", {5});
	spr->add_animation("down_walk", {6, 7, 6, 5, 8, 9, 8, 5}, 10.0);
	spr->add_animation("left", {10});
	spr->add_animation("left_walk", {11, 12, 11, 10, 13, 14, 13, 10}, 10.0);
	spr->add_animation("right", {15});
	spr->add_animation("right_walk", {16, 17, 16, 15, 18, 19, 18, 15}, 10.0);

	spr->set_centered(true);

	PlayerComponent* player = new PlayerComponent{};
	
	ent->add_component(t);
	ent->add_component(spr);
	ent->add_component(player);

	PlayerSystem psys{};
	RenderSystem rsys{};
	BulletSystem bsys{};

	game_world.add_entity(ent);
	game_world.add_component(t);
	game_world.add_component(spr);
	game_world.add_component(player);
	game_world.add_system(&psys);
	game_world.add_system(&rsys);
	game_world.add_system(&bsys);

	BoxCollider* coll = new BoxCollider{Vector2{0, 0}, 10, 10};
	ent->add_component(coll);
	game_world.add_component(coll);

	while (!game_world.is_game_quit()) {
		game_world.poll_events();
		game_world.tick_delta_time();

		Window::clear();

		game_world.process_systems();

		Window::update();
	}

	game_world.cleanup();
	Window::destroy_window();
	SDL_Quit();
}
