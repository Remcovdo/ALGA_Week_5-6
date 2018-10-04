#include "Dungeon.h"

#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

Dungeon::Dungeon()
{
	//generate: alle kamers aanmaken en handgranaten gebruiken
	//of binary space partition
}

Dungeon::~Dungeon()
{

}

void Dungeon::setStartRoom(Room& startRoom)
{
	if (this->startRoom != nullptr)
	{
		this->startRoom->setRoomtype('X');	//setNormalType
	}
	startRoom.setStartRoom();
	this->startRoom = &startRoom;
}

void Dungeon::setEndRoom(Room* endRoom)
{
	endRoom->setEndRoom();
}

void Dungeon::displayDungeon(int width, int heigth)
{
	cout << "Dungeon" << endl;
	char type = ' ';

	for (int i = 0; i < heigth; i++)
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

void Dungeon::addRoom(Room * room)
{
	if (room != nullptr)
	{
		rooms.push_back(room);
	}
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