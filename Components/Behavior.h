#ifndef __BEHAVIOR_H
#define __BEHAVIOR_H

#include "Component.h"

class Behavior : public Component {
public:
	virtual void _ready();
	virtual void _process(float delta);

	void _comp_ready() override;
	void _comp_process(float delta, SDL_Surface* window_surface) override;
};

#endif
