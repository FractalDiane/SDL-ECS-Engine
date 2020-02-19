#ifndef __ENTITY_H
#define __ENTITY_H

#include "Vector2.h"
#include "Component.h"

#include <SDL2/SDL_surface.h>

#include <vector>
#include <typeinfo>

class Component;

class Entity {
private:
	Vector2 position;
	float rotation;
	Vector2 scale;

	std::vector<Component*> components;

public:
	template <typename C>
	C* get_component() const {
		for (auto c : components) {
			if (typeid(c) == typeid(C))
				return c;
		}

		return nullptr;
	}

	void add_component(Component* comp);
	const std::vector<Component*>& get_component_list() const;

public:
	Entity();
	virtual ~Entity();

	virtual void _ready();
	virtual void _process(float delta);

	Vector2 get_position() const;
	float get_rotation() const;
	Vector2 get_scale() const;

	void set_position(const Vector2& value);
	void set_rotation(const float& value);
	void set_scale(const Vector2& value);
};

#endif
