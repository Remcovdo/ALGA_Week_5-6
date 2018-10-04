#include "Room.h"

#include <iostream>

Room::Room() : roomType{ 'X' }, startRoom{ false }, endRoom{ false }, visited{ false }, shortestRoute{ false } 
{
	
}

Room::~Room()
{

}

bool Room::isVisited() const 
{
	return this->visited;
}

void Room::setVisited()
{
	if (!startRoom && !endRoom)
		roomType = '*';

	this->visited = true;
}

bool Room::isShortestRoute() const
{
	return this->shortestRoute;
}

void Room::setShortestRoute(bool shortestRoute)
{
	this->shortestRoute = shortestRoute;
}

bool Room::isStartRoom() const
{
	return this->startRoom;
}

void Room::setStartRoom()
{
	if (endRoom)
		endRoom = false;

	this->roomType = 'S';
	this->startRoom = true;
}

bool Room::isEndRoom() const
{
	return this->endRoom;
}

void Room::setEndRoom()
{
	if (startRoom)
		startRoom = false;

	this->roomType = 'E';
	this->endRoom = endRoom;
}

char Room::getRoomtype() const
{
	return this->roomType;
}

void Room::setRoomtype(char roomType)
{
	this->roomType = roomType;
}
