#pragma once

#include <vector>

#include "Room.h"

class Dungeon;

class Player
{
	public:
		Player(Dungeon* dungeon);
		~Player();

	private:
		Dungeon* dungeon;
		std::vector<Room*> safestRoute;

		void destroyRandomHallway();
		void createMinimumSpanningTree();
		void displaySafestRoute();

	public:
		void useTalisman();
		void useGrenade();
		void useCompass();
};

