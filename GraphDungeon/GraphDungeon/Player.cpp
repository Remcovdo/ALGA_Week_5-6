#include "Player.h"
#include "Dungeon.h"

#include <map>

Player::Player(Dungeon* dungeon) : dungeon { dungeon }
{

}

Player::~Player()
{

}

void Player::useTalisman()
{
	
}

void Player::useGrenade()
{
	destroyRandomHallway();
	createMinimumSpanningTree();
}

void Player::destroyRandomHallway()
{
	int hallway = rand() % 4;

	while (dungeon->getStartRoom()->getHallway(hallway) == nullptr)
		hallway = rand() % 4;

	dungeon->getStartRoom()->getHallway(hallway)->destroyEnemy();
}

void Player::createMinimumSpanningTree()
{
	std::vector<Hallway*> destroyableHallways;

	for (Hallway* hallway : destroyableHallways)
		hallway->destroyHallway();
}
