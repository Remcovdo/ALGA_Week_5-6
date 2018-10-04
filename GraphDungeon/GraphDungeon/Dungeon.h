#pragma once

#include <vector>
#include <map>

#include "Room.h"
#include "Hallway.h"

class Dungeon
{
	public:
		Dungeon();
		~Dungeon();

	private:
		unsigned int width;
		unsigned int height;
		Room* startRoom;
		Room* endRoom;
		std::vector<Room*> rooms;
		std::vector<Hallway*> hallways;

	public:
		void setStartRoom(Room* startRoom);
		void setEndRoom(Room* endRoom);
		void displayDungeon();
};

