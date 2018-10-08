#pragma once

class Room;

class Hallway
{
	public:
		Hallway(Room* firstRoom, Room* secondRoom);
		~Hallway();

	private:
		unsigned int enemy;
		bool destroyed;
		Room* rooms[2]; // [0] Room at start - [1] Room at end

	public:
		unsigned int getEnemy() const;
		void destroyEnemy();
		bool isDestroyed() const;
		void destroyHallway();
		Room* getRoom(int index) const;
};

