#pragma once

class Dungeon;

class Player
{
	public:
		Player(Dungeon* dungeon);
		~Player();

	private:
		Dungeon* dungeon;

	public:
		void useTalisman();
		void useGrenade();
		void destroyRandomHallway();
		void createMinimumSpanningTree();
};

