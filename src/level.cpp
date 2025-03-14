#include "level.h"

#include <vector>
#include "raylib.h"

#include "object.h"

Level::~Level()
{
	for (Object* object : objs)
		delete object;

	objs.clear();
}

void Level::update()
{
	for (Object* obj : objs)
		obj->update();

	BeginDrawing();

	for (Object* obj : objs)
		obj->draw();

	EndDrawing();
}

void Level::addObject(Object* obj)
{
	objs.push_back(obj);
}