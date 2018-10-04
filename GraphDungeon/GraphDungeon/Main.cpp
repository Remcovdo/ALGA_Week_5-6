#include "Dungeon.h"
#include "Hallway.h"

#include <iostream>

int main()
{
	int width = 6, heigth = 5;
	Dungeon dungeon;
	for (int i = 0; i < width * heigth; i++)
	{
		dungeon.addRoom(new Room());
	}
	dungeon.setStartRoom(*dungeon.getRooms().at(2));
	dungeon.setEndRoom(dungeon.getRooms().at(28));
	dungeon.displayDungeon(width, heigth);

	dungeon.setStartRoom(*dungeon.getRooms().at(6));
	dungeon.displayDungeon(width, heigth);

	Hallway hallway;
	//std::cout << "Enemy level: " << hallway.getEnemy() << std::endl;
	getchar();
	return 0;
}