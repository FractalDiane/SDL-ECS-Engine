#include "TestEntity.h"

#include <iostream>

TestEntity::TestEntity() : timer{0} {}


void TestEntity::_ready() {

}


void TestEntity::_process(float delta) {
	timer += delta;
	//std::cout << timer << "\n";
}
