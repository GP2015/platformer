#include "block.h"

#include <string>
#include <raylib.h>

#include "defs.h"
#include "player.h"

void Block::setShape(std::string str, float xpos, float ypos, float width, float height)
{
	switch (str[0])
	{
	case 't':
		this->ypos = ypos;
		break;
	case 'c':
		this->ypos = ypos - height / 2;
		break;
	case 'b':
		this->ypos = ypos - height;
		break;
	}

	switch (str[1])
	{
	case 'l':
		this->xpos = xpos;
		break;
	case 'c':
		this->xpos = xpos - width / 2;
		break;
	case 'r':
		this->xpos = xpos - width;
		break;
	}

	this->width = width;
	this->height = height;
}

void Block::setColor(Color color)
{
	this->color = color;
}

void Block::linkPlayer(Player* plyr)
{
	this->plyr = plyr;
}

float Block::left() { return xpos; }
float Block::right() { return xpos + width; }
float Block::top() { return ypos; }
float Block::bottom() { return ypos + height; }

void Block::update()
{
	bool plyrOnX = left() < plyr->right() && plyr->left() < right();
	bool plyrOnY = top() < plyr->bottom() && plyr->top() < bottom();

	if (plyrOnX && top() < plyr->bottom() && plyr->bottom() - top() < BLOCK_TOP_PUSH)
	{
		plyr->setYPos('b', top());
		plyr->setYVel(0);
		plyr->setGrounded(true);
	}
	else if (plyrOnY && left() < plyr->right() && plyr->right() - left() < BLOCK_SIDE_PUSH)
	{
		plyr->setXPos('r', left());
		plyr->setXVel(0);
	}
	else if (plyrOnY && plyr->left() < right() && right() - plyr->left() < BLOCK_SIDE_PUSH)
	{
		plyr->setXPos('l', right());
		plyr->setXVel(0);
	}
	else if (plyrOnX && plyr->top() < bottom() && bottom() - plyr->top() < BLOCK_TOP_PUSH)
	{
		plyr->setYPos('t', bottom());
		plyr->setYVel(0);
	}

	return;
}

void Block::draw()
{
	DrawRectangle(R(xpos), R(ypos), R(width), R(height), color);
}
