#include "Hallway.h"

Hallway::Hallway() : enemy {10}, destroyed {false}
{

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

