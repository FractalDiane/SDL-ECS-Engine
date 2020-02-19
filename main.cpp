#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <cstdio>
#include <iostream>
#include <vector>
#include <cstdint>

#include "TestEntity.h"
#include "SpriteRenderer.h"

std::vector<Entity*> entities;
bool quit = false;


void initialize_entities(const std::vector<Entity*>& entities) {
	for (Entity* ent : entities) {
		ent->_ready();
		for (Component* comp : ent->get_component_list())
			comp->_ready();
	}
}


void poll_events(SDL_Event& event_handler) {
	while (SDL_PollEvent(&event_handler) != 0) {
		switch (event_handler.type) {
			case SDL_EventType::SDL_QUIT: {
				quit = true;
			} break;
		}
	}
}


void update_delta_time(std::uint64_t& dt_last, std::uint64_t& dt_now, double& delta_time) {
	dt_last = dt_now;
	dt_now = SDL_GetPerformanceCounter();
	delta_time = ((dt_now - dt_last) * 1000 / static_cast<double>(SDL_GetPerformanceFrequency())) * 0.001;
}


void process_entities(const std::vector<Entity*>& entities, SDL_Surface* window_surface, double delta) {
	for (Entity* ent : entities) {
		if (ent->is_process_enabled())
			ent->_process(static_cast<float>(delta));
			
		for (Component* comp : ent->get_component_list())
			comp->_process(window_surface);
	}
}

// ====================================================================================================================

int main() {
	// Inits
	SDL_Window* window;
	SDL_Surface* surface;
	SDL_Event event_handler;

	// Entities/Components
	TestEntity test_ent{};
	test_ent.set_position(Vector2{320, 240});
	entities.push_back(&test_ent);
	SpriteRenderer spr{"../Sprites/Boss.png"};
	test_ent.add_component(&spr);

	// Init delta time
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

			initialize_entities(entities);

			while (!quit) {
				poll_events(event_handler);

				update_delta_time(dt_last, dt_now, delta_time);

				// Clear screen for drawing
				SDL_FillRect(surface, nullptr, 0);

				process_entities(entities, surface, delta_time);

				SDL_UpdateWindowSurface(window);
			}
		}
	}

	SDL_DestroyWindow(window);
	SDL_Quit();
}
