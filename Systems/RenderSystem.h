#pragma once

#include "System.h"
#include "SpriteRenderer.h"

class RenderSystem : public System {
public:
	void run(World& world) override;

private:
	void render_sprite(SpriteRenderer* spr, World& world);
};
