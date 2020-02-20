#pragma once

#include "Component.h"

#include <unordered_map>
#include <typeindex>
#include <typeinfo>

class Component;

class Entity {
private:
	unsigned long id;
	std::unordered_map<std::type_index, Component*> components;

public:
	template <typename C>
	C* get_component() const {
		return static_cast<C*>(components.at(typeid(C)));
	}

	void add_component(Component* comp);
	const std::unordered_map<std::type_index, Component*>& get_component_list() const;

	unsigned long get_id() const;
	void set_id(unsigned long value);

public:
	Entity(unsigned long id_);
	virtual ~Entity();
};
