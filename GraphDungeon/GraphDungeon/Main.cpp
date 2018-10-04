#include <iostream>
#include "Dungeon.h"
#include "Hallway.h"

int main()
{
	Dungeon dungeon;
	dungeon.displayDungeon();
	Hallway hallway;
	std::cout << "Enemy level: " << hallway.getEnemy() << std::endl;
	std::getchar();
	return 0;
}