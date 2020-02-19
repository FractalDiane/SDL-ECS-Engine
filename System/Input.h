#ifndef __INPUT_H
#define __INPUT_H

#include <SDL2/SDL_keyboard.h>
#include <SDL2/SDL_joystick.h>
#include <SDL2/SDL_events.h>

#include <unordered_set>

class Input {
private:
	static std::unordered_set<SDL_Keycode> pressed_keys;
	static std::unordered_set<SDL_Keycode> pressed_keys_momentary;
	static std::unordered_set<SDL_Keycode> released_keys_momentary;

	Input();
	~Input();

public:
	enum class KeyEventType { Pressed, Released };

	static bool is_key_pressed(SDL_Keycode key);
	static bool is_key_held(SDL_Keycode key);
	static bool is_key_released(SDL_Keycode key);

	static void process_input_event(KeyEventType type, const SDL_Event& event);

	static void update_momentary_keys();
};

#endif
