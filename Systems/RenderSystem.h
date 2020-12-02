#pragma once

#include "Systems/System.h"
#include "Components/Sprite.h"
#include "Components/AnimatedSprite.h"
#include "Components/BoxCollider.h"

class RenderSystem : public System {
public:
	void run(World& world) override;

private:
	void render_sprite(Sprite* spr, Transform* tr, World& world);
	void render_animated_sprite(AnimatedSprite* spr, Transform* tr, World& world);
	void draw_collider(BoxCollider* coll, World& world);
};
