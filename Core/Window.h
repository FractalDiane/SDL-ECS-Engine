#pragma once

#include <SDL2/SDL_video.h>

class Window {
private:
	SDL_Window* window;
	SDL_Surface* base_surface;

public:
	Window(const char* title, unsigned int width, unsigned int height, unsigned int pixel_scale_h = 1, unsigned int pixel_scale_v = 1);
	~Window();

	SDL_Window* get_sdl_window() const;
	SDL_Surface* get_surface() const;

	void clear();
	void update();
};
