#include "Component.h"

Component::Component() {}
Component::~Component() { /* world->remove_component(this); */ }


void Component::set_owner(Entity* value) {
	owner = value;
}
