#pragma once

#include <raylib.h>

#include "object.h"

class Background : public Object
{
private:
	Color color = BLACK;

public:
	void setColor(Color color);
	void update(), draw();
};