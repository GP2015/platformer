#pragma once

#include <string>
#include "raylib.h"

#include "object.h"
#include "player.h"

class Block : public Object
{
private:

	float xpos, ypos;
	float width, height;
	Color color;
	Player* plyr;
	
	float left(), right(), top(), bottom();

public:

	Block(Player* plyr);
	
	void setShape(std::string str, float xpos, float ypos, float width, float height);
	
	void setPos(std::string str, float xpos, float ypos);
	void setXPos(char c, float xpos);
	void setYPos(char c, float ypos);
	
	void setSize(float width, float height);
	void setWidth(float width);
	void setHeight(float height);
	
	void setColor(Color color);
	
	void update(), draw();
};