#ifndef __WORLD_H
#define __WORLD_H

#include "Entity.h"

#include <vector>


class World {
private:
	std::vector<Entity*> entity_list;

public:
	World();
	~World();

	const std::vector<Entity*>& get_entity_list() const;
};

#endif
