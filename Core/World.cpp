#include "World.h"

#include "Input.h"

#include <SDL2/SDL_timer.h>


World::World() : dt_now{SDL_GetPerformanceCounter()}, dt_last{0}, delta_time_{0}, quit{false} {}
World::~World() {}

void World::add_entity(Entity* ent) {
	entity_list.push_back(ent);
}


void World::initialize_entities() {
	for (Entity* ent : entity_list) {
		for (auto comp : ent->get_component_list())
			comp.second->_comp_ready();
	}
}

void World::poll_events() {
	Input::update_momentary_keys();

	while (SDL_PollEvent(&event_handler) != 0) {
		switch (event_handler.type) {
			case SDL_EventType::SDL_QUIT: {
				quit = true;
			} break;

			case SDL_EventType::SDL_KEYDOWN: {
				Input::process_input_event(Input::KeyEventType::Pressed, event_handler);
			} break;

			case SDL_EventType::SDL_KEYUP: {
				Input::process_input_event(Input::KeyEventType::Released, event_handler);
			} break;
		}
	}
}


void World::tick_delta_time() {
	dt_last = dt_now;
	dt_now = SDL_GetPerformanceCounter();
	delta_time_ = ((dt_now - dt_last) * 1000 / static_cast<double>(SDL_GetPerformanceFrequency())) * 0.001;
}


void World::process_systems() {
	for (System* sys : system_list) {
		sys->run(*this);
	}
}


double World::delta_time() const {
	return delta_time_;
}


bool World::game_quit() const {
	return quit;
}

