#include "level01.h"

#include "raylib.h"

#include "level.h"
#include "background.h"
#include "player.h"
#include "block.h"

Level* level01;

void setupLevel01()
{
	level01 = new Level();

	Background* bg = new Background();
	bg->setColor({ 0, 255, 255, 1 });
	level01->addObject(bg);

	Player* plyr = new Player();
	plyr->setPos("bc", 160, 130);
	level01->addObject(plyr);

	Block* blk = new Block(plyr);
	blk->setShape("bc", 160, 180, 200, 50);
	blk->setColor(GREEN);
	level01->addObject(blk);
}

void updateLevel01()
{
	level01->update();
}

void endLevel01()
{
	delete level01;
}