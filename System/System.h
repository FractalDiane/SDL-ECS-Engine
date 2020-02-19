#ifndef __SYSTEM_H
#define __SYSTEM_H

#include "World.h"

struct System {
	virtual void run(World& world) = 0;
};

#endif
