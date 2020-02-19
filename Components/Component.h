#ifndef __COMPONENT_H
#define __COMPONENT_H

#include <SDL2/SDL_surface.h>
#include "Entity.h"

class Entity;

class Component {
public:
	virtual void _ready() = 0;
	virtual void _process(SDL_Surface* window_surface) = 0;

protected:
	Entity* parent;

public:
	void set_parent(Entity* value);
};

#endif
