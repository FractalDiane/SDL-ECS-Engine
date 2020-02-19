#ifndef __ENTITY_H
#define __ENTITY_H

#include "Component.h"

#include <unordered_map>
#include <typeindex>
#include <typeinfo>

class Component;

class Entity {
private:
	std::unordered_map<std::type_index, Component*> components;

public:
	template <typename C>
	C* get_component() const {
		return static_cast<C*>(components.at(typeid(C)));
	}

	void add_component(Component* comp);
	const std::unordered_map<std::type_index, Component*>& get_component_list() const;

public:
	Entity();
	virtual ~Entity();
};

#endif
