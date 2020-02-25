#pragma once

#include "System.h"
#include "Sprite.h"
#include "AnimatedSprite.h"

class RenderSystem : public System {
public:
	void run(World& world) override;

private:
	void render_sprite(Sprite* spr, Transform* tr, World& world);
	void render_animated_sprite(AnimatedSprite* spr, Transform* tr, World& world);
};
