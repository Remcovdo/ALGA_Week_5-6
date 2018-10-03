#pragma once
#include "Enemy.h"

class Hallway
{
	public:
		Hallway();
		~Hallway();

	private:
		Enemy enemy;
		bool destroyed;

	public:
		Enemy getEnemy() const;
		bool isDestroyed() const;
		void setDestroyed(bool destroyed);
};

