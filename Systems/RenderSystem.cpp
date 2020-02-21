#include "RenderSystem.h"

#include "World.h"
#include "Vector2.h"

#include <SDL2/SDL_surface.h>

void RenderSystem::run(World& world) {
	for (auto spr : world.get_components<Sprite>()) {
	//for (size_t i = 0; i < world.get_components<Sprite>().size(); i++) {
		//Sprite* spr = world.get_components<Sprite>()[i];
		render_sprite(spr, spr->get_owner_component<Transform>(), world);
	}
}


void RenderSystem::render_sprite(Sprite* spr, Transform* tr, World& world) {
	if (tr) {
		Vector2 pos = tr->get_position();
		SDL_Rect pos_rect{static_cast<int>(pos.x), static_cast<int>(pos.y), 0, 0};
		SDL_BlitSurface(spr->get_image(), nullptr, Window::get_main_surface(), &pos_rect);
	}
}
