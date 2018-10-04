#include "Hallway.h"
#include <stdlib.h>
#include <time.h>

Hallway::Hallway() : destroyed {false}
{
	srand(time(NULL));				//generates randomizer seed with the current time
	this->enemy = (rand() % 10);	//generates random number (% 10 causes it to be between 0-9)
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

