#include "Dungeon.h"

#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

Dungeon::Dungeon(unsigned int width, unsigned int height) : width{ width }, height{ height }
{
	//generate: alle kamers aanmaken en handgranaten gebruiken
	//of binary space partition
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

void Dungeon::displayDungeon()
{
	cout << "Dungeon" << endl;
	char type = ' ';

	for (int i = 0; i < height; i++)
	{
		printConnections(width);
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

void Dungeon::addRoom(Room* room)
{
	if (room != NULL)
		rooms.push_back(room);
}

vector<Room*> Dungeon::getRooms()
{
	return this->rooms;
}

void Dungeon::printConnections(int width)
{
	for (int i = 0; i < width; i++)
	{
		cout << '\t' << '|';
	}
	cout << endl;
}