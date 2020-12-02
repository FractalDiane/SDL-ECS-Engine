#include "BulletSystem.h"

#include "Core/World.h"
#include "Components/Transform.h"

void BulletSystem::run(World& world) {
	if (world.components_exist_of_type<BulletComponent>()) {
		for (auto* b : world.get_components<BulletComponent>()) {
			move_bullet(world.delta_time(), b, world);
		}
	}
}


void BulletSystem::move_bullet(double delta, BulletComponent* bullet, World& world) {
	Vector2 pos = bullet->get_owner_component<Transform>()->get_position_from_parent();
	if (pos.x < -20 || pos.x > 660 || pos.y < -20 || pos.y > 500) {
		world.destroy_entity(bullet->get_owner());
		return;
	}
	
	Vector2 vel = bullet->get_velocity() * bullet->get_speed() * delta;

	bullet->get_owner_component<Transform>()->set_position(Vector2{pos + vel});
}
