#pragma once

class Room
{
	public:
		Room();
		~Room();

	private:
		bool visited;
		bool shortestRoute;		// Is the chamber part of the shortest route?

	public:
		bool isVisited() const;
		void setVisited(bool visited);
		bool isShortestRoute() const;
		void setShortestRoute(bool shortestRoute);
};

