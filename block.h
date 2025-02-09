#pragma once

#include <raylib.h>

#include "defs.h"
#include "object.h"

class Block: public Object
{
    public:

        Block(int xpos, int ypos, int width, int height)
        {
            this->xpos = xpos;
            this->ypos = ypos;
            this->width = width;
            this->height = height;
        }

        void update(){}

        void draw()
        {
            DrawRectangle(R(xpos), R(ypos), R(width), R(height), GREEN);
        }

    private:

        int xpos;
        int ypos;
        int width;
        int height;
};