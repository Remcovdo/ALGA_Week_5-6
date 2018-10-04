#include "Dungeon.h"

#include <iostream>
#include <cstdlib>
#include <time.h>

Dungeon::Dungeon()
{

}

Dungeon::~Dungeon()
{

}

void Dungeon::setStartRoom(Room* startRoom)
{
	this->startRoom = startRoom;
}

void Dungeon::setEndRoom(Room* endRoom)
{
	this->endRoom = endRoom;
}

void Dungeon::displayDungeon()
{
	std::cout << "Dungeon" << std::endl;
}
