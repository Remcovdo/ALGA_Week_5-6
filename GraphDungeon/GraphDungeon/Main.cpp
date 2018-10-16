#include "Dungeon.h"
#include "Player.h"
#include "Room.h"
#include "Hallway.h"

#define _CRTDBG_MAP_ALLOC  
#include <stdlib.h>  
#include <crtdbg.h>
#include <time.h>
#include <iostream>

int main()
{
	srand(time(NULL));

	{
		Dungeon* dungeon = new Dungeon(6, 4);
		Player* player = new Player(dungeon);
		dungeon->addPlayer(player);
	
		dungeon->displayDungeon();
		player->useTalisman();
		player->useGrenade();

		dungeon->displayDungeon();
		player->useTalisman();

		delete player;
		delete dungeon;

		getchar();
	}

	_CrtDumpMemoryLeaks();
	return 0;
}