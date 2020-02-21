#include "Component.h"

Component::Component() {}
Component::~Component() { /* world->remove_component(this); */ }


Entity* Component::get_owner() const {
	return owner;
}

void Component::set_owner(Entity* value) {
	owner = value;
}
