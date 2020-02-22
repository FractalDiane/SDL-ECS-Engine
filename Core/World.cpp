#include "World.h"

#include "Input.h"

#include <SDL2/SDL_timer.h>

#include <algorithm>

#ifdef ECS_DEBUG
#include "ECSSystem.h"
#endif

#ifdef ECS_SHOW_FPS
#include <string>
#endif

unsigned long World::EntityCounter = 0;

World::World() : dt_now{SDL_GetPerformanceCounter()}, dt_last{0}, delta_time_{0}, quit{false} {}
World::~World() {
	#ifdef ECS_DEBUG
	size_t ccount = 0;
	for (auto& pair : component_map)
		ccount += pair.second.size();

	ECS_PRINT_MESSAGE("DESTROYING EVERYTHING (%lu entities and %lu components)", entity_list.size(), ccount);
	#endif

	for (auto& pair : component_map) {
		//for (size_t i = 0; i < pair.second.size(); i++)
		for (Component* comp : pair.second)
			destroy_component(comp, false);
	}

	//for (size_t i = 0; i < entity_list.size(); i++)
	for (Entity* ent : entity_list)
		destroy_entity(ent, false, false);
}


void World::add_entity(Entity* ent) {
	entity_list.push_back(ent);
	ent->set_id(EntityCounter++);

	#ifdef ECS_DEBUG
	ECS_PRINT_MESSAGE("Added a new entity (ID %lu)", EntityCounter - 1);
	#endif
}


void World::add_component(Component* comp) {
	component_map[typeid(*comp)].push_back(comp);

	#ifdef ECS_DEBUG
	ECS_PRINT_MESSAGE("Added a new component (%s)", typeid(*comp).name());
	#endif
}


void World::add_system(System* sys) {
	system_list.push_back(sys);

	#ifdef ECS_DEBUG
	ECS_PRINT_MESSAGE("Added a new system (%s)", typeid(*sys).name());
	#endif
}


void World::destroy_entity(Entity* ent, bool destroy_components, bool remove_from_list) {
	#ifdef ECS_DEBUG
	ECS_PRINT_MESSAGE("Destroying entity ID %lu", ent->get_id());
	#endif

	if (destroy_components) {
		for (auto& pair : ent->get_components())
			destroy_component(pair.second);
	}
	
	if (remove_from_list)
		entity_list.erase(std::remove(entity_list.begin(), entity_list.end(), ent));

	delete ent;
}


void World::destroy_component(Component* comp, bool remove_from_map) {
	auto& target_vec = component_map[typeid(*comp)];
	for (size_t i = 0; i < target_vec.size(); i++) {
		auto current_comp = target_vec[i];
		if (current_comp == comp) {
			#ifdef ECS_DEBUG
			ECS_PRINT_MESSAGE("Destroying entity ID %lu's component (%s)", comp->get_owner()->get_id(), typeid(*current_comp).name());
			#endif

			if (remove_from_map)
				target_vec.erase(std::remove(target_vec.begin(), target_vec.end(), current_comp));

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

	#ifdef ECS_SHOW_FPS
	SDL_SetWindowTitle(Window::get_main_window(), (std::string{Window::get_title()} + " - " + std::to_string(static_cast<long>(1.0 / delta_time_)) + " FPS").c_str());
	#endif
}


void World::process_systems() {
	for (System* sys : system_list) {
	//for (size_t i = 0; i < system_list.size(); i++) {
		//System* sys = system_list[i];
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


bool World::is_game_quit() const {
	return quit;
}

