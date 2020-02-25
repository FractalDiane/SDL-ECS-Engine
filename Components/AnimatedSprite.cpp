#include "AnimatedSprite.h"

#include "ECSSystem.h"

AnimatedSprite::AnimatedSprite(std::initializer_list<const char*> image_files, std::initializer_list<unsigned int> image_sequence_, float animation_speed_) : image_sequence{image_sequence_}, animation_speed{animation_speed_}, frame{0}, anim_time{0} {
	for (auto* file : image_files) {
		SDL_Surface* surf = IMG_Load(file);
		if (!surf)
			ECS_PRINT_ERROR("Failed to load image: %s (%s)", file, IMG_GetError());

		sprite_sizes.push_back(Vector2I{surf->w, surf->h});

		SDL_Texture* texture = SDL_CreateTextureFromSurface(Window::get_renderer(), surf);
		if (!texture)
			ECS_PRINT_ERROR("Failed to create texture: (%s)", SDL_GetError());

		sprite_frames.push_back(texture);
		SDL_FreeSurface(surf);
	}
}


AnimatedSprite::~AnimatedSprite() {
	for (SDL_Texture* texture : sprite_frames)
		SDL_DestroyTexture(texture);
}
