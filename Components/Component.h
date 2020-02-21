#pragma once

#include <SDL2/SDL_surface.h>

#include <unordered_map>
#include <typeinfo>
#include <typeindex>

#include "World.h"

class Entity;

class Component {
/*private:
	World* world;
*/
public:
	Component();
	virtual ~Component();

protected:
	Entity* owner;

public:
	Entity* get_owner() const;
	void set_owner(Entity* value);

	template <typename C>
	C* get_owner_component();
};


#include "Entity.h"

template <typename C>
C* Component::get_owner_component() {
	return static_cast<C*>(owner->get_component<C>());
}
