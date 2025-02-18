#pragma once

#include <vector>
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

class Player : public Object
{
public:

	float xpos = 0;
	float ypos = 0;
	float xvel = 0;
	float yvel = 0;
	bool grounded = false;
	float width = PLYR_WIDTH;
	float height = PLYR_HEIGHT;

	Player() = default;
	~Player() = default;

	void setPos(const std::string& str, float xpos, float ypos)
	{
		setYPos(str[0], ypos);
		setXPos(str[1], xpos);
	}

	void setXPos(char c, float xpos)
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

	void setYPos(char c, float ypos)
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

	void setGrounded(bool grounded)
	{
		this->grounded = grounded;
	}

	void setXVel(float xvel)
	{
		this->xvel = xvel;
	}

	void setYVel(float yvel)
	{
		this->yvel = yvel;
	}

	void update()
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

	void draw()
	{
		DrawRectangle(R(xpos), R(ypos), R(width), R(height), RED);
	}

	float left() { return xpos; }
	float right() { return xpos + width; }
	float top() { return ypos; }
	float bottom() { return ypos + height; }
};