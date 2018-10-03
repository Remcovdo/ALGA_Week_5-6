#pragma once

#include "Room.h"
#include "Hallway.h"

class Dungeon
{
	public:
		Dungeon();
		~Dungeon();

	private:
		Room start;
		Room end;

	public:
		void changeStartRoom();
		void changeEndRoom();
		void displayDungeon();
};

