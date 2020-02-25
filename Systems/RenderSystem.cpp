#include "RenderSystem.h"

#include "World.h"
#include "Vector2.h"

#ifdef _WIN32
#include <SDL_surface.h>
#else
#include <SDL2/SDL_surface.h>
#endif

void RenderSystem::run(World& world) {
	for (auto* spr : world.get_components<Sprite>()) {
	//for (size_t i = 0; i < world.get_components<Sprite>().size(); i++) {
		//Sprite* spr = world.get_components<Sprite>()[i];
		render_sprite(spr, spr->get_owner_component<Transform>(), world);
	}
}


void RenderSystem::render_sprite(Sprite* spr, Transform* tr, World& world) {
	if (tr) {
		Vector2 pos = tr->get_position();
		float rot = tr->get_rotation();
		Vector2I size = spr->sprite_size();
		
		SDL_Rect pos_rect{static_cast<int>(pos.x), static_cast<int>(pos.y), size.x, size.y};

		SDL_RenderCopyEx(Window::get_renderer(), spr->get_texture(), nullptr, &pos_rect, rot, nullptr, SDL_RendererFlip::SDL_FLIP_NONE);
	}
}
