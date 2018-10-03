#pragma once

class Enemy
{
	public:
		Enemy(unsigned int level);
		~Enemy();

	private:
		unsigned int level;

	public:
		unsigned int getLevel() const;
		void setLevel(unsigned int level);
};

