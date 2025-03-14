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

	void setPos(const std::string& str, float xpos, float ypos);

	void setXPos(char c, float xpos);
	void setYPos(char c, float ypos);

	void setGrounded(bool grounded);

	void setXVel(float xvel);
	void setYVel(float yvel);

	float left(), right(), top(), bottom();

	void update(), draw();
};