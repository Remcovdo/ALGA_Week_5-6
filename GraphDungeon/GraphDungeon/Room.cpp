#include "Room.h"
#include "Hallway.h"

#include <iostream>

Room::Room() : roomType{ 'X' }, startRoom{ false }, endRoom{ false }, visited{ false }, shortestRoute{ false }, hallways { nullptr }
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
		roomType = 'V';
}

bool Room::isShortestRoute() const
{
	return this->shortestRoute;
}

void Room::setShortestRoute()
{
	this->shortestRoute = true;
	
	if (!startRoom && !endRoom)
		roomType = 'G';
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
	this->visited = false;

	this->roomType = 'X';
}

void Room::addHallway(Hallway* hallway, int index)
{
	if (index >= 0 && index <= 3)
		hallways[index] = hallway;
}

Hallway* Room::getHallway(int index) const
{
	if (index >= 0 && index <= 3)
		return this->hallways[index];
	else
		return nullptr;
}
