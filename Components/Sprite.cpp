#include "Sprite.h"

#include "ECSSystem.h"

Sprite::Sprite(const char* image_file) {
	image = IMG_Load(image_file);
	if (!image)
		ECS_PRINT_ERROR("Failed to load image: %s (%s)", image_file, IMG_GetError());
}


Sprite::~Sprite() {
	SDL_FreeSurface(image);
}
