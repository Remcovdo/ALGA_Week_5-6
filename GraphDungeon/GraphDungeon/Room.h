#pragma once

class Hallway;

class Room
{
	public:
		Room();
		~Room();

	private:
		bool visited;
		bool shortestRoute;
		bool startRoom;
		bool endRoom;
		char roomType;
		Hallway* hallways[4]; // [0] Room North - [1] Room East - [2] Room South - [3] Room West

	public:
		bool isVisited() const;
		void setVisited();
		bool isShortestRoute() const;
		void setShortestRoute(bool shortestRoute);
		bool isStartRoom() const;
		void setStartRoom();
		bool isEndRoom() const;
		void setEndRoom();
		char getRoomtype() const;
		void setRoomtype(char roomType);
		void setStandardRoom();
		void addHallway(Hallway* hallway, int index);
		Hallway* getHallway(int index) const;
};

