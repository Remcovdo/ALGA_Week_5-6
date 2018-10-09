#include "Hallway.h"
#include "Room.h"

#include <stdlib.h>

Hallway::Hallway(Room* firstRoom, Room* secondRoom) : enemy { rand() % 10 }, destroyed { false }, rooms{ firstRoom, secondRoom }
{

}

Hallway::~Hallway()
{

}

int Hallway::getEnemy() const
{
	return this->enemy;
}

void Hallway::destroyEnemy()
{
	this->enemy = 0;
}

bool Hallway::isDestroyed() const
{
	return this->destroyed;
}

void Hallway::destroyHallway()
{	
	this->destroyed = true;
}

Room* Hallway::getRoom(int index) const
{
	if (index == 0 || index == 1)
		return this->rooms[index];
	else
		return nullptr;
}

