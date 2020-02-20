#include "Component.h"

Component::Component(World* world) { world->add_component(this); }
Component::~Component() { /* world->remove_component(this); */ }


void Component::set_owner(Entity* value) {
	owner = value;
}
