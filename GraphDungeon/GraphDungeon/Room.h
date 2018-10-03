#pragma once
class Room
{
	public:
		Room();
		~Room();

	private:
		bool isVisited;
		bool shortRoute;	//geeft aan of de kamer onderdeel is van de goedkoopste/kortste route
};

