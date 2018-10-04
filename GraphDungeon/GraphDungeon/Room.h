#pragma once

#include <map>

#include "Hallway.h"

class Room
{
	public:
		Room();
		~Room();

	private:
		bool visited;
		bool shortestRoute;
		std::map<Room*, Hallway*> adjecentRooms;
		char roomType;

	public:
		bool isVisited() const;
		void setVisited(bool visited);
		bool isShortestRoute() const;
		void setShortestRoute(bool shortestRoute);
		char getRoomtype() const;
		void setRoomtype(char roomType);
		void printRoom();
};

