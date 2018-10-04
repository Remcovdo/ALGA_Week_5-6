#pragma once

#include "Room.h"

class Hallway
{
	public:
		Hallway();
		~Hallway();

	private:
		unsigned int enemy;
		bool destroyed;
		Room* room;

	public:
		unsigned int getEnemy() const;
		void destroyEnemy();
		bool isDestroyed() const;
		void setDestroyed(bool destroyed);
};

