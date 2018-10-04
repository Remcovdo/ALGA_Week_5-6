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
		char roomType;
		Hallway* hallways;

	public:
		bool isVisited() const;
		void setVisited(bool visited);
		bool isShortestRoute() const;
		void setShortestRoute(bool shortestRoute);
		char getRoomtype() const;
		void setRoomtype(char roomType);
		void printRoom();
};

