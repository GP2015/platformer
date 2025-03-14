#include "player.h"

#include <string>
#include "raylib.h"

#include "defs.h"
#include "object.h"

#define PLYR_WIDTH 10
#define PLYR_HEIGHT 10

#define PLYR_X_ACC 0.2
#define PLYR_X_VEL_MAX 2

#define PLYR_JUMP_VEL 2.5
#define PLYR_GRAVITY 0.1

void Player::setPos(std::string str, float xpos, float ypos)
{
	setYPos(str[0], ypos);
	setXPos(str[1], xpos);
}

void Player::setXPos(char c, float xpos)
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

void Player::setYPos(char c, float ypos)
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

void Player::setGrounded(bool grounded)
{
	this->grounded = grounded;
}

void Player::setXVel(float xvel)
{
	this->xvel = xvel;
}

void Player::setYVel(float yvel)
{
	this->yvel = yvel;
}

float Player::getXPos() { return xpos; }
float Player::getYPos() { return ypos; }
float Player::getXVel() { return xvel; }
float Player::getYVel() { return yvel; }
float Player::getWidth() { return width; }
float Player::getHeight() { return height; }
bool Player::getGrounded() { return grounded; }

float Player::left() { return xpos; }
float Player::right() { return xpos + width; }
float Player::top() { return ypos; }
float Player::bottom() { return ypos + height; }

void Player::update()
{
	if (IsKeyDown(KEY_RIGHT) && !IsKeyDown(KEY_LEFT))
	{
		if (xvel > PLYR_X_VEL_MAX - PLYR_X_ACC) xvel = PLYR_X_VEL_MAX;
		else xvel += PLYR_X_ACC;
	}
	else if (IsKeyDown(KEY_LEFT) && !IsKeyDown(KEY_RIGHT))
	{
		if (xvel < -PLYR_X_VEL_MAX + PLYR_X_ACC) xvel = -PLYR_X_VEL_MAX;
		else xvel -= PLYR_X_ACC;
	}
	else
	{
		if (xvel > PLYR_X_ACC) xvel -= PLYR_X_ACC;
		else if (xvel < -PLYR_X_ACC) xvel += PLYR_X_ACC;
		else xvel = 0;
	}

	if (grounded)
	{
		if (IsKeyDown(KEY_UP))
		{
			yvel = -PLYR_JUMP_VEL;
		}
		else
		{
			yvel = 0;
		}
	}
	else
	{
		yvel += PLYR_GRAVITY;
	}

	xpos += xvel;
	ypos += yvel;
	grounded = false;
}

void Player::draw()
{
	DrawRectangle(R(xpos), R(ypos), R(width), R(height), RED);
}