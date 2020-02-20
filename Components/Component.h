#pragma once

#include <SDL2/SDL_surface.h>

class Entity;

class Component {
public:
	Component();
	virtual ~Component();

	virtual void _comp_ready();
	virtual void _comp_process(float delta, SDL_Surface* window_surface);

protected:
	Entity* owner;

public:
	void set_owner(Entity* value);
};
