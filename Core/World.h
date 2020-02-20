#pragma once

#include "Entity.h"
#include "Component.h"
#include "System.h"

#include <SDL2/SDL_events.h>

#include <vector>
#include <cstdint>


class World {
private:
	std::vector<Entity*> entity_list;
	std::vector<std::vector<Component*>> component_list;
	std::vector<System*> system_list;

	SDL_Event event_handler;

	std::uint64_t dt_now;
	std::uint64_t dt_last;
	double delta_time_;

	bool quit;

public:
	World();
	~World();

	const std::vector<Entity*>& get_entity_list() const;
	void add_entity(Entity* ent);

	void initialize_entities();
	void poll_events();
	void tick_delta_time();

	//template <typename C>
	//const std::vector<C>

	void process_systems();

	double delta_time() const;

	bool game_quit() const;
};
