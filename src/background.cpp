#include "background.h"

void Background::setColor(Color color)
{
	this->color = color;
}

void Background::update()
{
	return;
}

void Background::draw()
{
	ClearBackground(color);
}