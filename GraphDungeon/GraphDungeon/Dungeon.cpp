#include "Dungeon.h"

#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

Dungeon::Dungeon(unsigned int width, unsigned int height) : width{ width }, height{ height }
{
	for (int i = 0; i < (width * height); i++)								// Alle Rooms aanmaken
		addRoom(new Room());												// Handgranaten of Binary Space Partition
																		
	int totalHallways = ((width - 1) * height) + ((height - 1) * width);	// Alle Hallways aanmaken
	for (int i = 0; i < totalHallways; i++)
		addHallway(new Hallway());
}

Dungeon::~Dungeon()
{

}

void Dungeon::setStartRoom(Room& room)
{
	room.setStartRoom();
	startRoom = &room;
}

void Dungeon::setEndRoom(Room& room)
{
	room.setEndRoom();
	endRoom = &room;
}

void Dungeon::displayDungeon() const
{
	cout << "Dungeon" << endl;
	char type = ' ';

	for (int i = 0; i < height; i++)
	{
		printConnections();
		for (int j = 0; j < width; j++)
		{
			if (rooms[j+i*width] != NULL)
			{
				type = rooms[j+i*width]->getRoomtype();
			}
			cout << "\t" << type;
		}

		cout << endl;
	}
}

void Dungeon::printConnections() const
{
	for (int i = 0; i < width; i++)
	{
		cout << '\t' << '|';
	}
	cout << endl;
}

void Dungeon::addRoom(Room* room)
{
	if (room != NULL)
		rooms.push_back(room);
}

void Dungeon::addHallway(Hallway* hallway)
{
	if (hallway != NULL)
		hallways.push_back(hallway);
}

vector<Room*> Dungeon::getRooms() const
{
	return rooms;
}
