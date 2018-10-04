#pragma once

#include "Hallway.h"

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
		Hallway* hallways[4];

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
};

