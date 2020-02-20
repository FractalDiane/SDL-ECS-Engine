#pragma once

#include "System.h"
#include "Sprite.h"

class RenderSystem : public System {
public:
	void run(World& world) override;

private:
	void render_sprite(Sprite* spr, Transform* tr, World& world);
};
