#pragma once

#include <vector>

#include "object.h"

class Level
{
public:
	std::vector<Object*> objs;
	~Level();
	void update();
	void addObject(Object* obj);
};