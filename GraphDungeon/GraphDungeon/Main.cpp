#include "Dungeon.h"
#include "Hallway.h"

#define _CRTDBG_MAP_ALLOC  
#include <stdlib.h>  
#include <crtdbg.h>  

int main()
{
	
	{
		Dungeon dungeon(6, 5);
		dungeon.displayDungeon();
	}

	_CrtDumpMemoryLeaks();
	return 0;
}