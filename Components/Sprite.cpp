#include "Sprite.h"

#include <iostream>

Sprite::Sprite(const char* image_file) {
	image = IMG_Load(image_file);
	if (!image)
		std::cerr << "Failed to load image: " << image_file << "\n";
}


Sprite::~Sprite() {
	SDL_FreeSurface(image);
}
