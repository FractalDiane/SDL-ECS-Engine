#include "SpriteRenderer.h"

#include <iostream>

SpriteRenderer::SpriteRenderer(const char* image_file) : position{Vector2(0, 0)}, rotation{0}, scale{Vector2(1, 1)} {
	image = IMG_Load(image_file);
	if (!image)
		std::cerr << "Failed to load image: " << image_file << "\n";
}


SpriteRenderer::~SpriteRenderer() {
	SDL_FreeSurface(image);
}


void SpriteRenderer::_ready() {

}


void SpriteRenderer::_process(SDL_Surface* window_surface) {
	SDL_Rect pos_rect{static_cast<int>(position.x + parent->get_position().x), static_cast<int>(position.y + parent->get_position().y), 0, 0};
	SDL_BlitSurface(image, nullptr, window_surface, &pos_rect);
}
