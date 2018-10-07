#include "Dungeon.h"
#include "Hallway.h"

#include <iostream>

int main()
{
	Dungeon dungeon(6,5);
	for (int i = 0; i < 6 * 5; i++)
	{
		dungeon.addRoom(new Room());
	}
	dungeon.setStartRoom(*dungeon.getRooms().at(2));
	dungeon.setEndRoom(*dungeon.getRooms().at(28));
	dungeon.displayDungeon();

	dungeon.setStartRoom(*dungeon.getRooms().at(6));
	dungeon.displayDungeon();

	getchar();
	return 0;
}