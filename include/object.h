#pragma once

enum class OBJ_TYPE
{
	BACKGROUND,
	PLAYER
};

class Object
{
public:
	virtual ~Object() = default;
	virtual void update() = 0;
	virtual void draw() = 0;
};