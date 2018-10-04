#include "Hallway.h"
#include <stdlib.h>
#include <time.h>

Hallway::Hallway() : destroyed {false}
{
	srand(time(NULL));
	this->enemy = (rand() % 10);
}

Hallway::~Hallway()
{

}

unsigned int Hallway::getEnemy() const
{
	return this->enemy;
}

void Hallway::destroy()
{
	this->enemy = 0;
}

bool Hallway::isDestroyed() const
{
	return this->destroyed;
}

void Hallway::setDestroyed(bool destroyed)
{
	this->destroyed = destroyed;
}

