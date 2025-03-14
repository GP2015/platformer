#include "block.h"

#include <string>
#include "raylib.h"

#include "defs.h"
#include "player.h"

#include <stdio.h>

const int topPush = 5;
const int bottomPush = 5;
const int sidePush = 20;

Block::Block(Player* plyr)
{
	setShape("tl", 0, 0, 1, 1);
	setColor(BLACK);
	this->plyr = plyr;
}

void Block::setShape(std::string str, float xpos, float ypos, float width, float height)
{
	this->width = width;
	this->height = height;

	setYPos(str[0], ypos);
	setXPos(str[1], xpos);
}

void Block::setPos(std::string str, float xpos, float ypos)
{
	setYPos(str[0], ypos);
	setXPos(str[1], xpos);
}

void Block::setXPos(char c, float xpos)
{
	switch (c)
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
}

void Block::setYPos(char c, float ypos)
{
	switch (c)
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
}

void Block::setSize(float width, float height)
{
	this->width = width;
	this->height = height;
}

void Block::setWidth(float width)
{
	this->width = width;
}

void Block::setHeight(float height)
{
	this->height = height;
}

void Block::setColor(Color color)
{
	this->color = color;
}

void Block::update()
{
	bool plyrOnX = left() < plyr->right() && plyr->left() < right();
	bool plyrOnY = top() < plyr->bottom() && plyr->top() < bottom();

	if (plyrOnX && top() < plyr->bottom() && plyr->bottom() - top() < topPush)
	{
		plyr->setYPos('b', top());
		plyr->setYVel(0);
		plyr->setGrounded(true);
	}
	else if (plyrOnY && left() < plyr->right() && plyr->right() - left() < sidePush)
	{
		plyr->setXPos('r', left());
		plyr->setXVel(0);
	}
	else if (plyrOnY && plyr->left() < right() && right() - plyr->left() < sidePush)
	{
		plyr->setXPos('l', right());
		plyr->setXVel(0);
	}
	else if (plyrOnX && plyr->top() < bottom() && bottom() - plyr->top() < topPush)
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

float Block::left() { return xpos; }
float Block::right() { return xpos + width; }
float Block::top() { return ypos; }
float Block::bottom() { return ypos + height; }