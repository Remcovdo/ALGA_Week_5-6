#pragma once

class Room;

class Hallway
{
	public:
		Hallway();
		~Hallway();

	private:
		unsigned int enemy;
		bool destroyed;
		Room* rooms[2];

	public:
		unsigned int getEnemy() const;
		void destroyEnemy();
		bool isDestroyed() const;
		void setDestroyed(bool destroyed);
};

