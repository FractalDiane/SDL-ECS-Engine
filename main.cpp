#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <cstdio>
#include <iostream>
#include <vector>
#include <cstdint>

#include "TestEntity.h"
#include "SpriteRenderer.h"

std::vector<Entity*> entities;


int main() {
	SDL_Window* window;
	SDL_Surface* surface;

	SDL_Event ev;

	TestEntity test_ent{};
	test_ent.set_position(Vector2{320, 240});
	entities.push_back(&test_ent);
	SpriteRenderer spr{"Boss.png"};
	test_ent.add_component(&spr);

	bool quit = false;

	std::uint64_t dt_now = SDL_GetPerformanceCounter();
	std::uint64_t dt_last = 0;
	double delta_time = 0;

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::printf("ERROR: %s\n", SDL_GetError());
	}
	else {
		window = SDL_CreateWindow("SDL Test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);
		if (!window)
			std::printf("ERROR: %s\n", SDL_GetError());
		else {
			surface = SDL_GetWindowSurface(window);

			for (Entity* ent : entities) {
				ent->_ready();
				for (Component* comp : ent->get_component_list())
					comp->_ready();
			}

			while (!quit) {
				while (SDL_PollEvent(&ev) != 0) {
					switch (ev.type) {
						case SDL_EventType::SDL_QUIT: {
							quit = true;
						} break;
					}
				}

				dt_last = dt_now;
				dt_now = SDL_GetPerformanceCounter();
				delta_time = ((dt_now - dt_last) * 1000 / static_cast<double>(SDL_GetPerformanceFrequency())) * 0.001;

				for (Entity* ent : entities) {
					ent->_process(static_cast<float>(delta_time));
					for (Component* comp : ent->get_component_list())
						comp->_process(surface);
				}

				SDL_UpdateWindowSurface(window);
			}
		}
	}

	SDL_DestroyWindow(window);
	SDL_Quit();
}
