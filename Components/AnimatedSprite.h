#pragma once

#include "Components/Component.h"
#include "Components/Transform.h"
#include "Core/Vector2.h"
#include "Core/Mathf.h"

#include "Core/ECSSystem.h"

#include <vector>
#include <unordered_map>
#include <initializer_list>
#include <string>

#if defined(_WIN32) && 0
#include <SDL_image.h>
#else
#include <SDL2/SDL_image.h>
#endif

class AnimatedSprite : public Component {
private:
	struct Animation {
		std::vector<unsigned int> image_sequence;
		float fps;
	};

	std::vector<SDL_Texture*> textures;
	std::vector<Vector2I> texture_sizes;
	std::unordered_map<std::string, Animation*> animations;
	std::string current_animation;
	float animation_speed;
	unsigned int frame;
	double anim_time;

	bool centered = false;

public:
	AnimatedSprite();
	~AnimatedSprite();

	bool has_animations() { return animations.size() > 0; }

	void add_textures(std::initializer_list<const char*> image_files);
	void add_animation(const std::string& name, std::initializer_list<unsigned int> image_sequence, float animation_speed_ = 5.0f);

	SDL_Texture* current_frame_texture() { return textures[animations[current_animation]->image_sequence[frame]]; }

	void play_animation(const std::string& animation);
	const std::string& get_current_animation() { return current_animation; }

	float get_animation_speed() { return animations[current_animation]->fps; }
	//void set_animation_speed(const float& value) { animation_speed = value; }

	unsigned int current_frame() { return frame; }
	void advance_frame() { frame = Mathf::wrap(++frame, 0, animations[current_animation]->image_sequence.size() - 1); }

	double get_anim_time() { return anim_time; }
	void add_anim_time(const double& value) { anim_time += value; }
	void reset_anim_time() { anim_time = 0; }

	const Vector2I& sprite_size() { return texture_sizes[animations[current_animation]->image_sequence[frame]]; }

	bool is_centered() { return centered; }
	void set_centered(bool value) { centered = value; }
};
