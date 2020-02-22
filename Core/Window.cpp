#include "Window.h"

#ifdef _WIN32
#include <SDL.h>
#else
#include <SDL2/SDL.h>
#endif

#include "ECSSystem.h"


SDL_Window* Window::window = nullptr;
SDL_Surface* Window::base_surface = nullptr;
const char* Window::window_title = "";

int Window::mouse_x = 0;
int Window::mouse_y = 0;

void Window::create_window(const char* title, unsigned int width, unsigned int height, unsigned int pixel_scale_h, unsigned int pixel_scale_v) {
	int result = SDL_Init(SDL_INIT_VIDEO);
	if (result < 0) {
		ECS_PRINT_ERROR("Failed to initialize SDL (%s)", SDL_GetError());
		std::abort();
	}
	
	window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
	if (!window) {
		ECS_PRINT_ERROR("Failed to create SDL window (%s)", SDL_GetError());
		std::abort();
	}

	base_surface = SDL_GetWindowSurface(window);
	window_title = title;
}


void Window::destroy_window() {
	SDL_DestroyWindow(window);
}


SDL_Window* Window::get_main_window() {
	return window;
}


SDL_Surface* Window::get_main_surface() {
	return base_surface;
}


const char* Window::get_title() { 
	return window_title;
}


Vector2I Window::get_mouse_position() {
	return Vector2I{mouse_x, mouse_y};
}


void Window::clear() {
	SDL_FillRect(base_surface, nullptr, 0);
}


void Window::update() {
	SDL_GetMouseState(&mouse_x, &mouse_y);
	SDL_UpdateWindowSurface(window);
}
