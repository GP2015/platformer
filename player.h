#pragma once

#include <raylib.h>

#include "defs.h"
#include "object.h"

#define PLYR_WIDTH 20
#define PLYR_HEIGHT 20

#define PLYR_X_ACC 1
#define PLYR_X_VEL_MAX 10

#define PLYR_JUMP_VEL 10
#define PLYR_GRAVITY 1

class Player: public Object
{
    public:

        Player(int xpos = 0, int ypos = 0)
        {
            this->xpos = 0;
            this->ypos = 0;
        }

        ~Player(){}

        void update()
        {
            updateVelocity();
            updatePosition();
        }

        void draw()
        {
            DrawRectangle(R(xpos), R(ypos), R(PLYR_WIDTH), R(PLYR_HEIGHT), RED);
        }
    
    private:

        int xpos = 0;
        int ypos = 0;
        int xvel = 0;
        int yvel = 0;

        void updateVelocity()
        {
            if(IsKeyDown(KEY_RIGHT) && !IsKeyDown(KEY_LEFT))
            {
                if(xvel > PLYR_X_VEL_MAX - PLYR_X_ACC) xvel = PLYR_X_VEL_MAX;
                else xvel += PLYR_X_ACC;   
            }
            else if(IsKeyDown(KEY_LEFT) && !IsKeyDown(KEY_RIGHT))
            {
                if(xvel < -PLYR_X_VEL_MAX + PLYR_X_ACC) xvel = -PLYR_X_VEL_MAX;
                else xvel -= PLYR_X_ACC;   
            }
            else
            {
                if(xvel > PLYR_X_ACC) xvel -= PLYR_X_ACC;
                else if(xvel < -PLYR_X_ACC) xvel += PLYR_X_ACC;
                else xvel = 0;
            }
        }

        void updatePosition()
        {
            xpos += xvel;
            ypos += yvel;
        }
};