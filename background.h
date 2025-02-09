#pragma once

#include <raylib.h>

#include "object.h"

class Background: public Object
{
    public:

        Background(Color color)
        {
            this->color = color;
        }

        ~Background(){}

        void update(){}

        void draw()
        {
            ClearBackground(color);
        }

    private:

        Color color;
};