#pragma once

#include "Components/Component.h"
#include "Components/Transform.h"
#include "Core/Vector2.h"

#if defined(_WIN32) && 0
#include <SDL_image.h>
#else
#include <SDL2/SDL_image.h>
#endif

class Sprite : public Component {
private:
	SDL_Texture* texture;
	Vector2I sprite_size_;
	bool centered = false;

public:
	Sprite(const char* image_file);
	~Sprite();

	SDL_Texture* get_texture() { return texture; }
	const Vector2I& sprite_size() { return sprite_size_; }
	bool is_centered() { return centered;  }
	void set_centered(bool value) { centered = value;  }
};
