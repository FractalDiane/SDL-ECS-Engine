#include "SpriteRenderer.h"

#include "Transform.h"
#include "Entity.h"

#include <iostream>

SpriteRenderer::SpriteRenderer(const char* image_file) {
	image = IMG_Load(image_file);
	if (!image)
		std::cerr << "Failed to load image: " << image_file << "\n";
}


SpriteRenderer::~SpriteRenderer() {
	SDL_FreeSurface(image);
}


void SpriteRenderer::_comp_process(float delta, SDL_Surface* window_surface) {
	Vector2 parent_pos = parent->get_component<Transform>()->get_position();
	SDL_Rect pos_rect{static_cast<int>(parent_pos.x), static_cast<int>(parent_pos.y), 0, 0};
	SDL_BlitSurface(image, nullptr, window_surface, &pos_rect);
}
