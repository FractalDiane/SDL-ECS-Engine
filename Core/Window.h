#pragma once

#ifdef _WIN32
#include <SDL_video.h>
#else
#include <SDL2/SDL_video.h>
#endif

#include "Vector2.h"

class Window {
private:
	static SDL_Window* window;
	static SDL_Surface* base_surface;

	static int mouse_x;
	static int mouse_y;

	static const char* window_title;

public:
	static void create_window(const char* title, unsigned int width, unsigned int height, unsigned int pixel_scale_h = 1, unsigned int pixel_scale_v = 1);
	static void destroy_window();

	static SDL_Window* get_main_window();
	static SDL_Surface* get_main_surface();

	static const char* get_title();

	static Vector2I get_mouse_position();

	static void clear();
	static void update();
};
