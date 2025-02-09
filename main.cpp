#include <raylib.h>

#include "defs.h"
#include "level01.h"

int main()
{
    InitWindow(GAME_WIDTH * RESOLUTION, GAME_HEIGHT * RESOLUTION, "Platformer Game");
    SetTargetFPS(60);

    Level01* level01 = new Level01();

    while (WindowShouldClose() == false)
    {
        level01->update();
        level01->draw();
    }

    CloseWindow();
}