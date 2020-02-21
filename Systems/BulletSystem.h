#pragma once

#include "System.h"
#include "BulletComponent.h"

class BulletSystem : public System {
public:
	void run(World& world) override;

private:
	void move_bullet(double delta, BulletComponent* bullet, World& world);
};
