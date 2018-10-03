#pragma once
#include "Enemy.h"

class Hallway
{
	public:
		Hallway();
		~Hallway();

	private:
		Enemy *enemy;
		bool isDestroyed;
};

