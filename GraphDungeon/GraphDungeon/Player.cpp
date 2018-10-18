#include "Player.h"
#include "Dungeon.h"

#include <set>
#include <vector>
#include <map>
#include <iostream>

Player::Player(Dungeon* dungeon) : dungeon { dungeon }
{

}

Player::~Player()
{

}

void Player::useTalisman()
{
	Room* startRoom = dungeon->getStartRoom();
	Room* endRoom = dungeon->getEndRoom();
	std::set<Room*> visitedRooms;
	visitedRooms.insert(startRoom);
	int stepsToEndRoom = 0;
	
	while (true)	// Keep searching for the endRoom unitl it's found
	{
		for (Room* room : visitedRooms)
			if (room == endRoom)
			{
				std::cout << "De talisman fluistert dat het eindpunt " << stepsToEndRoom << " stap(pen) van u vandaan is!" << std::endl;
				std::cout << std::endl;
				return;
			}

		std::set<Room*> tempVisitedRooms = visitedRooms;

		for (Room* room : tempVisitedRooms)
			for (int i = 0; i < 4; i++)
				if (room->getHallway(i) != nullptr && !room->getHallway(i)->isDestroyed())
				{
					visitedRooms.insert(room->getHallway(i)->getRoom(0));
					visitedRooms.insert(room->getHallway(i)->getRoom(1));
				}

		stepsToEndRoom++;
	}
}

void Player::useGrenade()
{
	destroyRandomHallway();
	createMinimumSpanningTree();

	std::cout << "De tegenstander in een aangrenzende hallway is vermorzeld!" << std::endl;
	std::cout << "Verschillende gedeeltes van de kerker zijn ingestort..." << std::endl;
	std::cout << std::endl;
}

void Player::useCompass()
{
	Room* startRoom = dungeon->getStartRoom();
	Room* endRoom = dungeon->getEndRoom();

	displaySafestRoute();
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
	std::set<Room*> visitedRooms;								// Rooms that have been visited by the algorithm 		
	std::set<Hallway*> choosableHallways;						// Hallways that might be part of the MST
	std::set<Hallway*> hallwaysMST;								// Hallways that are part of the MST
	std::vector<Hallway*> hallways = dungeon->getHallways();	// All Hallways in the Dungeon

 	visitedRooms.insert(dungeon->getStartRoom());				// Start the algorithm at the startRoom of the Dungeon

	for (int i = 0; i < dungeon->getRooms().size() - 1; i++)	// Execute for all other Rooms in the Dungeon except the startRoom
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
			if (safeRoute == nullptr || choosableHallway->getEnemy() < safeRoute->getEnemy())
				safeRoute = choosableHallway;

		hallwaysMST.insert(safeRoute);
		visitedRooms.insert(safeRoute->getRoom(0));
		visitedRooms.insert(safeRoute->getRoom(1));
	}

	for (Hallway* hallway : hallways)	// Destory all hallways that aren't part of the MST
		if (hallwaysMST.find(hallway) == hallwaysMST.end())
			hallway->destroyHallway();
}

void Player::displaySafestRoute()
{
	for (int i = 0; i < safestRoute.size(); i++)
	{
		Room* previousRoom;
		Room* currentRoom = safestRoute.at(i);

		if (i != 0)
			previousRoom = safestRoute.at(i - 1);
		else
			previousRoom = dungeon->getStartRoom();

		for (int j = 0; j < 4; j++)
			if (currentRoom->getHallway(j) != nullptr)
			{
				if (j == 0 && currentRoom->getHallway(j)->getRoom(0) == previousRoom)
					std::cout << "Zuid (" << currentRoom->getHallway(j)->getEnemy()  << ")";

				if (j == 1 && currentRoom->getHallway(j)->getRoom(1) == previousRoom)
					std::cout << "West (" << currentRoom->getHallway(j)->getEnemy() << ")";

				if (j == 2 && currentRoom->getHallway(j)->getRoom(1) == previousRoom)
					std::cout << "Noord (" << currentRoom->getHallway(j)->getEnemy() << ")";

				if (j == 3 && currentRoom->getHallway(j)->getRoom(0) == previousRoom)
					std::cout << "Oost (" << currentRoom->getHallway(j)->getEnemy() << ")";
			}

		if (i < safestRoute.size() - 1)
			std::cout << " - ";
	}

	std::cout << std::endl;
}

