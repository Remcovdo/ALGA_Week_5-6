#include "Room.h"

#include <iostream>

Room::Room() : roomType {'X'}
{

}

Room::~Room()
{

}

bool Room::isVisited() const 
{
	return this->visited;
}

void Room::setVisited(bool visited)
{
	this->visited = visited;
}

bool Room::isShortestRoute() const
{
	return this->shortestRoute;
}

void Room::setShortestRoute(bool shortestRoute)
{
	this->shortestRoute = shortestRoute;
}

char Room::getRoomtype() const
{
	return this->roomType;
}

void Room::setRoomtype(char roomType)
{
	this->roomType = roomType;
}

void Room::printRoom()
{
	std::cout << this->roomType;
}
