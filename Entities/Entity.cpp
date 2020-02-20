#include "Entity.h"

#include <SDL2/SDL_image.h>

Entity::Entity(unsigned long id_) : id{id_} {}

Entity::~Entity() {}


void Entity::add_component(Component* comp) {
		components[typeid(*comp)] = comp;
		comp->set_parent(this);
}

const std::unordered_map<std::type_index, Component*>& Entity::get_component_list() const {
	return components;
}


unsigned long Entity::get_id() const {
	return id;
}


void Entity::set_id(unsigned long value) {
	id = value;
}
