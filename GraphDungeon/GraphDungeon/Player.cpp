#include "Player.h"
#include "Dungeon.h"

#include <set>
#include <vector>
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

void Player::useCompass()
{
	Room* startRoom = dungeon->getStartRoom();
	Room* endRoom = dungeon->getEndRoom();
	std::vector<Room*> dungeonRooms = dungeon->getRooms();
	struct dijkstraRoom
	{
		Room* room;
		Room* prevRoom;
		int weight;
		bool visited;
	};
	std::set<dijkstraRoom*> rooms;


	for (Room* room : dungeonRooms)
	{
		if (room->isStartRoom())
		{
			dijkstraRoom *dr = new dijkstraRoom();
			dr->room = room;
			dr->prevRoom = nullptr;
			dr->weight = 0;
			dr->visited = false;
			rooms.insert(dr);
		}
		else
		{
			dijkstraRoom *dr = new dijkstraRoom();
			dr->room = room;
			dr->prevRoom = nullptr;
			dr->weight = 1000000;
			dr->visited = false;
			rooms.insert(dr);
		}
	}
	
	for (dijkstraRoom* dR : rooms)
	{
		if (dR->room->isStartRoom())
		{
			for (int i = 0; i < 4; i++)
			{
				if (dR->room->getHallway(i) != nullptr)
				{
					Room* temp = nullptr;
					for (int j = 0; j < 2; j++)
					{
						if (dR->room->getHallway(i)->getRoom(j) != dR->room)
						{
							temp = dR->room->getHallway(i)->getRoom(j);
						}
					}
					for (dijkstraRoom* kamer : rooms)
					{
						if (kamer->room == temp)
						{
							if (kamer->room->getHallway(i) != nullptr)
							{
								if (kamer->room->getHallway(i)->getEnemy() < kamer->weight)
								{
									kamer->weight = kamer->room->getHallway(i)->getEnemy() + dR->weight;
									kamer->prevRoom = dR->room;
								}
							}
						}
					}
				}
			}
			dR->visited = true;
		}
	}

	for (dijkstraRoom* dR : rooms)
	{
		for (int i = 0; i < 4; i++)
		{
			if (dR->room->getHallway(i) != nullptr)
			{
				Room* temp = dR->room->getHallway(i)->getRoom(1);
				for (dijkstraRoom* kamer : rooms)
				{
					if (kamer->room == temp)
					{
						if (kamer->room->getHallway(i) != nullptr)
						{
							if (kamer->room->getHallway(i)->getEnemy() < kamer->weight)
							{
								kamer->weight = kamer->room->getHallway(i)->getEnemy() + dR->weight;
								kamer->prevRoom = dR->room;
							}
						}
					}
				}
			}
		}
		dR->visited = true;
	}

	for (dijkstraRoom* dR : rooms)
	{
		if (dR->room->isEndRoom())
		{
			//endroom zoeken in de dijkstraRooms en vanaf daar de route teruglopen
		}
	}

	//alle rooms hebben oneindig zwaarte
		//zwaarte (wat je hebt + edge) minder dan huidige zwaarte van node? + afstand lager?
			//ja - update zwaarte en vanaf welke room je komt
	//doen totdat alle rooms zijn gevisit

	//vanaf dan kan je de route teruglopen vanaf de endroom tot er geen previous meer is en het totale gewicht heb je ook
	//dan heb je alle rooms en moet je de hallways nog in een route opslaan en die returnen
}
