#pragma once

class Hallway
{
	public:
		Hallway();
		~Hallway();

	private:
		unsigned int enemy;
		bool destroyed;

	public:
		unsigned int getEnemy() const;
		void destroy();
		bool isDestroyed() const;
		void setDestroyed(bool destroyed);
};

