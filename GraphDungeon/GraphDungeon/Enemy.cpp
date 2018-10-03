#include "Enemy.h"

Enemy::Enemy(unsigned int level) : level {level}
{

}

Enemy::~Enemy()
{

}

unsigned int Enemy::getLevel() const
{
	return this->level;
}

void Enemy::setLevel(unsigned int level)
{
	this->level = level;
}