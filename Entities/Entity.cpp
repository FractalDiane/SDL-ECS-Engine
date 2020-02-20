#include "Entity.h"

Entity::Entity() {}

Entity::~Entity() {
	/*for (auto pair : component_refs)
		delete pair.second;*/
}


unsigned long Entity::get_id() const {
	return id;
}


void Entity::set_id(unsigned long value) {
	id = value;
}
