#pragma once

#include <vector>

#include "Room.h"
#include "Hallway.h"

class Dungeon
{
	public:
		Dungeon(unsigned int width, unsigned int height);
		~Dungeon();

	private:
		unsigned int width;
		unsigned int height;
		Room* startRoom;
		Room* endRoom;
		std::vector<Room*> rooms;
		std::vector<Hallway*> hallways;

	public:
		void setStartRoom(Room& room);
		void setEndRoom(Room& room);
		void displayDungeon() const;
		void printConnections() const;
		void addRoom(Room* room);
		void addHallway(Hallway* hallway);
};

