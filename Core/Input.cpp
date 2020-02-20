#include "Input.h"

std::unordered_set<SDL_Keycode> Input::pressed_keys = {};
std::unordered_set<SDL_Keycode> Input::pressed_keys_momentary = {};
std::unordered_set<SDL_Keycode> Input::released_keys_momentary = {};

Input::Input() {}

Input::~Input() {}


bool Input::is_key_held(SDL_Keycode key) {
	return pressed_keys.find(key) != pressed_keys.end();
}


bool Input::is_key_pressed(SDL_Keycode key) {
	return pressed_keys_momentary.find(key) != pressed_keys_momentary.end();
}

bool Input::is_key_released(SDL_Keycode key) {
	return released_keys_momentary.find(key) != pressed_keys_momentary.end();
}


void Input::process_input_event(KeyEventType type, const SDL_Event& event) {
	switch (type) {
		case KeyEventType::Pressed: {
			pressed_keys.insert(event.key.keysym.sym);
			pressed_keys_momentary.insert(event.key.keysym.sym);
		} break;
		
		case KeyEventType::Released: {
			pressed_keys.erase(event.key.keysym.sym);
			released_keys_momentary.insert(event.key.keysym.sym);
		} break;
	}
}


void Input::update_momentary_keys() {
	pressed_keys_momentary.clear();
	released_keys_momentary.clear();
}
