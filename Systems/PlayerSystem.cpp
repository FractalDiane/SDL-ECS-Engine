#include "PlayerSystem.h"

#include "World.h"
#include "Input.h"

#include "Mathf.h"

#include "Transform.h"
#include "Sprite.h"
#include "BulletComponent.h"

void PlayerSystem::run(World& world) {
	if (world.components_exist_of_type<PlayerComponent>()) {
		for (auto* p : world.get_components<PlayerComponent>()) {
			player_input(world.delta_time(), p, world);
		}
	}
}


void PlayerSystem::player_input(double delta, PlayerComponent* player, World& world) {
	int x1 = Input::is_key_held(SDLK_RIGHT) || Input::is_key_held(SDLK_d) ? 1 : 0;
	int x2 = Input::is_key_held(SDLK_LEFT) || Input::is_key_held(SDLK_a) ? 1 : 0;
	int y1 = Input::is_key_held(SDLK_DOWN) || Input::is_key_held(SDLK_s) ? 1 : 0;
	int y2 = Input::is_key_held(SDLK_UP) || Input::is_key_held(SDLK_w) ? 1 : 0;

	Vector2 vel = Vector2{float(x1 - x2), float(y1 - y2)}.normalized() * player->get_speed() * delta;

	Vector2 pos = player->get_owner_component<Transform>()->get_position();
	
	player->get_owner_component<Transform>()->set_position(Vector2{pos + vel});

	if (Input::is_mouse_button_pressed(Input::MouseButton::ButtonLeft)) {
		fire_bullet(pos, world);
	}
}


void PlayerSystem::fire_bullet(const Vector2& player_pos, World& world) {
	Entity* bullet = new Entity{};
	Transform* bullet_tr = new Transform{};
	bullet_tr->set_position(player_pos);
	Sprite* bullet_spr = new Sprite{"../Sprites/Fireball.png"};
	BulletComponent* bullet_comp = new BulletComponent{};

	Vector2 dir = Vector2{-1, 0}.rotated(player_pos.angle_to(Window::get_mouse_position()));
	bullet_tr->set_rotation(Mathf::rad2deg(dir.angle()));
	bullet_tr->set_scale(Vector2{2, 2});
	bullet_comp->set_velocity(dir);

	bullet->add_component(bullet_tr);
	bullet->add_component(bullet_spr);
	bullet->add_component(bullet_comp);

	world.add_entity(bullet);
	world.add_component(bullet_tr);
	world.add_component(bullet_spr);
	world.add_component(bullet_comp);
}
