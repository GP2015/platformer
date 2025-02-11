#pragma once

#include <vector>
#include <string>
#include "raylib.h"

#include "defs.h"
#include "object.h"
#include "Object.h"

#define PLYR_WIDTH 10
#define PLYR_HEIGHT 10

#define PLYR_X_ACC 0.2
#define PLYR_X_VEL_MAX 2

#define PLYR_JUMP_VEL 10
#define PLYR_GRAVITY 0.1

class Player : public Object
{
    public:

        Player() = default;
        ~Player() = default;

        void setPosition(std::string str, float xpos, float ypos)
        {
            switch(str[0])
            {
                case 't':
                    this->ypos = ypos;
                    break;
                case 'c':
                    this->ypos = ypos - PLYR_HEIGHT / 2;
                    break;
                case 'b':
                    this->ypos = ypos - PLYR_HEIGHT;
                    break;
            }

            switch(str[1])
            {
                case 'l':
                    this->xpos = xpos;
                    break;
                case 'c':
                    this->xpos = xpos - PLYR_WIDTH / 2;
                    break;
                case 'r':
                    this->xpos = xpos - PLYR_WIDTH;
                    break;
            }
        }

        void setGround(bool grounded)
        {
            this->grounded = grounded;
        }

        void setXvelocity(float xvel)
        {
            this->xvel = xvel;
        }

        void setYvelocity(float yvel)
        {
            this->yvel = yvel;
        }
        
        void update()
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

            if(grounded)
            {
                if(IsKeyDown(KEY_UP))
                {
                    yvel = -PLYR_JUMP_VEL;
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
            DrawRectangle(R(xpos), R(ypos), R(PLYR_WIDTH), R(PLYR_HEIGHT), RED);
        }
    
    private:

        float xpos = 0;
        float ypos = 0;
        float xvel = 0;
        float yvel = 0;
        bool grounded = false;
};