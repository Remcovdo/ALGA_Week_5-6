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
	this->visited = true;

	if (!startRoom && !endRoom)
		roomType = '*';
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
	this->endRoom = false;
	this->startRoom = true;
	this->roomType = 'S';
}

bool Room::isEndRoom() const
{
	return this->endRoom;
}

void Room::setEndRoom()
{
	this->startRoom = false;
	this->endRoom = true;
	this->roomType = 'E';
}

char Room::getRoomtype() const
{
	return this->roomType;
}

void Room::setRoomtype(char roomType)
{
	this->roomType = roomType;
}

void Room::setStandardRoom()
{
	this->startRoom = false;
	this->endRoom = false;

	if (!visited)
		this->roomType = 'X';
	else
		this->roomType = '*';
}
