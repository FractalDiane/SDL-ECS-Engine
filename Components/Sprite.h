#pragma once

#include "Component.h"
#include "Transform.h"
#include "Vector2.h"

#ifdef _WIN32
#include <SDL_image.h>
#else
#include <SDL2/SDL_image.h>
#endif

class Sprite : public Component {
private:
	SDL_Texture* texture;
	Vector2I sprite_size_;

public:
	Sprite(const char* image_file);
	~Sprite();

	SDL_Texture* get_texture() { return texture; }
	const Vector2I& sprite_size() { return sprite_size_; }
};
