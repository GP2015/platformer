#pragma once

#include <vector>
#include "raylib.h"

#include "object.h"
#include "background.h"
#include "player.h"
#include "block.h"

using namespace std;

class Level01
{
    public:

        Level01()
        {
            objects.push_back(new Background({0, 255, 255, 1}));
            objects.push_back(new Player(40, 100));
            //objects.push_back(new Block(0, 0, 100, 100));
        }

        ~Level01()
        {
            objects.clear();
        }

        void update()
        {
            for(unsigned int i = 0; i < objects.size(); i++)
                objects[i]->update();
        }

        void draw()
        {
            BeginDrawing();

            for(unsigned int i = 0; i < objects.size(); i++)
                objects[i]->draw();
            
            EndDrawing();
        }

    private:

        std::vector<Object*> objects;
};