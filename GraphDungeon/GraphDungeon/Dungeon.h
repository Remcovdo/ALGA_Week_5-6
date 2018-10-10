#pragma once

#include <vector>

#include "Room.h"
#include "Hallway.h"

class Player;

class Dungeon
{
	public:
		Dungeon(int width, int height);
		~Dungeon();

	private:
		int width;
		int height;
		Room* startRoom;
		Room* endRoom;
		Room* playerRoom;
		std::vector<Room*> rooms;
		std::vector<Hallway*> hallways;
		Player* player;

	public:
		Room* getStartRoom();
		void setStartRoom(Room& room);
		Room* getEndRoom();
		void setEndRoom(Room& room);
		void displayDungeon() const;
		void printConnections() const;
		void addRoom(Room* room);
		void addHallway(Hallway* hallway);
		void addPlayer(Player* player);
		std::vector<Room*> getRooms();
		std::vector<Hallway*> getHallways();
};

