#include "AnimatedSprite.h"

#include "ECSSystem.h"

AnimatedSprite::AnimatedSprite() : frame{0}, anim_time{0} {
	
}


AnimatedSprite::~AnimatedSprite() {
	for (auto& pair : animations)
		delete pair.second;

	for (SDL_Texture* texture : textures)
		SDL_DestroyTexture(texture);
}


void AnimatedSprite::add_textures(std::initializer_list<const char*> image_files) {
	for (auto* file : image_files) {
		SDL_Surface* surf = IMG_Load(file);
		if (!surf)
			ECS_PRINT_ERROR("Failed to load image: %s (%s)", file, IMG_GetError());

		texture_sizes.push_back(Vector2I{surf->w, surf->h});

		SDL_Texture* texture = SDL_CreateTextureFromSurface(Window::get_renderer(), surf);
		if (!texture)
			ECS_PRINT_ERROR("Failed to create texture: (%s)", SDL_GetError());

		textures.push_back(texture);
		SDL_FreeSurface(surf);
	}
}


void AnimatedSprite::add_animation(const std::string& name, std::initializer_list<unsigned int> image_sequence_, float animation_speed_) {
	animations.insert({name, new Animation{image_sequence_, animation_speed_}});
	if (animations.size() == 1)
		current_animation = name;
}


void AnimatedSprite::play_animation(const std::string& animation) {
	if (current_animation != animation) {
		current_animation = animation;
		frame = 0;
		anim_time = 0;
	}
}
