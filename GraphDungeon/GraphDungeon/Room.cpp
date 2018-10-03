#include "Room.h"

Room::Room()
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
