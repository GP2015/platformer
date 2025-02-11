#pragma once

#include <string>
#include "raylib.h"

#include "defs.h"
#include "object.h"

class Block : public Object
{
    public:

        Block() = default;
        ~Block() = default;

        void setShape(std::string str, float xpos, float ypos, float width, float height)
        {
            switch(str[0])
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

            switch(str[1])
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

        void setColor(Color color)
        {
            this->color = color;
        }

        void linkPlayer(Player* plyr)
        {
            this->plyr = plyr;
        }

        void update()
        {
            // Insert player changing code here
            return;
        }

        void draw()
        {
            DrawRectangle(R(xpos), R(ypos), R(width), R(height), color);
        }

    private:

        int xpos = 0;
        int ypos = 0;
        int width = 1;
        int height = 1;

        Color color = GREEN;

        Player* plyr;
};