#ifndef __SPRITE_RENDERER_H
#define __SPRITE_RENDERER_H

#include "Component.h"
#include "Vector2.h"

#include <SDL2/SDL_image.h>

class SpriteRenderer : public Component {
private:
	SDL_Surface* image;

public:
	SpriteRenderer(const char* image_file);
	~SpriteRenderer();

	void _comp_process(float delta, SDL_Surface* window_surface) override;
};

#endif
