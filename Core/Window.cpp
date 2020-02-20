#include "Window.h"

#include <SDL2/SDL.h>

#include <cstdio>

Window::Window(const char* title, unsigned int width, unsigned int height, unsigned int pixel_scale_h = 1, unsigned int pixel_scale_v = 1) {
	int result = SDL_Init(SDL_INIT_VIDEO);
	if (result < 0) {
		std::fprintf(stderr, "ERROR: %s", SDL_GetError());
		std::abort();
	}
	
	window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
	if (!window) {
		std::fprintf(stderr, "ERROR: %s", SDL_GetError());
		std::abort();
	}

	base_surface = SDL_GetWindowSurface(window);
}


Window::~Window() {
	SDL_DestroyWindow(window);
}


SDL_Window* Window::get_sdl_window() const {
	return window;
}


SDL_Surface* Window::get_surface() const {
	return base_surface;
}


void Window::clear() {
	SDL_FillRect(base_surface, nullptr, 0);
}


void Window::update() {
	SDL_UpdateWindowSurface(window);
}
