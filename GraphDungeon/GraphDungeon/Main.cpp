#include "Dungeon.h"
#include "Hallway.h"

#include <iostream>

int main()
{
	int width = 4, heigth = 4;
	Dungeon dungeon;
	dungeon.displayDungeon(width, heigth);
	Hallway hallway;
	//std::cout << "Enemy level: " << hallway.getEnemy() << std::endl;
	Room room1;
	//room1.printRoom();
	getchar();
	return 0;
}