#include "background.h"

Background::Background()
{
	setColor(BLACK);
}

void Background::setColor(Color color)
{
	this->color = color;
}

Color Background::getColor() { return color; }

void Background::update() { return; }

void Background::draw()
{
	ClearBackground(color);
}