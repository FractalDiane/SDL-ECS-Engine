#include "CustomBehavior.h"

#include "Input.h"
#include "Entity.h"
#include "Transform.h"

#include <iostream>

void CustomBehavior::_ready() {
	std::cout << "Ready called\n";
}


void CustomBehavior::_process(float delta) {
	int x1 = Input::is_key_held(SDLK_RIGHT) ? 1 : 0;
	int x2 = Input::is_key_held(SDLK_LEFT) ? 1 : 0;
	int y1 = Input::is_key_held(SDLK_DOWN) ? 1 : 0;
	int y2 = Input::is_key_held(SDLK_UP) ? 1 : 0;

	const float speed = 100;
	Vector2 vel = Vector2{x1 - x2, y1 - y2}.normalized() * speed * delta;

	Vector2 pos = parent->get_component<Transform>()->get_position();
	parent->get_component<Transform>()->set_position(Vector2{pos + vel});
}
