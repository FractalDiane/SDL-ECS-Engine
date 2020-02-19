#ifndef __CUSTOM_BEHAVIOR_H
#define __CUSTOM_BEHAVIOR_H

#include "Behavior.h"

class CustomBehavior : public Behavior {
public:
	void _ready() override;
	void _process(float delta) override;
};

#endif
