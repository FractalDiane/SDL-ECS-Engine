#include "Behavior.h"

void Behavior::_ready() {}
void Behavior::_process(float delta) {}


void Behavior::_comp_ready() {
	_ready();
}

void Behavior::_comp_process(float delta, SDL_Surface* window_surface) {
	_process(delta);
}
