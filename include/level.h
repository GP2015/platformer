#pragma once

#include <vector>

#include "object.h"

class Level
{
private:
	std::vector<Object*> objs;

public:
	~Level();
	void addObject(Object* obj);
	void update();
};