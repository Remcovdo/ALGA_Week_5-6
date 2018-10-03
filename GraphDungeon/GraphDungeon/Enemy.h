#pragma once
#include "Entity.h"
class Enemy : public Entity
{
	public:
		Enemy(unsigned int level);
		~Enemy();

	private:
		const unsigned int level;

	public:
		unsigned int getLevel() const;
};

