#include "raylib.h"

#include "defs.h"
#include "levelmanager.h"

int main()
{
    InitWindow(GAME_WIDTH * RESOLUTION, GAME_HEIGHT * RESOLUTION, "Platformer Game");
    SetTargetFPS(60);

    setupGame();

    while (WindowShouldClose() == false)
        updateGame();

    endGame();

    CloseWindow();
}