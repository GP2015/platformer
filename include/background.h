#pragma once

#include "raylib.h"

#include "object.h"

class Background : public Object
{
private:

	Color color = BLACK;

public:

	Background();
	
	void setColor(Color color);
	Color getColor();

	void update(), draw();
};