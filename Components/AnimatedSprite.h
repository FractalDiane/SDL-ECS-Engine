#pragma once

#include "Component.h"
#include "Transform.h"
#include "Vector2.h"
#include "Mathf.h"

#include <vector>
#include <initializer_list>

#ifdef _WIN32
#include <SDL_image.h>
#else
#include <SDL2/SDL_image.h>
#endif

class AnimatedSprite : public Component {
private:
	std::vector<SDL_Texture*> sprite_frames;
	std::vector<Vector2I> sprite_sizes;
	const std::vector<unsigned int> image_sequence;
	float animation_speed;
	unsigned int frame;
	double anim_time;

public:
	AnimatedSprite(std::initializer_list<const char*> image_files, std::initializer_list<unsigned int> image_sequence, float animation_speed_ = 5.0f);
	~AnimatedSprite();

	const std::vector<SDL_Texture*>& get_sprite_frames() { return sprite_frames; }
	SDL_Texture* current_frame_texture() { return sprite_frames[image_sequence[frame]]; }

	float get_animation_speed() { return animation_speed; }
	void set_animation_speed(const float& value) { animation_speed = value; }

	unsigned int current_frame() { return frame; }
	void advance_frame() { frame = Mathf::wrap(++frame, 0, image_sequence.size() - 1); }

	double get_anim_time() { return anim_time; }
	void add_anim_time(const double& value) { anim_time += value; }
	void reset_anim_time() { anim_time = 0; }

	const Vector2I& sprite_size() { return sprite_sizes[image_sequence[frame]]; }
};
