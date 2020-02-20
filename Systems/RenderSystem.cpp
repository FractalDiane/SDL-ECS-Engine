#include "RenderSystem.h"

#include "World.h"
#include "Vector2.h"

#include <SDL2/SDL_surface.h>

void RenderSystem::run(World& world) {
	for (auto spr : world.get_components<Sprite>()) {
		render_sprite(spr, world);
	}
}


void RenderSystem::render_sprite(Sprite* spr, World& world) {
	Vector2 pos = spr->get_transform()->get_position();
	SDL_Rect pos_rect{static_cast<int>(pos.x), static_cast<int>(pos.y), 0, 0};
	SDL_BlitSurface(spr->get_image(), nullptr, world.get_window()->get_surface(), &pos_rect);
}
