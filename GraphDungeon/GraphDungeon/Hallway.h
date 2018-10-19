#pragma once

class Room;

class Hallway
{
	public:
		Hallway(Room* firstRoom, Room* secondRoom);
		~Hallway();

	private:
		int enemy;
		bool destroyed;
		Room* rooms[2]; // [0] Room at start - [1] Room at end

	public:
		int getEnemy() const;
		void setEnemy(int enemy);
		void destroyEnemy();
		bool isDestroyed() const;
		void destroyHallway();
		Room* getRoom(int index) const;
};

