#ifndef __TEST_ENTITY_H
#define __TEST_ENTITY_H

#include "Entity.h"

class TestEntity : public Entity {
private:
	float timer;

public:
	TestEntity();

	void _ready() override;
	void _process(float delta) override;
};

#endif
