#pragma once

#include <SDL2/SDL_video.h>

class Window {
private:
	static SDL_Window* window;
	static SDL_Surface* base_surface;

public:
	static void create_window(const char* title, unsigned int width, unsigned int height, unsigned int pixel_scale_h = 1, unsigned int pixel_scale_v = 1);
	static void destroy_window();

	static SDL_Window* get_main_window();
	static SDL_Surface* get_main_surface();

	static void clear();
	static void update();
};
