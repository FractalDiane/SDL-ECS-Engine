#include "World.h"

#include "Input.h"

#include <SDL2/SDL_timer.h>

#ifdef ECS_DEBUG
#include <iostream>
#endif

unsigned long World::EntityCounter = 0;

World::World() : dt_now{SDL_GetPerformanceCounter()}, dt_last{0}, delta_time_{0}, quit{false} {}
World::~World() {
	#ifdef ECS_DEBUG
	std::cout << "[ECS] DESTROYING EVERYTHING\n";
	#endif

	for (auto& pair : component_map) {
		for (size_t i = 0; i < pair.second.size(); i++)
			destroy_component(pair.second[i]);
	}

	for (size_t i = 0; i < entity_list.size(); i++)
		destroy_entity(entity_list[i]);
}


void World::add_entity(Entity* ent) {
	entity_list.push_back(ent);
	ent->set_id(EntityCounter++);

	#ifdef ECS_DEBUG
	std::cout << "[ECS] Added a new entity (ID " << EntityCounter - 1 << ")\n";
	#endif
}


void World::add_system(System* sys) {
	system_list.push_back(sys);

	#ifdef ECS_DEBUG
	std::cout << "[ECS] Added a new system (" << typeid(*sys).name() << ")\n";
	#endif
}


void World::destroy_entity(Entity* ent) {
	#ifdef ECS_DEBUG
	std::cout << "[ECS] Destroying entity ID " << ent->get_id() << "\n";
	#endif

	//for (auto& pair : ent->get_components())
	//	destroy_component(pair.second);
		
	entity_list.erase(ent);
	delete ent;
}


void World::destroy_component(Component* comp) {
	auto& target_vec = component_map[typeid(*comp)];
	for (size_t i = 0; i < target_vec.size(); i++) {
		auto current_comp = target_vec[i];
		if (current_comp == comp) {
			#ifdef ECS_DEBUG
			std::cout << "[ECS] Destroying entity ID " << comp->get_owner()->get_id() << "'s component (" << typeid(*current_comp).name() << ")\n";
			#endif

			target_vec.erase(current_comp);
			delete current_comp;
		}
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
	//for (System* sys : system_list) {
	for (size_t i = 0; i < system_list.size(); i++) {
		System* sys = system_list[i];
		if (sys)
			sys->run(*this);
	}
}


double World::delta_time() const {
	return delta_time_;
}


Window* World::get_window() const {
	return window;
}


void World::set_window(Window* value) {
	window = value;
}


bool World::game_quit() const {
	return quit;
}

