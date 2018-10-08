#include "Dungeon.h"

#include <iostream>

Dungeon::Dungeon(unsigned int width, unsigned int height) : width{ width }, height{ height }
{
	for (int i = 0; i < (width * height); i++)								// Alle Rooms aanmaken
		addRoom(new Room());												// Handgranaten of Binary Space Partition
																		
	for (int a = 0; a < height; a++)
	{
		for (int b = 0; b < (width - 1); b++)
		{
			Room* firstRoom = rooms.at(a * width + b);
			Room* secondRoom = rooms.at(a * width + b + 1);
			Hallway* hallway = new Hallway(firstRoom, secondRoom);
			addHallway(hallway);
			firstRoom->addHallway(hallway, 1);
			secondRoom->addHallway(hallway, 3);
		}
	}

	for (int a = 0; a < (height - 1); a++)
	{
		for (int b = 0; b < width; b++)
		{
			Room* firstRoom = rooms.at(a * width + b);
			Room* secondRoom = rooms.at((a + 1) * width + b);
			Hallway* hallway = new Hallway(firstRoom, secondRoom);
			addHallway(hallway);
			firstRoom->addHallway(hallway, 2);
			secondRoom->addHallway(hallway, 0);
		}
	}
}

Dungeon::~Dungeon()
{
	for (Room* room : rooms)
		delete room;

	for (Hallway* hallway : hallways)
		delete hallway;
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
	std::cout << "Dungeon" << std::endl;
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
			std::cout << "\t" << type;
		}

		std::cout << std::endl;
	}
}

void Dungeon::printConnections() const
{
	for (int i = 0; i < width; i++)
	{
		std::cout << '\t' << '|';
	}
	std::cout << std::endl;
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
