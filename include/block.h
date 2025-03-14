#pragma once

#include <string>
#include <raylib.h>

#include "object.h"
#include "player.h"

#define BLOCK_TOP_PUSH 5
#define BLOCK_BOTTOM_PUSH 5
#define BLOCK_SIDE_PUSH 20

class Block : public Object
{
private:

	float xpos, ypos;
	float width, height;
	Color color;
	Player* plyr;
	float left(), right(), top(), bottom();

public:

	void setShape(std::string str, float xpos, float ypos, float width, float height);
	void setColor(Color color);
	void linkPlayer(Player* plyr);
	void update(), draw();
};