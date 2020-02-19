#include "Entity.h"

#include <SDL2/SDL_image.h>

Entity::Entity() : position{Vector2(0, 0)}, rotation{0}, scale{Vector2(1, 1)}, process_enabled{false} {

}


Entity::~Entity() {
	
}


void Entity::add_component(Component* comp) {
		components.push_back(comp);
		comp->set_parent(this);
	}

const std::vector<Component*>& Entity::get_component_list() const {
	return components;
}


void Entity::_ready() {

}


void Entity::_process(float delta) {
	
}


Vector2 Entity::get_position() const {
	return position;
}


float Entity::get_rotation() const {
	return rotation;
}


Vector2 Entity::get_scale() const {
	return scale;
}


void Entity::set_position(const Vector2& value) {
	position = value;
}


void Entity::set_rotation(const float& value) {
	rotation = value;
}


void Entity::set_scale(const Vector2& value) {
	scale = value;
}


bool Entity::is_process_enabled() const {
	return process_enabled;
}


void Entity::set_process_enabled(bool value) {
	process_enabled = value;
}
