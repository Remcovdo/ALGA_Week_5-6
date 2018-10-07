#include "Hallway.h"

#include <stdlib.h>
#include <time.h>

Hallway::Hallway() : destroyed {false}
{
	srand(time(NULL));				// Generates randomizer seed with the current time
	this->enemy = (rand() % 10);	// Generates random number (% 10 causes it to be between 0-9)
}

Hallway::~Hallway()
{

}

unsigned int Hallway::getEnemy() const
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

