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
		Dungeon* dungeon = new Dungeon(2, 2);
		dungeon->displayDungeon();

		Player* player = new Player(dungeon);
		dungeon->addPlayer(player);
	
		//player->useGrenade();
		
		delete player;
		delete dungeon;

		getchar();
	}

	_CrtDumpMemoryLeaks();
	return 0;
}