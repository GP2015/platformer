#pragma once

#include <vector>

#include "object.h"
#include "background.h"
#include "player.h"
#include "block.h"

class Level
{
public:

	std::vector<Object*> objs;

	Level() = default;

	~Level()
	{
		for (Object* object : objs)
			delete object;

		objs.clear();
	}

	void update()
	{
		for (Object* obj : objs)
			obj->update();

		BeginDrawing();

		for (Object* obj : objs)
			obj->draw();

		EndDrawing();
	}

	void addObject(Object* obj)
	{
		objs.push_back(obj);
	}
};