#include "Hallway.h"

Hallway::Hallway() : enemy {10}
{

}

Hallway::~Hallway()
{

}

Enemy Hallway::getEnemy() const
{
	return this->enemy;
}

bool Hallway::isDestroyed() const
{
	return this->destroyed;
}

void Hallway::setDestroyed(bool destroyed)
{
	this->destroyed = destroyed;
}

