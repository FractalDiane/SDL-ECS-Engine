#include "Component.h"

Component::Component() {}
Component::~Component() {}


void Component::set_owner(Entity* value) {
	owner = value;
}
