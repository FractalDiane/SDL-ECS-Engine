#include "Component.h"

Component::Component() {}
Component::~Component() {}


void Component::set_parent(Entity* value) {
	parent = value;
}


void Component::_ready() {}
void Component::_process(SDL_Surface* window_surface) {}
