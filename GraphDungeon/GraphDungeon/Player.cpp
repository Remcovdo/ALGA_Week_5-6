#include "Player.h"
#include "Dungeon.h"

#include <set>

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
	std::set<Room*> visitedRooms;
	std::set<Hallway*> choosableHallways;
	visitedRooms.insert(dungeon->getStartRoom());

	for (int i = 0; i < dungeon->getRooms().size() - 1; i++)
	{
		choosableHallways.clear();
		for (Room* visitedRoom : visitedRooms)
		{
			for (int i = 0; i < 4; i++)
				if (visitedRoom->getHallway(i) != nullptr)
				{
					Room* firstRoom = visitedRoom->getHallway(i)->getRoom(0);
					Room* secondRoom = visitedRoom->getHallway(i)->getRoom(1);

					if (!(visitedRooms.count(firstRoom) && visitedRooms.count(secondRoom)))
						choosableHallways.insert(visitedRoom->getHallway(i));
				}
		}

		Hallway* safeRoute = nullptr;
		for (Hallway* choosableHallway : choosableHallways)
		{
			if (safeRoute == nullptr || choosableHallway->getEnemy() < safeRoute->getEnemy())
				safeRoute = choosableHallway;
		}

		visitedRooms.insert(safeRoute->getRoom(0));
		visitedRooms.insert(safeRoute->getRoom(1));
	}
}
