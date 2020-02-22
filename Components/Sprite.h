#pragma once

#include "Component.h"
#include "Transform.h"

#ifdef _WIN32
#include <SDL_image.h>
#else
#include <SDL2/SDL_image.h>
#endif

class Sprite : public Component {
private:
	SDL_Surface* image;

public:
	Sprite(const char* image_file);
	~Sprite();

	SDL_Surface* get_image() { return image; }
};
