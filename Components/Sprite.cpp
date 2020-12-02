#include "Sprite.h"

#include "Core/ECSSystem.h"

Sprite::Sprite(const char* image_file) {
	SDL_Surface* surf = IMG_Load(image_file);
	if (!surf)
		ECS_PRINT_ERROR("Failed to load image: %s (%s)", image_file, IMG_GetError());

	sprite_size_ = {surf->w, surf->h};

	texture = SDL_CreateTextureFromSurface(Window::get_renderer(), surf);

	if (!texture)
		ECS_PRINT_ERROR("Failed to create texture: (%s)", SDL_GetError());

	SDL_FreeSurface(surf);
}


Sprite::~Sprite() {
	SDL_DestroyTexture(texture);
}
