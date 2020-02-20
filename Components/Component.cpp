#include "Component.h"

Component::Component() {}
Component::~Component() {}


void Component::set_owner(Entity* value) {
	owner = value;
}


void Component::_comp_ready() {}
void Component::_comp_process(float delta, SDL_Surface* window_surface) {}
