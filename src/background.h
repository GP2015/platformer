#pragma once

#include "raylib.h"

#include "object.h"

class Background : public Object
{
public:

	Background() = default;
	~Background() = default;

	void setColor(Color color)
	{
		this->color = color;
	}

	void update() {}

	void draw()
	{
		ClearBackground(color);
	}

private:

	Color color = BLACK;
};