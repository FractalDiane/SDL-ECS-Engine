#pragma once

#include <SDL2/SDL_video.h>

class Window {
private:
	SDL_Window* window;
	SDL_Surface* base_surface;

public:
	Window(const char* title, int width, int height);
	~Window();

	SDL_Surface* get_surface() const;

	void clear();
	void update();
};
