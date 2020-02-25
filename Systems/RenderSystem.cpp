#include "RenderSystem.h"

#include "World.h"
#include "Vector2.h"

#ifdef _WIN32
#include <SDL_surface.h>
#else
#include <SDL2/SDL_surface.h>
#endif

void RenderSystem::run(World& world) {
	if (world.components_exist_of_type<Sprite>()) {
		for (auto* spr : world.get_components<Sprite>()) {
			render_sprite(spr, spr->get_owner_component<Transform>(), world);
		}
	}
}


void RenderSystem::render_sprite(Sprite* spr, Transform* tr, World& world) {
	if (tr) {
		Vector2 pos = tr->get_position();
		float rot = tr->get_rotation();
		Vector2 scale = tr->get_scale();
		Vector2I size = spr->sprite_size();

		SDL_Rect pos_rect{static_cast<int>(pos.x), static_cast<int>(pos.y), static_cast<int>(size.x * scale.x), static_cast<int>(size.y * scale.y)};

		SDL_RenderCopyEx(Window::get_renderer(), spr->get_texture(), nullptr, &pos_rect, rot, nullptr, SDL_RendererFlip::SDL_FLIP_NONE);
	}
}
