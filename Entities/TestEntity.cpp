#include "TestEntity.h"

#include <iostream>

TestEntity::TestEntity() : timer{0} {}


void TestEntity::_ready() {
	set_process_enabled(true);
}


void TestEntity::_process(float delta) {
	timer += delta;
	//std::cout << timer << "\n";

	Vector2 pos = get_position();
	set_position(Vector2{pos.x + 20 * delta, pos.y});
}
