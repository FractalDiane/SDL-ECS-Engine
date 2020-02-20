#include "SpriteRenderer.h"

#include <iostream>

SpriteRenderer::SpriteRenderer(const char* image_file) {
	image = IMG_Load(image_file);
	if (!image)
		std::cerr << "Failed to load image: " << image_file << "\n";
}


SpriteRenderer::~SpriteRenderer() {
	SDL_FreeSurface(image);
}
