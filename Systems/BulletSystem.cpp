#include "BulletSystem.h"

#include <iostream>

#include "World.h"

void BulletSystem::run(World& world) {
	if (world.components_exist_of_type<BulletComponent>()) {
		for (auto b : world.get_components<BulletComponent>()) {
		//for (size_t i = 0; i < world.get_components<BulletComponent>().size(); i++) {
			//BulletComponent* p = world.get_components<BulletComponent>()[i];
			move_bullet(world.delta_time(), b, world);
		}
	}
}


void BulletSystem::move_bullet(double delta, BulletComponent* player, World& world) {
	
}
